#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, LIM = 17, M = 2 * N;
int edge[M], succ[M], ver[N], idx;
int fa[N][LIM + 3], depth[N], siz[N], dist[N];
int n, m;
void add(int u, int v) {
  edge[idx] = v;
  succ[idx] = ver[u];
  ver[u] = idx++;
}
void bfs() {
  memset(depth, 0x3f, sizeof depth);
  depth[0] = -1;
  depth[1] = 1;
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i = ver[t]; ~i; i = succ[i]) {
      int j = edge[i];
      if (depth[j] > depth[t]) {
        depth[j] = depth[t] + 1;
        dist[j] = dist[t] + 1;
        q.push(j);
        fa[j][0] = t;
        for (int k = 1; k <= LIM; ++k) fa[j][k] = fa[fa[j][k - 1]][k - 1];
      }
    }
  }
}
void dfs(int u, int fa) {
  siz[u] = 1;
  for (int i = ver[u]; ~i; i = succ[i]) {
    int j = edge[i];
    if (j == fa) continue;
    dfs(j, u);
    siz[u] += siz[j];
  }
}
int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  for (int k = LIM; k >= 0; --k)
    if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
  if (a == b) return a;
  for (int k = LIM; k >= 0; --k)
    if (fa[a][k] != fa[b][k]) a = fa[a][k], b = fa[b][k];
  return fa[a][0];
}
int vdist(int a, int b) { return dist[a] + dist[b] - 2 * dist[lca(a, b)]; }
int main() {
  memset(ver, -1, sizeof ver);
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v), add(v, u);
  }
  bfs();
  dfs(1, -1);
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u == v)
      printf("%d\n", siz[1]);
    else if (depth[u] == depth[v]) {
      for (int k = LIM; k >= 0; --k)
        if (fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
      printf("%d\n", siz[1] - siz[u] - siz[v]);
    } else {
      if (depth[u] < depth[v]) swap(u, v);
      if ((depth[u] - depth[v]) & 1) {
        printf("0\n");
        continue;
      }
      int anc = lca(u, v);
      int tard = depth[anc] + (depth[u] - depth[v]) / 2;
      for (int k = LIM; k >= 0; --k)
        if (depth[fa[u][k]] > tard) u = fa[u][k];
      printf("%d\n", siz[fa[u][0]] - siz[u]);
    }
  }
  return 0;
}
