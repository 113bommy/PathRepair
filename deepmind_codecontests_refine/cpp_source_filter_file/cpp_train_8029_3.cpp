#include <bits/stdc++.h>
using namespace std;
int n, q, h[100005], tot;
struct edge {
  int to, nxt;
} e[100005 << 1];
void adde(int x, int y) {
  e[++tot].nxt = h[x];
  h[x] = tot;
  e[tot].to = y;
}
int fa[100005], sz[100005], son[100005], dfn[100005], top[100005], d[100005],
    idx;
void dfs(int x, int f) {
  fa[x] = f;
  d[x] = d[f] + 1;
  sz[x] = 1;
  for (int i = h[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      dfs(e[i].to, x), sz[x] += sz[e[i].to];
      if (sz[e[i].to] > sz[son[x]]) son[x] = e[i].to;
    }
}
void dfs2(int x, int tp) {
  dfn[x] = ++idx;
  top[x] = tp;
  if (!son[x]) return;
  dfs2(son[x], tp);
  for (int i = h[x]; i; i = e[i].nxt)
    if (e[i].to != fa[x] && e[i].to != son[x]) dfs2(e[i].to, e[i].to);
}
int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  if (d[x] > d[y]) swap(x, y);
  return x;
}
int dis(int x, int y) {
  int z = lca(x, y);
  return d[x] + d[y] - d[z] * 2;
}
int c[100005];
inline void add(int x, int val) {
  for (; x <= n; x += x & -x) c[x] += val;
}
inline int ask(int x) {
  int sum = 0;
  for (; x; x -= x & -x) sum += c[x];
  return sum;
}
int query(int x, int y) {
  int sum = 0;
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    sum += ask(dfn[x]) - ask(dfn[top[x]] - 1);
    x = fa[top[x]];
  }
  if (d[x] > d[y]) swap(x, y);
  return sum + ask(dfn[y]) - ask(dfn[x - 1]);
}
pair<int, int> u[100005];
int f[100005][305];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adde(x, y);
    adde(y, x);
  }
  dfs(1, 0);
  dfs2(1, 1);
  while (q--) {
    int k, m, r;
    scanf("%d%d%d", &k, &m, &r);
    for (int i = 1; i <= k; i++)
      scanf("%d", &u[i].second), u[i].first = dis(r, u[i].second);
    sort(u + 1, u + k + 1);
    for (int i = 0; i <= k; i++) memset(f[i], 0, sizeof(f[i]));
    f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
      int cur = query(u[i].second, r);
      for (int j = 1; j <= m; j++) {
        f[i][j] = (f[i - 1][j - 1] + 1LL * f[i - 1][j] * max(0, j - cur)) %
                  1000000007;
      }
      add(dfn[u[i].second], 1);
    }
    for (int i = 1; i <= k; i++) add(dfn[u[i].second], -1);
    int ans = 0;
    for (int i = 0; i <= m; i++) ans = (ans + f[k][i]) % 1000000007;
    printf("%d\n", ans);
  }
  return 0;
}
