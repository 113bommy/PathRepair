#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<pair<int, string>> solve(string& s) {
    int n = s.length();
    vector<pair<int, string>> res(n);
    vector<int> stk;
    res[n - 1] = make_pair(1, string(1, s[n - 1]));
    stk.push_back(n - 1);
    auto build = [&]() {
      string res;
      if (stk.size() > 10) {
        for (int i = 0; i < 2; ++i) {
          res += s[stk[i]];
        }
        res += "...";
        for (int i = 4; i >= 0; --i) {
          res += s[stk[stk.size() - 1 - i]];
        }
      } else {
        for (auto x : stk) {
          res += s[x];
        }
      }
      reverse(res.begin(), res.end());
      return res;
    };
    vector<char> nexts(n, 0);
    for (int i = n - 2; i >= 0; --i) {
      if (stk.empty() || stk.back() != i + 1 || s[i + 1] != s[i]) {
        if (stk.empty()) {
          nexts[i] = 0;
        } else if (s[stk.back()] == s[i]) {
          nexts[i] = nexts[stk.back()];
        } else {
          nexts[i] = s[stk.back()];
        }
        stk.push_back(i);
      } else {
        if (stk.size() > 1) {
          if (nexts[stk.back()] < s[i]) {
            stk.pop_back();
          } else {
            nexts[i] = nexts[stk.back()];
            stk.push_back(i);
          }
        } else {
          stk.pop_back();
        }
      }
      res[i] = make_pair(stk.size(), build());
    }
    return res;
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  string s;
  cin >> s;
  auto res = sol.solve(s);
  for (auto& p : res) {
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}
