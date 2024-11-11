#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int maxm = 2010;
int head[maxn], Next[maxm], ver[maxm], edge[maxm], d[maxn];
int n, m, s, t, tot, maxflow;
int head1[maxn], Next1[maxm], ver1[maxm], edge1[maxm], tot1;
bool v1[maxm];
int ans = 0;
int mi, mi_id;
int a[maxn], b[maxn];
queue<int> q;
struct Edge {
  int u, v, w;
};
Edge e[maxm];
void add(int x, int y, int z) {
  ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
  ver[++tot] = x, edge[tot] = z, Next[tot] = head[y], head[y] = tot;
}
void add1(int x, int y, int z) {
  ver1[++tot1] = y, edge1[tot1] = z, Next1[tot1] = head1[x], head1[x] = tot1;
  ver1[++tot1] = x, edge1[tot1] = z, Next1[tot1] = head1[y], head1[y] = tot1;
}
void init() {
  memset(head, 0, sizeof(head));
  tot = 1;
  for (int i = 1; i <= m; i++) add(e[i].u, e[i].v, e[i].w);
}
bool bfs() {
  memset(d, 0, sizeof(d));
  while (q.size()) q.pop();
  q.push(s);
  d[s] = 1;
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = Next[i]) {
      if (edge[i] && !d[ver[i]]) {
        q.push(ver[i]);
        d[ver[i]] = d[x] + 1;
        if (ver[i] == t) return 1;
      }
    }
  }
  return 0;
}
int dfs(int x, int flow) {
  if (x == t) return flow;
  int rest = flow, k;
  for (int i = head[x]; i && rest; i = Next[i]) {
    if (edge[i] && d[ver[i]] == d[x] + 1) {
      k = dfs(ver[i], min(rest, edge[i]));
      if (!k) d[ver[i]] = 0;
      edge[i] -= k;
      edge[i ^ 1] += k;
      rest -= k;
    }
  }
  return flow - rest;
}
void dinic(int x, int y) {
  s = x, t = y;
  init();
  int flow = 0;
  maxflow = 0;
  while (bfs())
    while (flow = dfs(s, 0x3f3f3f3f)) maxflow += flow;
}
void build(int l, int r) {
  if (l == r) return;
  int x = a[l], y = a[l + 1];
  dinic(x, y);
  int L = l - 1, R = r + 1;
  for (int i = l; i <= r; i++) {
    if (d[a[i]] == 0)
      b[--R] = a[i];
    else
      b[++L] = a[i];
  }
  for (int i = l; i <= r; i++) a[i] = b[i];
  add1(x, y, maxflow);
  ans += maxflow;
  build(l, L);
  build(R, r);
}
void dfs1(int x, int fa) {
  for (int i = head1[x]; i; i = Next1[i]) {
    int y = ver1[i], z = edge1[i];
    if (v1[i]) continue;
    if (y == fa) continue;
    if (z < mi) {
      mi = z;
      mi_id = i;
    }
    dfs1(y, x);
  }
}
void print(int x) {
  mi = 0x3f3f3f3f, mi_id = -1;
  dfs1(x, -1);
  int Mi_id = mi_id;
  if (Mi_id == -1) {
    printf("%d ", x);
    return;
  }
  v1[Mi_id] = v1[Mi_id ^ 1] = 1;
  print(ver1[Mi_id]);
  print(ver1[Mi_id ^ 1]);
}
int main() {
  tot1 = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
  }
  for (int i = 1; i <= n; i++) a[i] = i;
  build(1, n);
  printf("%d\n", ans);
  print(1);
}
