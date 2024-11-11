#include <bits/stdc++.h>
using namespace std;
const int M = 2e4 + 5, INF = 0x7fffffff;
struct node {
  int to, next, flow;
} edge[M * 100];
struct Tree {
  int to, next;
} nedge[M << 1];
int head[M * 100], cnt = 1, nhead[M], ncnt = 1;
int f[M][16], lg[M], id[M][16], dep[M], tot, id_new[M];
int cur[M * 100], co[M * 100], d[M * 100];
int s, t;
bool vis[M * 100];
inline void add(int x, int y, int f) {
  edge[++cnt] = (node){y, head[x], f}, head[x] = cnt;
  edge[++cnt] = (node){x, head[y], 0}, head[y] = cnt;
}
inline void nadd(int x, int y) {
  nedge[++ncnt] = (Tree){y, nhead[x]}, nhead[x] = ncnt;
}
inline int read() {
  int x = 0;
  char ch = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x;
}
void dfs1(int x, int fa) {
  dep[x] = dep[fa] + 1;
  f[x][0] = fa;
  id[x][0] = ++tot;
  for (register int i = 1; i <= lg[dep[fa]] - 1; i++) {
    f[x][i] = f[f[x][i - 1]][i - 1], id[x][i] = ++tot;
    add(id[x][i], id[x][i - 1], INF);
    add(id[x][i], id[f[x][i - 1]][i - 1], INF);
  }
  for (register int i = nhead[x]; i; i = nedge[i].next) {
    int u = nedge[i].to;
    if (u == fa) continue;
    dfs1(u, x);
    id_new[u] = i / 2;
  }
}
int dfs(int now, int flow) {
  if (now == t) return flow;
  int use = 0;
  for (register int i = cur[now]; i; i = edge[i].next) {
    int u = edge[i].to;
    cur[now] = i;
    if (d[u] + 1 == d[now] && edge[i].flow > 0) {
      int tmp = dfs(u, min(edge[i].flow, flow - use));
      use += tmp;
      edge[i].flow -= tmp;
      edge[i ^ 1].flow += tmp;
      if (flow == use) return use;
    }
  }
  cur[now] = head[now];
  if (!(--co[d[now]])) d[s] = tot + 2;
  ++co[++d[now]];
  return use;
}
void find(int now) {
  vis[now] = true;
  for (register int i = head[now]; i; i = edge[i].next) {
    if (!edge[i].flow) continue;
    int u = edge[i].to;
    if (!vis[u]) find(u);
  }
}
int main() {
  int n = read(), m = read();
  for (register int i = 1; i <= n; i++)
    lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
  for (register int i = 2; i <= n; i++) {
    int x = read(), y = read();
    nadd(x, y);
    nadd(y, x);
  }
  tot = m;
  dfs1(1, 0);
  s = tot + 1;
  s = tot + 2;
  for (register int i = 1; i <= m; i++) add(s, i, 1);
  for (register int i = 1; i <= m; i++) {
    int x = read(), y = read();
    if (dep[x] < dep[y]) swap(x, y);
    while (dep[x] > dep[y])
      add(i, id[x][lg[dep[x] - dep[y]] - 1], INF),
          x = f[x][lg[dep[x] - dep[y]] - 1];
    if (x == y) continue;
    for (register int j = lg[dep[x]] - 1; j >= 0; j--) {
      if (f[x][j] != f[y][j])
        add(i, id[x][j], INF), add(i, id[y][j], INF), x = f[x][j], y = f[y][j];
    }
    add(i, id[x][0], INF);
    add(i, id[y][0], INF);
  }
  for (register int i = 1; i <= n; i++) add(id[i][0], t, 1);
  co[0] = tot + 2;
  int ans = 0;
  while (d[s] < tot + 2) ans += dfs(s, INF);
  printf("%d\n", ans);
  find(s);
  vector<int> ans1, ans2;
  for (register int i = 1; i <= m; i++) {
    if (!vis[i]) ans1.push_back(i);
  }
  for (register int i = 1; i <= n; i++) {
    if (vis[id[i][0]]) ans2.push_back(id_new[i]);
  }
  printf("%d ", ans1.size());
  for (register int i = 0; i < ans1.size(); i++) printf("%d ", ans1[i]);
  putchar('\n');
  printf("%d ", ans2.size());
  for (register int i = ans2.size() - 1; i >= 0; i--) printf("%d ", ans2[i]);
  return 0;
}
