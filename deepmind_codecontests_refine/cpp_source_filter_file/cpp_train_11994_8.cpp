#include <bits/stdc++.h>
using namespace std;
string s;
int A[1000005], i, t, j;
bool ok;
int main() {
  cin >> t;
  for (i = 1; i <= t; i++) {
    cin >> s;
    ok = true;
    for (j = 0; j < s.size(); j++) {
      if (j > 0 && s[j] == s[j - 1]) {
        ok = false;
        break;
      }
      if (s[j] != '?') continue;
      if (j == 0) {
        for (char c = 'a'; c <= 'c'; c++) {
          if (s[j + 1] != c) s[j] = c;
        }
      } else if (j == s.size() - 1) {
        for (char c = 'a'; c <= 'c'; c++) {
          if (s[j + 1] != c) s[j] = c;
        }
      } else {
        for (char c = 'a'; c <= 'c'; c++) {
          if (s[j + 1] != c && s[j - 1] != c) s[j] = c;
        }
      }
      if (s[j] == '?') {
        ok = false;
        break;
      }
    }
    if (!ok)
      cout << -1 << endl;
    else
      cout << s << endl;
  }
  return 0;
}
