#include <bits/stdc++.h>
using namespace std;
int T, n, m, p, k, cnt = 0, fa[2][100010], Fa[100010];
struct edge {
  int to, link, w;
};
struct graph {
  int head[100010], o;
  edge e[200010];
  void clear() {
    memset(head, 0, sizeof(head));
    o = 0;
  }
  void add_edge(int u, int v) {
    e[++o].to = v, e[o].link = head[u], head[u] = o;
    e[++o].to = u, e[o].link = head[v], head[v] = o;
  }
} g[2];
struct node {
  int x, y, z, w;
} ans[100010];
void dfs(int k, int u, int pre) {
  fa[k][u] = pre;
  for (int i = g[k].head[u]; i; i = g[k].e[i].link) {
    if (g[k].e[i].to == pre) continue;
    dfs(k, g[k].e[i].to, u);
  }
}
int find(int a) { return Fa[a] == a ? a : Fa[a] = find(Fa[a]); }
void work(int u, int pre) {
  for (int i = g[0].head[u]; i; i = g[0].e[i].link) {
    if (g[0].e[i].to == pre) continue;
    work(g[0].e[i].to, u);
    if (fa[1][g[0].e[i].to] == u || fa[1][u] == g[0].e[i].to) continue;
    ans[++cnt] =
        (node){u, g[0].e[i].to, find(g[0].e[i].to), fa[1][find(g[0].e[i].to)]};
  }
}
int main() {
  scanf("%d", &n);
  g[0].clear(), g[1].clear();
  for (int k = 0; k <= 1; k++) {
    for (int i = 1, u, v; i < n; i++)
      scanf("%d%d", &u, &v), g[k].add_edge(u, v);
    dfs(k, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    if (fa[0][i] == fa[1][i] || fa[0][fa[1][i]] == i)
      Fa[i] = fa[1][i];
    else
      Fa[i] = i;
  }
  work(1, 0);
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++)
    printf("%d %d %d %d\n", ans[i].x, ans[i].y, ans[i].z, ans[i].w);
}
