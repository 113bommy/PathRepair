#include <bits/stdc++.h>
using namespace std;
int read() {
  int n = 0;
  bool b = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') b = 1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    n = (n << 1) + (n << 3) + (c ^ 48);
    c = getchar();
  }
  return b ? -n : n;
}
int n;
const int N = 1e6 + 7, mod = 1e9 + 7;
inline int cnt(int x) { return n / x; }
int f[N][20][2];
signed main() {
  n = read();
  int Mx2 = log2(n);
  f[1][Mx2][0] = 1;
  if ((1 << (Mx2 - 1)) * 3 <= n) f[1][Mx2 - 1][1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= Mx2; j++) {
      f[i][j][0] =
          (1ll * f[i - 1][j][0] * (cnt(1 << j) - (i - 1)) +
           1ll * f[i - 1][j + 1][0] * (cnt(1 << j) - cnt(1 << (j + 1))) +
           1ll * f[i - 1][j][1] * (cnt(1 << j) - cnt((1 << j) * 3))) %
          mod;
      f[i][j][1] = (1ll * f[i - 1][j][1] * (cnt((1 << j) * 3) - (i - 1)) +
                    1ll * f[i - 1][j + 1][1] *
                        (cnt((1 << j) * 3) - cnt((1 << (j + 1)) * 3))) %
                   mod;
    }
  printf("%d", f[n][0][0] % mod);
}
