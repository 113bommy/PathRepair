#include <bits/stdc++.h>
using namespace std;
int sym(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else if (c >= 'A' && c <= 'Z')
    return (c - 'A') + 10;
  return 0;
}
int binpow(int a, int n) {
  int res = 1;
  while (n)
    if (n & 1) {
      res *= a;
      --n;
    } else {
      a *= a;
      n >>= 1;
    }
  return res;
}
int main() {
  string s;
  int m = 0, i = 0, n = 0;
  cin >> s;
  while (s[0] == '0') s.erase(0, 1);
  for (i = 0; s[i] != ':'; i++)
    ;
  i++;
  while (s[i] == '0') s.erase(i, 1);
  if (s[0] == ':') s = '0' + s;
  if (s[s.length() - 1] == ':') s += '0';
  for (i = 0; i < s.length(); i++) m = max(m, sym(s[i]));
  m++;
  int c, l;
  for (l = 0; s[l] != ':'; l++)
    ;
  for (n = m;; n++) {
    c = 0;
    for (i = 0; i < l; i++) {
      c += sym(s[i]) * binpow(n, l - (i + 1));
      if (c > 23) goto _;
    }
    c = 0;
    i++;
    for (int ii = 0; i < s.length(); i++, ii++) {
      c += sym(s[i]) * binpow(n, (s.length() - (l + 1)) - (ii + 1));
      if (c > 59) goto _;
    }
    if (l <= 1 && (s.length() - (l + 1)) <= 1) {
      cout << -1 << '\n';
      return 0;
    }
    cout << n << '\n';
  }
_:;
  if (n == m) cout << 0 << '\n';
  return 0;
}
