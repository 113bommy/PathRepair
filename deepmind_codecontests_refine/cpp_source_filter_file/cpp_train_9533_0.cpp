#include <bits/stdc++.h>
using namespace std;
vector<string> ans[1000000 + 2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j;
  string s;
  cin >> s;
  deque<int> Q;
  string ss;
  int fl = 0;
  int num = 0;
  for (i = 0; i < s.length(); i++) {
    if ((s[i] >= 'a' && s[i] < 'z') || (s[i] >= 'A' && s[i] < 'Z')) {
      ss.push_back(s[i]);
      fl = 1;
    }
    if (s[i] >= '0' && s[i] <= '9') {
      num = (num * 10) + (s[i] - '0');
      fl = 2;
    }
    if (s[i] == ',') {
      if (fl == 1) {
        ans[Q.size()].push_back(ss);
        ss.clear();
      }
      if (fl == 2) {
        if (num != 0) {
          Q.push_back(num);
        } else {
          if (Q.size()) {
            int x = Q.back();
            Q.pop_back();
            Q.push_back(x - 1);
          }
          while (Q.size() && Q.back() == 0) {
            Q.pop_back();
            if (Q.size()) {
              int y = Q.back();
              Q.pop_back();
              Q.push_back(y - 1);
            }
          }
        }
        num = 0;
      }
    }
  }
  int sz = 0;
  for (i = 0; i <= 1000000; i++) {
    if (ans[i].size())
      sz++;
    else
      break;
  }
  cout << sz << '\n';
  for (i = 0; i < sz; i++) {
    for (j = 0; j < ans[i].size(); j++) cout << ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
