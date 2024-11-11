#include <bits/stdc++.h>
using namespace std;
const int N = 55, mod = 1e9 + 7, i2 = (mod + 1) / 2;
int n, d[N];
int C[N][N], fac[N];
int f[N][N], g[N][N][N];
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void init() {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  g[0][0][0] = 1;
  init();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        if (!i && !j && !k) continue;
        if (!i) {
          if (!j) {
            for (int l = 3; l <= k; l++) {
              add(g[i][j][k], 1ll * g[i][j][k - l] * C[k - 1][l - 1] % mod *
                                  fac[l - 1] % mod * i2 % mod);
            }
          } else {
            if (j >= 2) add(g[i][j][k], 1ll * g[i][j - 2][k] * (j - 1) % mod);
            if (k) add(g[i][j][k], 1ll * g[i][j][k - 1] * k % mod);
          }
        } else {
          if (j) add(g[i][j][k], 1ll * g[i - 1][j - 1][k] * j % mod);
          if (k) add(g[i][j][k], 1ll * g[i - 1][j + 1][k - 1] * k % mod);
        }
      }
  f[d[1] + 1][d[1]] = 1;
  for (int i = d[1] + 2; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      int x = 0, y = 0;
      for (int k = 1; k <= i - j; k++) {
        if (d[i - j - k + 1] == 2)
          x++;
        else
          y++;
        add(f[i][j], 1ll * f[i - j][k] * g[j][x][y] % mod);
      }
    }
  int ans = 0, x = 0, y = 0;
  for (int j = 1; j <= n; j++) {
    if (d[n - j + 1] == 2)
      x++;
    else
      y++;
    add(ans, 1ll * f[n][j] * g[0][x][y] % mod);
  }
  printf("%d", ans);
  return 0;
}
