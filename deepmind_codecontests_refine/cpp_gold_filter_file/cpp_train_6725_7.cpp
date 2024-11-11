#include <bits/stdc++.h>
using namespace std;
const int maxn = 55, p = 1e9 + 7;
int fac[maxn], ifac[maxn];
inline int poww(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * a * ans % p;
    b >>= 1;
    a = 1ll * a * a % p;
  }
  return ans;
}
int C(int n, int m) { return 1ll * fac[n] * ifac[m] % p * ifac[n - m] % p; }
int g[maxn][maxn][maxn], f[maxn][maxn];
void init() {
  int inv2 = p - (p / 2);
  fac[0] = 1;
  for (int i = 1; i <= 50; ++i) fac[i] = 1ll * fac[i - 1] * i % p;
  ifac[50] = poww(fac[50], p - 2);
  for (int i = 49; i >= 0; --i) ifac[i] = 1ll * (i + 1) * ifac[i + 1] % p;
  g[0][0][0] = 1;
  for (int j = 0; j <= 50; ++j) {
    for (int k = 0; k <= 50 - j; ++k) {
      if (j == 0 && k > 0) {
        for (int l = 2; l < k; ++l)
          g[0][j][k] = (g[0][j][k] + 1ll * g[0][j][k - l - 1] * C(k - 1, l) %
                                         p * fac[l] % p * inv2 % p) %
                       p;
      } else {
        if (j >= 2)
          g[0][j][k] = (g[0][j][k] + 1ll * g[0][j - 2][k] * (j - 1) % p) % p;
        if (k >= 1)
          g[0][j][k] = (g[0][j][k] + 1ll * g[0][j][k - 1] * k % p) % p;
      }
    }
  }
  for (int i = 1; i <= 50; i++)
    for (int j = 0; j <= 50 - i; j++)
      for (int k = 0; k <= 50 - i - j; k++) {
        if (j >= 1)
          g[i][j][k] = (g[i][j][k] + 1ll * g[i - 1][j - 1][k] * j % p) % p;
        if (k >= 1)
          g[i][j][k] = (g[i][j][k] + 1ll * g[i - 1][j + 1][k - 1] * k % p) % p;
      }
}
int d[maxn], n;
int main() {
  init();
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> d[i];
  f[d[1] + 1][d[1]] = 1;
  for (int i = d[1] + 2; i <= n; ++i)
    for (int j = 1; j <= i - d[1] - 1; ++j) {
      int c1 = 0, c2 = 0;
      for (int k = 1; k <= i - j; ++k) {
        if (d[i - j - k + 1] == 2)
          ++c1;
        else
          ++c2;
        f[i][j] = (f[i][j] + 1ll * f[i - j][k] * g[j][c1][c2] % p) % p;
      }
    }
  int ans = 0, c1 = 0, c2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[n - i + 1] == 2)
      ++c1;
    else
      ++c2;
    ans = (ans + 1ll * f[n][i] * g[0][c1][c2] % p) % p;
  }
  cout << ans;
}
