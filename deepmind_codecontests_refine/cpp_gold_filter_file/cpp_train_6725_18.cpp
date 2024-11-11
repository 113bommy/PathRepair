#include <bits/stdc++.h>
const int N = 53, mo = 1e9 + 7;
int n, deg[N];
long long C[N][N], Neck[N];
long long g[N][N][N], f[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &deg[i]);
  for (int i = C[0][0] = 1; i <= n; ++i)
    for (int j = C[i][0] = 1; j <= i; ++j)
      (C[i][j] = C[i - 1][j] + C[i - 1][j - 1]) >= mo ? C[i][j] -= mo : 0;
  Neck[3] = 1ll;
  for (int i = 4; i <= n; ++i) Neck[i] = Neck[i - 1] * (long long)(i - 1) % mo;
  g[0][0][0] = 1ll;
  for (int k = 3; k <= n; ++k)
    for (int l = 3; l <= k; ++l)
      g[0][0][k] =
          (g[0][0][k] + g[0][0][k - l] * C[k - 1][l - 1] % mo * Neck[l] % mo) %
          mo;
  for (int j = 1; j <= n; ++j)
    for (int k = 0; j + k <= n; ++k) {
      if (j >= 2)
        g[0][j][k] =
            (g[0][j][k] + (long long)(j - 1) * g[0][j - 2][k] % mo) % mo;
      if (k)
        g[0][j][k] = (g[0][j][k] + (long long)k * g[0][j][k - 1] % mo) % mo;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; i + j <= n; ++j)
      for (int k = 0; i + j + k <= n; ++k) {
        if (j)
          g[i][j][k] =
              (g[i][j][k] + (long long)j * g[i - 1][j - 1][k] % mo) % mo;
        if (k)
          g[i][j][k] =
              (g[i][j][k] + (long long)k * g[i - 1][j + 1][k - 1] % mo) % mo;
      }
  f[deg[1] + 1][deg[1]] = 1ll;
  for (int i = deg[1] + 1 + 1; i <= n; ++i)
    for (int j = 1; i - j >= deg[1] + 1; ++j) {
      int _2_ = 0, _3_ = 0;
      for (int k = 1; k < i - j; ++k) {
        deg[i - j - k + 1] == 2 ? ++_2_ : ++_3_;
        f[i][j] = (f[i][j] + f[i - j][k] * g[j][_2_][_3_] % mo) % mo;
      }
    }
  long long ans = 0ll;
  int _2_ = 0, _3_ = 0;
  for (int k = 1; k < n; ++k) {
    deg[n - k + 1] == 2 ? ++_2_ : ++_3_;
    ans = (ans + f[n][k] * g[0][_2_][_3_] % mo) % mo;
  }
  std ::cout << ans;
  return 0;
}
