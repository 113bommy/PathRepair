#include <bits/stdc++.h>
const int N = 1e5;
const int M = 1e6;
const int LOGN = 20;
struct Edge {
  int to, nxt, w;
} e[N * 2 + 10];
int head[N + 10], tote;
inline void addEdge(int u, int v, int w) {
  e[++tote].to = v;
  e[tote].w = w;
  e[tote].nxt = head[u];
  head[u] = tote;
}
struct _Edge {
  int u, v, w, id, ans;
  inline bool operator<(const _Edge& rhs) const { return w < rhs.w; }
};
_Edge _e[M + 10];
int n, m;
int fa[N + 10][LOGN + 5], dep[N + 10], maxx[N + 10][LOGN + 5];
int f[N + 10];
bool st[M + 10];
inline int getRt(int u) { return f[u] == u ? u : f[u] = getRt(f[u]); }
void Kruskal() {
  std::sort(_e + 1, _e + m + 1);
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    int u = _e[i].u, v = _e[i].v, w = _e[i].w;
    if (getRt(u) == getRt(v)) continue;
    f[getRt(u)] = getRt(v);
    addEdge(u, v, w);
    addEdge(v, u, w);
    st[i] = 1;
  }
}
void DFS(int u, int _fa) {
  fa[u][0] = _fa;
  dep[u] = dep[_fa] + 1;
  for (int i = 1; i <= LOGN; i++)
    fa[u][i] = fa[fa[u][i - 1]][i - 1],
    maxx[u][i] = std::max(maxx[u][i - 1], maxx[fa[u][i - 1]][i - 1]);
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == _fa) continue;
    maxx[v][0] = e[i].w;
    DFS(v, u);
  }
}
inline int LCA(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  for (int i = LOGN; ~i; i--)
    if (dep[u] - (1 << i) >= dep[v]) u = fa[u][i];
  if (u == v) return u;
  for (int i = LOGN; ~i; i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
inline int queryMax(int u, int lca) {
  int res = 0;
  for (int i = LOGN; ~i; i--)
    if (dep[u] - (1 << i) >= dep[lca])
      res = std::max(res, maxx[u][i]), u = fa[u][i];
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &_e[i].u, &_e[i].v, &_e[i].w), _e[i].id = i;
  Kruskal();
  DFS(1, 0);
  for (int i = 1; i <= m; i++) {
    if (st[i])
      _e[i].ans = -1;
    else {
      int u = _e[i].u, v = _e[i].v;
      int lca = LCA(u, v);
      _e[i].ans = std::max(queryMax(u, lca), queryMax(v, lca));
    }
  }
  std::sort(_e + 1, _e + m + 1,
            [](_Edge i, _Edge j) -> bool { return i.id < j.id; });
  for (int i = 1; i <= m; i++)
    if (_e[i].ans != -1) printf("%d\n", _e[i].ans);
  return 0;
}
