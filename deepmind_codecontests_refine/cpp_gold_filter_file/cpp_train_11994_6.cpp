#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  int i, n;
  int query;
  cin >> query;
  while (query--) {
    cin >> s;
    n = s.length();
    if (n == 1) {
      cout << "a\n";
      continue;
    }
    if (s[0] == '?') {
      if (s[1] == 'a')
        s[0] = 'b';
      else
        s[0] = 'a';
    }
    bool flag = 0;
    for (i = 1; i < n - 1; i++) {
      if (s[i] == s[i - 1]) {
        cout << -1 << '\n';
        flag = 1;
        break;
      }
      if (s[i] == '?') {
        if (s[i - 1] == 'a' || s[i + 1] == 'a') {
          if (s[i - 1] == 'b' || s[i + 1] == 'b')
            s[i] = 'c';
          else
            s[i] = 'b';
        } else
          s[i] = 'a';
      }
    }
    if (flag) {
      continue;
    }
    if (s[n - 2] == s[n - 1]) {
      cout << -1 << '\n';
      continue;
    }
    if (s[n - 1] == '?') {
      if (s[n - 2] == 'a')
        s[n - 1] = 'b';
      else
        s[n - 1] = 'a';
    }
    cout << s << '\n';
  }
}
