#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/most-common-word/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        unordered_set<string> ban;
        // set for easy comparison
        for (auto &word : banned) ban.insert(word);
        // lowercase the paragraph
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
                  [](unsigned char c) { return tolower(c); });
        // keep track of counts
        unordered_map<string, int> mxcount;
        string mxword = "";
        auto start_word = paragraph.begin();
        while (!isalpha(*start_word)) ++start_word;
        auto it = start_word;
        do {
            while (it != paragraph.end() && isalpha(*it)) ++it;
            string s(start_word, it);
            if (!ban.count(s) && (++mxcount[s] > mxcount[mxword]))
                    mxword = s;
            start_word = it;
            while (start_word != paragraph.end() && !isalpha(*start_word)) ++start_word;
            it = start_word;

        } while (it != paragraph.end());

        return mxword;
    }
};

void test1() {
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned{"hit"};


    cout << "ball ? " << Solution().mostCommonWord(paragraph, banned) << endl;

    paragraph = "Bob";
    banned = {};
    cout << "bob ? " << Solution().mostCommonWord(paragraph, banned) << endl;
}

void test2() {

}

void test3() {

}