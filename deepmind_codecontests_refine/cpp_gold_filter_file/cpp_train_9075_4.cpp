#include <bits/stdc++.h>
using namespace std;
string ans;
int cnt = -1;
bool happy(string s) {
  for (int i = (0); i < ((int)s.length()); ++i)
    if (s[i] != '4' && s[i] != '7') return 0;
  return 1;
}
int main() {
  string s;
  cin >> s;
  int len = s.length();
  for (int i = (0); i < (len); ++i)
    for (int j = (1); j < (len - i + 1); ++j) {
      string c = s.substr(i, j);
      int cur = 0;
      if (happy(c)) {
        for (int k = (0); k < (len); ++k)
          if (s.substr(k, j) == c) ++cur;
        if (cur == cnt) ans = min(ans, c);
        if (cur > cnt) {
          cnt = cur;
          ans = c;
        }
      }
    }
  cout << (ans.empty() ? "-1" : ans);
  return 0;
}
