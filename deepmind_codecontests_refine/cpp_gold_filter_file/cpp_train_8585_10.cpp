#include <bits/stdc++.h>
const int N = 200005;
int n, m, u[N], v[N];
bool vis[N];
struct Edge {
  int to, nxt, id;
} E[N << 1];
int head[N], tot;
inline void add(int f, int t, int id) {
  E[++tot] = (Edge){t, head[f], id}, head[f] = tot;
  return;
}
std::vector<int> G[N];
int lg[N], fa[N][20], dep[N];
void dfs(int x, int from, int id) {
  vis[id] = 1, dep[x] = dep[fa[x][0] = from] + 1;
  for (int i = 1; i < lg[dep[x]]; ++i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = head[x]; i; i = E[i].nxt) {
    int y = E[i].to, dd = E[i].id;
    if (!fa[y][0]) dfs(y, x, dd);
  }
  return;
}
inline int lca(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  while (dep[x] != dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
  if (x == y) return x;
  for (int i = lg[dep[x]] - 1; i >= 0; --i)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int col[N];
inline bool cmp(int x, int y) { return dep[x] > dep[y]; }
inline void inter(int a, int b, int c, int d, int& l, int& r) {
  int p[4] = {lca(a, c), lca(a, d), lca(b, c), lca(b, d)};
  std::sort(p, p + 4, cmp);
  l = p[0], r = p[1];
  return;
}
int cnt, len[3], ans[3][N];
int st[N], top;
void dfs2(int x, int from, int t) {
  st[++top] = x;
  if (x == t)
    return len[cnt] = top, memcpy(ans[cnt], st, sizeof(int[top + 5])), ++cnt,
           --top, void(0);
  for (int i = 0; i < (signed)G[x].size(); ++i) {
    int y = G[x][i];
    if (y != from) dfs2(y, x, t);
  }
  --top;
  return;
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n + 1; ++i) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= m; ++i)
    scanf("%d%d", u + i, v + i), add(u[i], v[i], i), add(v[i], u[i], i);
  dep[n + 1] = 1;
  for (int i = 1; i <= n; ++i)
    if (!fa[i][0]) dfs(i, n + 1, 0);
  for (int i = 1; i <= m; ++i)
    if (!vis[i]) {
      int f = lca(u[i], v[i]), p = 0;
      for (int j = u[i]; j != f; j = fa[j][0])
        if (col[j]) {
          p = col[j];
          break;
        } else
          col[j] = i;
      for (int j = v[i]; j != f; j = fa[j][0])
        if (col[j]) {
          p = col[j];
          break;
        } else
          col[j] = i;
      if (p) {
        printf("YES\n");
        int l, r;
        inter(u[i], v[i], u[p], v[p], l, r);
        for (int j = 1; j <= m; ++j)
          if (vis[j]) G[u[j]].push_back(v[j]), G[v[j]].push_back(u[j]);
        G[u[i]].push_back(v[i]), G[v[i]].push_back(u[i]);
        G[u[p]].push_back(v[p]), G[v[p]].push_back(u[p]);
        for (int j = 0; j < (signed)G[l].size(); ++j) {
          int y = G[l][j];
          dfs2(y, l, r);
        }
        for (int k = 0; k < 3; ++k) {
          printf("%d %d ", len[k] + 1, l);
          for (int j = 1; j <= len[k]; ++j) printf("%d ", ans[k][j]);
          putchar('\n');
        }
        return 0;
      }
    }
  printf("NO\n");
  return 0;
}
