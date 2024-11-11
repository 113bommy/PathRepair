#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(const T& a) {
  return a > 0 ? a : -a;
}
int n;
int m;
int vx[500000], vy[500000];
char s[1000000];
int main() {
  cin >> n >> m;
  gets(s);
  for (int i = 0; i < (n); i++) {
    gets(s);
    for (int j = 0; j < (m); j++)
      if (s[j] != '.') {
        int cy = 1;
        if (s[j] > '2') cy = 2;
        if (j % 2) cy = 3 - cy;
        vx[i] |= cy;
        int cx = 1;
        if (s[j] == '2' || s[j] == '3') cx = 2;
        if (i % 2) cx = 3 - cx;
        vy[j] |= cx;
      }
  }
  int ans = 1;
  int mod = 1000000 + 3;
  for (int i = 0; i < (n); i++) {
    if (vx[i] == 0) ans = ans * 2 % mod;
    if (vx[i] == 3) ans = 0;
  }
  for (int i = 0; i < (m); i++) {
    if (vy[i] == 0) ans = ans * 2 % mod;
    if (vy[i] == 3) ans = 0;
  }
  cout << ans << endl;
  return 0;
}
