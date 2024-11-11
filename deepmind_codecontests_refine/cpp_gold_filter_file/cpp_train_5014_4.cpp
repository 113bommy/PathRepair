#include <bits/stdc++.h>
using namespace std;
const int MM = 320000;
const int LE = 1100000;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  unordered_map<char, deque<int>> um;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) um[s[i]].push_back(i);
  int ta = s.size() / 2;
  int tt = ta / 2;
  int now = 0;
  vector<char> ans;
  while (now < tt) {
    int mx = -1, mc = -1;
    int tmp_st, tmp_end;
    for (int i = 0; i < 3; i++) {
      auto &dq = um[char('a' + i)];
      if (dq.empty()) continue;
      int len = dq.back() - dq.front();
      if (len > mx) mx = len, mc = i, tmp_st = dq.front(), tmp_end = dq.back();
    }
    for (int i = 0; i < 3; i++) {
      auto &dq = um[char('a' + i)];
      while (!dq.empty() && dq.front() <= tmp_st) dq.pop_front();
      while (!dq.empty() && dq.back() >= tmp_end) dq.pop_back();
    }
    ans.push_back(char(mc + 'a'));
    now += 1;
  }
  for (auto c : ans) cout << c;
  if (ta % 2 == 1) {
    for (int i = 0; i < 3; i++) {
      auto &dq = um[char('a' + i)];
      if (!dq.empty()) {
        cout << char('a' + i);
        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto c : ans) cout << c;
  cout << endl;
}
