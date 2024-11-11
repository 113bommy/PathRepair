#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int K = 205;
int n, k, S[K][K], fac[K], f[N][K], ans[N], sz[N];
vector<int> G[N];
inline void upd(int &x, const int &y) { (x += y) >= mod ? x -= mod : 0; }
void dfs(int u, int fa = 0) {
  f[u][0] = 2;
  sz[u] = 1;
  for (int e = 0; e <= (int)G[u].size() - 1; ++e) {
    int v = G[u][e];
    if (v == fa) continue;
    dfs(v, u);
    static int t[K];
    for (int i = 0; i <= k; ++i) t[i] = 0;
    for (int x = min(sz[u] - 1, k); x >= 0; --x)
      for (int y = min(sz[v] - 1, k - x); y >= 0; --y) {
        int val = 1ll * f[u][x] * f[v][y] % mod;
        upd(t[x + y], val);
        upd(t[x + y + 1], val);
      }
    for (int i = 0; i <= k; ++i) upd(f[u][i], t[i]);
    for (int i = 0; i <= k; ++i) {
      upd(ans[i], mod - f[v][i]);
      upd(ans[i + 1], mod - f[v][i]);
    }
    sz[u] += sz[v];
  }
  upd(f[u][0], mod - 1);
  for (int i = 1; i <= k; ++i) upd(ans[i], f[u][i]);
}
int main() {
  scanf("%d%d", &n, &k);
  int u, v;
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  S[0][0] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= i; ++j) {
      S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % mod;
    }
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  dfs(1);
  int res = 0;
  for (int i = 1; i <= k; ++i) {
    upd(res, 1ll * fac[i] * S[k][i] % mod * ans[i] % mod);
  }
  printf("%d\n", res);
  return 0;
}
