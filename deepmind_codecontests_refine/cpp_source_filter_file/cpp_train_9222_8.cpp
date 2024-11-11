#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, mod = 1e9 + 7;
int n, a[N], pos[N], mu[N], phi[N], prime[N], v[N], cp, g[N], f[N], h[N], ans,
    fa[N], top[N], son[N], sz[N], dfn[N], dep[N], Time;
int head[N], ce;
struct edge {
  int to, nxt;
} e[N << 1];
void lnk(int a, int b) { e[++ce] = (edge){b, head[a]}, head[a] = ce; }
int z[N << 1], stk[N], Top, cnt, res;
vector<int> G[N];
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return ret;
}
void sieze(int mx) {
  mu[1] = 1, phi[1] = 1;
  for (int i = 2; i <= mx; ++i) {
    if (!v[i]) prime[++cp] = i, mu[i] = mod - 1, phi[i] = i - 1;
    for (int j = 1; j <= cp && i * prime[j] <= mx; ++j) {
      v[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0, phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      mu[i * prime[j]] = mod - mu[i];
      phi[i * prime[j]] = phi[i] * phi[prime[j]];
    }
  }
}
void dfs1(int u, int lst) {
  fa[u] = lst, dep[u] = dep[lst] + 1, sz[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == lst) continue;
    dfs1(v, u), sz[u] += sz[v], son[u] = sz[v] > sz[son[u]] ? v : son[u];
  }
}
void dfs2(int u, int lst) {
  dfn[u] = ++Time, top[u] = (son[lst] == u) ? top[lst] : u;
  if (son[u]) dfs2(son[u], u);
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == lst || v == son[u]) continue;
    dfs2(v, u);
  }
}
int lca(int x, int y) {
  while (top[x] != top[y])
    dep[top[x]] < dep[top[y]] ? y = fa[top[y]] : x = fa[top[x]];
  return dep[x] < dep[y] ? x : y;
}
void dp(int u, int x) {
  if (a[u] % x == 0) h[u] = phi[a[u]];
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    dp(v, x), h[u] = (h[u] + h[v]) % mod;
  }
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    res = (res + mod - 2ll * (h[u] + mod - h[v]) * h[v] % mod * dep[u] % mod) %
          mod;
  }
  if (a[u] % x == 0)
    res = (res + mod - 1ll * phi[a[u]] * phi[a[u]] % mod * dep[u] % mod) % mod;
}
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
int solve(int x) {
  res = 0;
  int sum = 0;
  for (int i = 1; i <= cnt; ++i) sum = (sum + phi[a[z[i]]]) % mod;
  for (int i = 1; i <= cnt; ++i)
    res = (res + 1ll * sum * phi[a[z[i]]] % mod * dep[z[i]]) % mod;
  sort(z + 1, z + 1 + cnt, cmp);
  for (int i = 1; i + 1 <= cnt; ++i) z[i + cnt] = lca(z[i], z[i + 1]);
  z[cnt * 2] = lca(z[1], z[cnt]), cnt <<= 1;
  sort(z + 1, z + 1 + cnt, cmp), cnt = unique(z + 1, z + cnt + 1) - z - 1;
  stk[Top = 0] = 0;
  for (int i = 1; i <= cnt; ++i) {
    while (Top && dfn[stk[Top]] + sz[stk[Top]] - 1 < dfn[z[i]]) --Top;
    if (Top) G[stk[Top]].push_back(z[i]);
    stk[++Top] = z[i];
  }
  dp(z[1], x);
  res = (res << 1) % mod;
  for (int i = 1; i <= cnt; ++i) G[z[i]].clear(), h[z[i]] = 0;
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pos[a[i]] = i;
  for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), lnk(u, v), lnk(v, u);
  sieze(n);
  dfs1(1, 0), dfs2(1, 0);
  for (int i = 1; i <= n; ++i) {
    cnt = 0;
    for (int j = i; j <= n; j += i) z[++cnt] = pos[j];
    g[i] = solve(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i)
      f[i] = (f[i] + 1ll * g[j] * mu[j / i]) % mod;
    ans = (ans + 1ll * f[i] * i % mod * qpow(phi[i], mod - 2)) % mod;
  }
  ans = 1ll * ans * qpow(1ll * n * (n - 1) % mod, mod - 2) % mod;
  printf("%d", ans);
  return 0;
}
