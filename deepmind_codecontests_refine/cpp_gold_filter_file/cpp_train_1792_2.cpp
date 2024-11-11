#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  int l = 0;
  int r = n - 1;
  char c = s[0];
  int cntl = 0;
  int cntr = 0;
  while (l <= r) {
    if (s[l] == c) {
      cntl++;
      l++;
    }
    if (r > l && s[r] == c) {
      cntr++;
      r--;
    }
    if (s[l] != c && s[r] != c && s[l] != s[r]) {
      cout << 0 << '\n';
      return 0;
    }
    if (s[l] == s[r] && s[l] != c) {
      if (cntl * cntr == 0 || cntl + cntr < 3) {
        cout << 0 << '\n';
        return 0;
      }
      c = s[l];
      cntl = 0;
      cntr = 0;
    }
  }
  if (cntr + cntl >= 2)
    cout << cntr + cntl + 1 << '\n';
  else
    cout << 0 << '\n';
  return 0;
}
