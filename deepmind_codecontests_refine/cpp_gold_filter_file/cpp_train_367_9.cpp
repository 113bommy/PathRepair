#include <bits/stdc++.h>
using namespace std;
const int nmax = 1000;
const int gmax = 10;
int mod;
int t[nmax + 1];
int inv[gmax + 1];
int d[nmax + 1][gmax + 1][nmax + 1];
inline int C(int x, int y) {
  int ans = 1;
  for (int i = x - y + 1; i <= x; ++i) ans = 1LL * ans * i % mod;
  return 1LL * ans * inv[y] % mod;
}
int lgput(int b, int p) {
  int ans = 1;
  while (p > 0) {
    if (p & 1) ans = 1LL * ans * b % mod;
    b = 1LL * b * b % mod;
    p >>= 1;
  }
  return ans;
}
int main() {
  int n, g;
  fscanf(stdin, "%d%d%d", &n, &g, &mod);
  if (n == 1 || n == 2) {
    fprintf(stdout, "1\n");
    return 0;
  }
  int fct = 1;
  inv[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fct = 1LL * fct * i % mod;
    inv[i] = lgput(fct, mod - 2);
  }
  t[1] = 1;
  for (int i = 0; i <= n; ++i) d[0][0][i] = d[1][g - 1][i] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= g; ++j) {
      for (int mx = 1; mx <= n; ++mx) {
        d[i][j][mx] = (d[i][j][mx] + d[i][j][mx - 1]) % mod;
        if (j * mx + 1 == i) {
          d[i][j][mx] = (d[i][j][mx] + C(t[mx] + j - 1, j)) % mod;
        }
        for (int x = 1; x < j && x * mx <= i; ++x) {
          d[i][j][mx] = (d[i][j][mx] + 1LL * d[i - x * mx][j - x][mx - 1] *
                                           C(t[mx] + x - 1, x)) %
                        mod;
        }
      }
    }
    t[i] = d[i][g - 1][n];
  }
  int ans = 0;
  if (n % 2 == 0) {
    ans += 1LL * (t[n / 2] + 1) * t[n / 2] % mod * inv[2] % mod;
  }
  ans = (ans + d[n][g][(n - 1) / 2]) % mod;
  fprintf(stdout, "%d\n", ans);
  return 0;
}
