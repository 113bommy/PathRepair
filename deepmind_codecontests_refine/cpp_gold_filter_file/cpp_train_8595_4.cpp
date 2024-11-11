#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, maxm = 3e5 + 10;
int n, m, s, hed[maxn], q[maxn], ed, ans, sz[maxn], fa[maxn][21], dep[maxn],
    d[maxn], u, v, w;
long long dis[maxn];
vector<int> f[maxn];
struct edge {
  int from, to, nex;
  long long val;
  edge(int t = 0, int _ = 0, int __ = 0, long long ___ = 0)
      : from(t), to(_), nex(__), val(___) {}
} e[maxm << 1];
struct node {
  int u;
  long long dis;
};
inline bool operator<(node a, node b) { return a.dis > b.dis; }
inline void add_edge(int u, int v, long long w) {
  e[++ed] = edge(u, v, hed[u], w);
  hed[u] = ed;
}
void dijkstra(int s) {
  priority_queue<node> pq;
  for (int i = (1); i <= (n); ++i) dis[i] = 1e18;
  dis[s] = 0;
  pq.push((node){s, 0});
  while (!pq.empty()) {
    node x = pq.top();
    pq.pop();
    int u = x.u;
    for (int i = hed[u], v = e[i].to; i; i = e[i].nex, v = e[i].to)
      if (dis[v] > x.dis + e[i].val) {
        dis[v] = x.dis + e[i].val;
        pq.push((node){v, dis[v]});
      }
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  if (dep[u] != dep[v]) {
    int t = dep[u] - dep[v];
    for (int i = (0); i <= (20); ++i)
      if (t & (1 << i)) u = fa[u][i];
  }
  if (u == v) return u;
  for (int i = (20); i >= (0); --i)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
void bd(int u) {
  int t = f[u][0];
  for (int i = (0); i <= ((int)f[u].size() - 1); ++i) t = lca(t, f[u][i]);
  dep[u] = dep[t] + 1;
  fa[u][0] = t;
  for (int i = (1); i <= (20); ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  sz[u] = 1;
}
void topsort(int s) {
  int l = 1, r = 1;
  q[1] = s;
  sz[s] = 1;
  for (int i = (1); i <= (ed); ++i)
    if (dis[e[i].from] + e[i].val == dis[e[i].to]) ++d[e[i].to];
  while (l <= r) {
    int u = q[l++];
    for (int i = hed[u], v = e[i].to; i; i = e[i].nex, v = e[i].to) {
      if (dis[v] != dis[u] + e[i].val) continue;
      --d[v];
      f[v].push_back(u);
      if (!d[v]) q[++r] = v, bd(v);
    }
  }
}
void get_ans() {
  for (int i = (n); i >= (1); --i) sz[fa[q[i]][0]] += sz[q[i]];
  for (int i = (1); i <= (n); ++i)
    if (i != s) ans = max(ans, sz[i]);
  printf("%d\n", ans);
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = (1); i <= (m); ++i)
    scanf("%d%d%d", &u, &v, &w), add_edge(u, v, w), add_edge(v, u, w);
  dijkstra(s);
  topsort(s);
  get_ans();
  return 0;
}
