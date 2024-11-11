#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
int dp[110000], par[110000][20], adj[110000][2], deg[110000];
pair<int, int> leaf[110000];
int n;
int lo[110000], hi[110000], key[110000];
double ans[110000];
void dfs(int u) {
  int i, v;
  if (deg[u] == 0)
    lo[u] = hi[u] = key[u];
  else
    lo[u] = 0x3f3f3f3f, hi[u] = -0x3f3f3f3f;
  for (i = 0; i < deg[u]; i++) {
    v = adj[u][i];
    dp[v] = dp[u] + 1;
    dfs(v);
    chkmin(lo[u], lo[v]);
    chkmax(hi[u], hi[v]);
  }
}
void dfs1(int u, long long x) {
  if (deg[u] == 0) {
    ans[u] = 1.0 * x / dp[u];
    return;
  }
  int v = adj[u][0], w = adj[u][1];
  dfs1(v, x + lo[w]);
  dfs1(w, x + hi[v]);
}
int lca(int u, int v) {
  int i;
  if (dp[u] > dp[v]) swap(u, v);
  for (i = 19; i >= 0; i--)
    if (dp[v] >= dp[u] + (1 << i)) v = par[v][i];
  if (u == v) return u;
  for (i = 19; i >= 0; i--)
    if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
  return par[u][0];
}
int main() {
  int N, Q, i, u, v, w, r, x;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d%d", &u, &key[i]);
    u--;
    if (u >= 0) adj[u][deg[u]++] = i;
    par[i][0] = u;
    if (par[i][0] < 0) r = par[i][0] = i;
  }
  for (i = n = 0; i < N; i++) {
    if (deg[i] == 0)
      leaf[n++] = pair<int, int>(key[i], i);
    else if (key[adj[i][0]] > key[adj[i][1]])
      swap(adj[i][0], adj[i][1]);
  }
  sort(leaf, leaf + n);
  dp[r] = 0;
  dfs(r);
  dfs1(r, 0);
  for (i = 1; i < 20; i++)
    for (u = 0; u < N; u++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (scanf("%d", &Q); Q--;) {
    scanf("%d", &x);
    v = lower_bound(leaf, leaf + n, pair<int, int>(x, -1)) - leaf;
    u = v - 1;
    if (u < 0)
      u = v;
    else if (v < n) {
      w = lca(leaf[u].second, leaf[v].second);
      if (key[w] < x) u = v;
    }
    printf("%.15lf\n", ans[leaf[u].second]);
  }
  return 0;
}
