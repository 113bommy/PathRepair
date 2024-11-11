#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, M = 64, mod = 998244353;
inline void check(int& x) { x -= mod, x += x >> 31 & mod; }
int n, k, m, tot;
long long int a[N], f[M], g[M], t[M];
int ans[M], tmp[M], pw[N], c[M][M], w[M][M];
inline void ins(long long int x) {
  for (int i = m; i >= 0; i--)
    if (x >> i & 1) {
      if (f[i])
        x ^= f[i];
      else
        return f[i] = x, k++, void();
    }
}
inline void dfs(int p, long long int x) {
  if (p == tot)
    tmp[__builtin_popcountll(x)]++;
  else
    dfs(p + 1, x), dfs(p + 1, x ^ t[p]);
}
int main() {
  cin.tie(0), cin >> n >> m, pw[0] = 1, m--;
  for (int i = 1; i <= n; i++)
    cin >> a[i], ins(a[i]), check(pw[i] = pw[i - 1] << 1);
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= i - 1; j++)
      if (f[i] >> j & 1) f[i] ^= f[j];
  if (k <= 26) {
    for (int i = 0; i <= m; i++)
      if (f[i]) t[tot++] = f[i];
    dfs(0, 0);
    for (int i = 0; i <= m + 1; i++)
      cout << 1ll * pw[n - k] * tmp[i] % mod << ' ';
  } else {
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++) g[j] |= (f[i] >> j & 1) << i;
    for (int i = 0; i <= m; i++)
      if (g[i] ^= 1ll << i) t[tot++] = g[i];
    k = ++m - k, dfs(0, 0);
    for (int i = 0; i <= m; i++) c[i][0] = 1;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++)
        check(c[i][j] = c[i - 1][j] + c[i - 1][j - 1]);
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++)
        for (int p = 0; p <= i; p++)
          if (p & 1)
            check(w[i][j] += mod - 1ll * c[j][p] * c[m - j][i - p] % mod);
          else
            check(w[i][j] += 1ll * c[j][p] * c[m - j][i - p] % mod);
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++)
        check(ans[i] += 1ll * tmp[j] * w[i][j] % mod);
    int tag = pw[max(0, n - m + k)];
    for (int i = 1; i <= k; i++) tag = 1ll * (mod + 1 >> 1) * tag % mod;
    for (int i = 0; i <= m; i++) cout << 1ll * ans[i] * tag % mod << ' ';
  }
  return 0;
}
