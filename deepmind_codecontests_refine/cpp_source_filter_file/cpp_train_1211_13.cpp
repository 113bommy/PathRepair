#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
int n, siz[2010];
ll g[2010][2], f[2010][2010][2], ans[2010], tot, C[2010][2010];
basic_string<int> v[2010];
ll po(ll a, ll b = mod - 2) {
  ll r = 1;
  for (; b; b /= 2, a = a * a % mod)
    if (b & 1) r = r * a % mod;
  return r;
}
void dfs(int p, int fa = -1) {
  f[p][0][1] = f[p][0][0] = 1;
  siz[p] = 1;
  for (int i : v[p])
    if (i != fa) {
      dfs(i, p);
      memset(g, 0, sizeof g);
      for (int j = 0; j < siz[p] + siz[i]; j++)
        for (int x = 0; x < siz[i] && x <= j; x++) {
          (g[j][1] += f[i][x][1] * f[p][j - x][1]) %= mod;
          (g[j][0] += f[i][x][1] * f[p][j - x][0]) %= mod;
          if (x < j)
            (g[j][1] += f[i][x][0] * f[p][j - 1 - x][1]) %= mod,
                (g[j][1] += f[i][x][1] * f[p][j - 1 - x][0]) %= mod,
                (g[j][0] += f[i][x][0] * f[p][j - 1 - x][0]) %= mod;
        }
      memcpy(f[p], g, sizeof g);
      siz[p] += siz[i];
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (int i = 1, x, y; i < n; i++) scanf("%d%d", &x, &y), v[x] += y, v[y] += x;
  dfs(1);
  for (int i = 0; i < n; i++) ans[i] = f[1][i][1];
  for (int i = 0; i < n; i++) (ans[i] *= po(n, n - i - 2 + mod - 1)) %= mod;
  for (int i = n - 2; ~i; i--)
    for (int j = i + 1; j < n; j++) (ans[i] -= ans[j] * C[j][i]) %= mod;
  for (int i = 0; i < n; i++)
    printf("%lld%c", (ans[i] + mod) % mod, " \n"[i == n - 1]);
  return 0;
}
