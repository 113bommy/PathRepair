#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    bool p = true;
    cin >> s;
    int sz = s.size();
    if (sz == 1 && s[0] == '?') {
      cout << 'a' << endl;
      break;
    }
    for (int i = 1; i < sz; i++) {
      if (s[i] == '?') {
        continue;
      }
      if (s[i] == s[i - 1]) {
        p = false;
        cout << -1 << endl;
        break;
      }
    }
    if (p == false) continue;
    for (int i = 0; i < sz; i++) {
      if (i == 0 && s[i] == '?' && s[i + 1] == '?') {
        s[i] = 'a';
        continue;
      } else if (i == 0 && s[i] == '?' && s[i + 1] != '?') {
        if (s[i + 1] - 'a' == 0) {
          s[i] = 'b';
          continue;
        } else {
          s[i] = s[i + 1] - 1;
          continue;
        }
      }
      if (i == sz - 1 && s[i] == '?') {
        if (s[i - 1] - 'a' == 0) {
          s[i] = 'b';
          continue;
        } else {
          s[i] = s[i - 1] - 1;
          continue;
        }
      }
      if (s[i] == '?' && s[i + 1] != '?') {
        s[i] = 'a';
        while (s[i] == s[i + 1] || s[i] == s[i - 1]) {
          s[i]++;
        }
      }
      if (s[i] == '?' && s[i + 1] == '?') {
        if (s[i - 1] - 'a' == 0) {
          s[i] = s[i - 1] + 1;
        } else {
          s[i] = 'a';
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
