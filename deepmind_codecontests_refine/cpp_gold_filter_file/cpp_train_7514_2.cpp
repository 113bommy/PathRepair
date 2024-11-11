#include <bits/stdc++.h>
using namespace std;
const int N = 3610;
const int mod = 998244353;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int C[N][N], n, m, k, f[N][N], g[N][N], fac[N];
bool vr[N], vc[N], br[N], bc[N];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    vr[gi()] = 1;
    vc[gi()] = 1;
    vr[gi()] = 1;
    vc[gi()] = 1;
  }
  int len = 0;
  for (int i = 1; i <= m; i++) {
    if (vc[i])
      bc[len] = 1;
    else
      ++len;
  }
  m = len;
  len = 0;
  for (int i = 1; i <= n; i++) {
    if (vr[i])
      br[len] = 1;
    else
      ++len;
  }
  n = len;
  fac[0] = 1;
  for (int i = 0; i < N; i++) {
    C[i][0] = 1;
    if (i) fac[i] = 1ll * fac[i - 1] * i % mod;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  f[0][0] = g[0][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 0; j <= i / 2; j++) {
      f[i][j] = f[i - 1][j];
      g[i][j] = g[i - 1][j];
      if (i >= 2 && j >= 1) {
        if (!bc[i - 1]) f[i][j] = (f[i][j] + f[i - 2][j - 1]) % mod;
        if (!br[i - 1]) g[i][j] = (g[i][j] + g[i - 2][j - 1]) % mod;
      }
    }
  int ans = 0;
  for (int i = 0; i <= m / 2; i++)
    for (int j = 0; j <= n / 2; j++) {
      ans = (ans + 1ll * f[m][i] * g[n][j] % mod * C[n - 2 * j][i] % mod *
                       C[m - 2 * i][j] % mod * fac[i] % mod * fac[j]) %
            mod;
    }
  cout << ans;
  return 0;
}
