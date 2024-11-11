#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3, M = 3e5 + 4;
const long long INF = 1e18;
struct List {
  int dir, nxt;
  long long lng;
} E[M << 1], D[M], T[M];
int G[N], cnt;
inline void Add(int u, int v, long long w) {
  E[++cnt].dir = v, E[cnt].nxt = G[u], G[u] = cnt, E[cnt].lng = w;
}
int H[N], cnd;
inline void AddD(int u, int v) {
  D[++cnd].dir = v, D[cnd].nxt = H[u], H[u] = cnd;
}
int Gt[N], cnT;
inline void AddT(int u, int v) {
  T[++cnT].dir = v, T[cnT].nxt = Gt[u], Gt[u] = cnT;
}
int n, m, s;
long long dis[N];
void dijkstra() {
  for (register int i = (1); i <= (n); ++i) dis[i] = INF;
  static priority_queue<pair<long long, int> > q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    int u = q.top().second;
    if (dis[u] != INF) {
      q.pop();
      continue;
    }
    dis[u] = -q.top().first, q.pop();
    for (register int i = G[u]; i; i = E[i].nxt) {
      int v = E[i].dir;
      if (dis[v] == INF) q.push(make_pair(-dis[u] - E[i].lng, v));
    }
  }
}
int fa[18][N], dep[N];
inline int Lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int lft = dep[u] - dep[v];
  for (register int i = 0; lft; lft >>= 1, ++i)
    if (lft & 1) u = fa[i][u];
  if (u == v) return u;
  for (register int i = (17); i >= (0); --i)
    if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
  return fa[0][u];
}
int sz[N];
void dfs(int u) {
  sz[u] = 1;
  for (register int i = Gt[u]; i; i = T[i].nxt) {
    int v = T[i].dir;
    dfs(v), sz[u] += sz[v];
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (register int i = (1); i <= (m); ++i) {
    static int u, v;
    static long long w;
    scanf("%d%d%lld", &u, &v, &w);
    Add(u, v, w), Add(v, u, w);
  }
  dijkstra();
  static int ind[N], ord[N], rk;
  for (register int i = 1; i <= cnt; i += 2) {
    int u = E[i].dir, v = E[i + 1].dir;
    if (dis[u] + E[i].lng == dis[v]) AddD(u, v), ind[v]++;
    if (dis[v] + E[i].lng == dis[u]) AddD(v, u), ind[u]++;
  }
  static int q[N], h, t;
  static basic_string<int> Lst[N];
  h = 1, t = 0;
  q[++t] = s;
  while (h <= t) {
    int u = q[h++];
    ord[++rk] = u;
    for (register int i = H[u]; i; i = D[i].nxt) {
      int v = D[i].dir;
      Lst[v] += u;
      if (!--ind[v]) q[++t] = v;
    }
  }
  for (register int i = (2); i <= (rk); ++i) {
    int u = ord[i], p = Lst[u][0];
    for (register int j = 1; j < (int)Lst[u].size(); ++j) p = Lca(p, Lst[u][j]);
    dep[u] = dep[p] + 1, fa[0][u] = p;
    for (register int i = (1); i <= (17); ++i)
      fa[i][u] = fa[i - 1][fa[i - 1][u]];
    AddT(p, u);
  }
  dfs(s);
  static int res = 0;
  for (register int i = (1); i <= (n); ++i)
    if (i != s && sz[i] > res) res = sz[i];
  printf("%d\n", res);
  return 0;
}
