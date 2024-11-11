#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, l, n, x = 0, y = 0, p = 0, q = 0;
  string s;
  cin >> n;
  char m[n + 1];
  cin >> s;
  if (s[0] == 'r')
    for (i = 0; i < n;) {
      m[i] = 'r';
      i++;
      if (i >= n) break;
      m[i] = 'b';
      i++;
      if (i >= n) break;
    }
  else
    for (i = 0; i < n;) {
      m[i] = 'b';
      i++;
      if (i >= n) break;
      m[i] = 'r';
      i++;
      if (i >= n) break;
    }
  for (i = 0; i < n; i++) {
    if (m[i] != s[i]) {
      if (m[i] == 'r') x++;
      if (m[i] == 'b') y++;
    }
  }
  if (s[0] == 'r')
    for (i = 0; i < n;) {
      m[i] = 'b';
      i++;
      if (i >= n) break;
      m[i] = 'r';
      i++;
      if (i >= n) break;
    }
  else
    for (i = 0; i < n;) {
      m[i] = 'r';
      i++;
      if (i >= n) break;
      m[i] = 'b';
      i++;
      if (i >= n) break;
    }
  for (i = 0; i < n; i++) {
    if (m[i] != s[i]) {
      if (m[i] == 'r') p++;
      if (m[i] == 'b') q++;
    }
  }
  cout << min(max(x, y), max(p, q));
  return 0;
}
