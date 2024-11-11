#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, q, dfn[N], low[N], dfs_clock, sta1[N * 2], top1, scc_num,
    scc_id[N * 2], edgenum;
int fa[N][21], vet[N * 2], head[N], Next[N * 2], dep[N], beg[N * 2],
    sta2[N * 4], top2, w[N][21];
bool flag[N * 2], vis[N];
bool used[N];
void addedge(int u, int v) {
  vet[++edgenum] = v;
  beg[edgenum] = u;
  Next[edgenum] = head[u];
  head[u] = edgenum;
}
void Tarjan(int u, int father) {
  dfn[u] = low[u] = ++dfs_clock;
  for (int e = head[u]; e; e = Next[e]) {
    int v = vet[e];
    int x = e;
    if (!scc_id[(e + 1) / 2]) sta1[++top1] = e;
    if (v == father) continue;
    if (!dfn[v]) {
      Tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        top2 = 0;
        int x;
        x = sta1[top1];
        scc_num++;
        bool flag1 = 0;
        do {
          x = sta1[top1--];
          scc_id[(x + 1) / 2] = scc_num;
          sta2[++top2] = x;
          int d1 = dep[beg[x]] % 2, d2 = dep[vet[x]] % 2;
          if (d1 == d2) flag1 = 1;
        } while (beg[x] != u);
        if (flag1) {
          while (top2) {
            x = sta2[top2];
            flag[sta2[top2]] = 1;
            if (sta2[top2] % 2 == 0)
              flag[sta2[top2--] - 1] = 1;
            else
              flag[sta2[top2--] + 1] = 1;
          }
        }
      }
    } else
      low[u] = min(low[u], dfn[v]);
  }
}
void dfs(int u, int father) {
  vis[u] = 1;
  dep[u] = dep[father] + 1;
  fa[u][0] = father;
  for (int i = 1; i < 21; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int e = head[u]; e; e = Next[e]) {
    int v = vet[e];
    if (!vis[v]) dfs(v, u);
  }
}
int LCA(int u, int v, int &l) {
  if (dep[u] < dep[v]) swap(u, v);
  int delta = dep[u] - dep[v], ret = 0;
  for (int i = 0; i < 21; i++)
    if (delta & (1 << i)) ret += w[u][i], u = fa[u][i];
  if (u == v) {
    l = u;
    return ret;
  }
  for (int i = 20; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) {
      ret += w[u][i] + w[v][i];
      u = fa[u][i];
      v = fa[v][i];
    }
  l = fa[u][0];
  return ret + w[u][0] + w[v][0];
}
void dfs1(int u, int father) {
  vis[u] = 1;
  for (int i = 1; i < 21; i++) w[u][i] = w[u][i - 1] + w[fa[u][i - 1]][i - 1];
  for (int e = head[u]; e; e = Next[e]) {
    int v = vet[e];
    if (!vis[v]) {
      if (flag[e]) w[v][0] = 1;
      dfs1(v, u);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, 0);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan(i, 0);
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs1(i, 0);
  scanf("%d", &q);
  while (q--) {
    int u, v, l;
    scanf("%d%d", &u, &v);
    int dist = LCA(u, v, l);
    if (l == 0 || u == v) {
      puts("No");
      continue;
    }
    int dis = dep[u] + dep[v] - 2 * dep[l];
    if (dis & 1)
      puts("Yes");
    else {
      if (dist)
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}
