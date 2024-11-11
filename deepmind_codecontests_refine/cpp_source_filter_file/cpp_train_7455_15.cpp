#include <bits/stdc++.h>
using namespace std;
struct node {
  int u, v, x;
} tmp;
inline node mk(int u, int v, int x) {
  tmp.u = u;
  tmp.v = v;
  tmp.x = x;
  return tmp;
}
int n, m, i, x, j, u, v, fa[200005][18], dfn, dp[200005], c[200005],
    dep[200005], in[200005], out[200005];
vector<int> son[200005];
vector<node> ed[200005];
int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  int i;
  for (i = 17; ~i; --i)
    if (dep[fa[y][i]] >= dep[x]) y = fa[y][i];
  if (x == y) return x;
  for (i = 17; ~i; --i)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
inline void add(int x, int y) {
  while (x < 200005) c[x] += y, x += (x & -x);
}
inline int sum(int x) {
  int ret = 0;
  while (x) ret += c[x], x -= (x & -x);
  return ret;
}
void dfs(int now) {
  int i, T, gg;
  in[now] = ++dfn;
  for (i = 0; i < son[now].size(); ++i) dfs(T = son[now][i]), dp[now] += dp[T];
  for (gg = dp[now], i = 0; i < ed[now].size(); ++i)
    tmp = ed[now][i],
    gg = max(gg, sum(in[tmp.u]) + sum(in[tmp.v]) + dp[now] + tmp.x);
  add(in[now], dp[now] - gg), add(dfn + 1, gg - dp[now]);
  dp[now] = gg;
}
int main() {
  for (cin >> n >> m, i = 2; i <= n; ++i)
    cin >> x, fa[i][0] = x, son[x].push_back(i), dep[i] = dep[x] + 1;
  for (i = 1; i <= 17; ++i)
    for (j = 1; j <= n; ++j) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  for (i = 1; i <= m; ++i)
    cin >> u >> v >> x, ed[lca(u, v)].push_back(mk(u, v, x));
  dfs(1);
  cout << dp[1];
}
