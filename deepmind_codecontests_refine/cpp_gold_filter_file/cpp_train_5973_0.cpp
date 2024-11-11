#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, last = 0, need = 0, first = 0, second = 0, ok;
  cin >> t;
  string s, ans[105];
  for (; t--; t > 0) {
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == ':') need++;
      if (s[i] == ':' && s[i + 1] == ':') {
        first = i;
        second = i + 1;
      }
      if (need == 8) break;
    }
    if (first != second) {
      if (first != 0 && second != s.size() - 1)
        need = 8 - need;
      else if (first != 0 || second != s.size() - 1) {
        need = 9 - need;
      } else
        need = 10 - need;
    } else
      need = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ':' && s[i + 1] == ':') {
        for (int j = 1; j <= need; j++) {
          if (j == need && second == s.size() - 1)
            cout << "0000";
          else
            cout << "0000:";
        }
      } else if (i == 0) {
        int j;
        for (j = 0; j <= 4; j++) {
          if (s[j] == ':') break;
        }
        for (int l = 0; l < 4 - j; l++) cout << '0';
        for (j = 0; j <= 4; j++) {
          if (s[j] == ':') break;
          cout << s[j];
        }
        cout << ':';
      } else if (s[i] == ':' && i != s.size() - 1) {
        int j = i + 1;
        int ok;
        for (int j = i + 1; j < s.size(); j++) {
          if (s[j] == ':') {
            break;
          }
          ok = j;
        }
        for (int l = 0; l < 4 - (ok - i); l++) cout << '0';
        for (int j = i + 1; j < s.size(); j++) {
          if (s[j] == ':') {
            break;
          } else
            cout << s[j];
          ok = j;
        }
        if (ok != s.size() - 1) cout << ':';
      }
    }
    if (t != 0) cout << endl;
    need = 0;
  }
  return 0;
}
