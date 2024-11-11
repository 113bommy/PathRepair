#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == '?') {
      if (s[1] == 'a')
        s[0] = 'b';
      else
        s[0] = 'a';
    }
    for (int i = 1; i <= n; i++) {
      if (s[i] == '?') {
        if (s[i + 1] == s[i - 1]) {
          if (s[i + 1] == 'a')
            s[i] = 'b';
          else
            s[i] = 'a';
        } else {
          if (s[i + 1] - s[i - 1] == 2 or s[i + 1] - s[i - 1] == -2)
            s[i] = 'b';
          else {
            if (s[i + 1] == 'c' or s[i - 1] == 'c')
              s[i] = 'a';
            else
              s[i] = 'c';
          }
        }
      }
    }
    if (s[n - 1] == '?') {
      if (s[n - 2] == 'a')
        s[n - 1] = 'b';
      else
        s[n - 1] = 'a';
    }
    int i = 0;
    for (i = 1; i < n - 1; i++) {
      if (s[i] == s[i - 1] or s[i] == s[i + 1]) break;
    }
    if (i < n - 1)
      cout << "-1\n";
    else
      cout << s << endl;
  }
}
