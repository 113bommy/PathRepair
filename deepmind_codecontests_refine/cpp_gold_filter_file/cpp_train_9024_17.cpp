#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n1, n2, k, vis[4444];
vector<int> G[4444];
long long ans[222], cpy[222];
int sz[4444];
void SZ(int x, int fa) {
  sz[x] = 1;
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (vis[to] || to == fa) continue;
    SZ(to, x), sz[x] += sz[to];
  }
}
int tot, M, rt;
void RT(int x, int fa) {
  int MS = 0;
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (vis[to] || to == fa) continue;
    RT(to, x), MS = max(MS, sz[to]);
  }
  MS = max(MS, tot - sz[x]);
  if (MS < M) M = MS, rt = x;
}
long long f[4444][222], g[4444][222];
void init(int x, int fa) {
  memset(f[x], 0, sizeof(f[x]));
  memset(g[x], 0, sizeof(g[x]));
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (vis[to] || to == fa) continue;
    init(to, x);
  }
}
void update(int x, int fa, int d) {
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (vis[to] || to == fa) continue;
    if (x != rt) f[to][d] = (f[to][d] + f[x][d - 1]) % mod;
    if (to != rt) f[x][d] = (f[x][d] + f[to][d - 1]) % mod;
    g[to][d] = (g[to][d] + g[x][d - 1]) % mod;
    g[x][d] = (g[x][d] + g[to][d - 1]) % mod;
    update(to, x, d);
  }
}
void GET(int x, int fa) {
  if (x == rt)
    for (int a = 0; a <= k; ++a) ans[a] = (ans[a] + g[x][a]) % mod;
  else
    for (int a = 0; a <= k; ++a)
      for (int b = 0; b <= k; ++b)
        ans[a + b] = (ans[a + b] + f[x][a] * g[x][b]) % mod;
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (vis[to] || to == fa) continue;
    GET(to, x);
  }
}
void solve(int x) {
  SZ(x, 0);
  tot = M = sz[x], RT(x, 0);
  x = rt;
  init(x, 0);
  g[x][0] = 1;
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (vis[to]) continue;
    f[to][1] = g[to][1] = 1;
  }
  for (int o = 2; o <= k; ++o) update(x, 0, o);
  GET(x, 0);
  vis[x] = 1;
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (vis[to]) continue;
    solve(to);
  }
}
long long C[222][222];
int main() {
  for (int i = 0; i < 222; ++i) C[i][0] = C[i][i] = 1;
  for (int i = 2; i < 222; ++i)
    for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  scanf("%d %d %d", &n1, &n2, &k);
  for (int i = 1; i < n1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  solve(1);
  memcpy(cpy, ans, sizeof(cpy));
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n2; ++i) G[i].clear(), vis[i] = 0;
  for (int i = 1; i < n2; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  solve(1);
  long long ret = 0;
  for (int i = 0; i <= k; ++i)
    ret = (ret + C[k][i] * ans[i] % mod * cpy[k - i]) % mod;
  printf("%I64d\n", ret);
  return 0;
}
