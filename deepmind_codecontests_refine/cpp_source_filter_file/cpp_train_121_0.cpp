#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 300005;
const long long INF = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
template <typename T>
inline void cmax(T &x, T y) {
  if (x < y) x = y;
}
int n, m, k, Q;
int vis[MAXN], from[MAXN], fa[MAXN], siz[MAXN];
long long dis[MAXN], fw[MAXN];
priority_queue<pair<long long, int> > q;
struct Edge {
  int v, w, nxt;
} g[MAXM << 1];
int first[MAXN], eCnt;
inline void AddEdge(int u, int v, int w) {
  g[++eCnt].v = v;
  g[eCnt].w = w;
  g[eCnt].nxt = first[u];
  first[u] = eCnt;
}
struct Edge2 {
  int u, v;
  long long w;
  bool operator<(const Edge2 &rhs) const { return w < rhs.w; }
} e[MAXM];
void Dijkstra() {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= k; ++i) {
    dis[i] = 0;
    from[i] = i;
    q.push(make_pair(0, i));
  }
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = first[u]; i; i = g[i].nxt) {
      int v = g[i].v;
      if (dis[v] > dis[u] + g[i].w) {
        dis[v] = dis[u] + g[i].w;
        from[v] = from[u];
        q.push(make_pair(-dis[v], v));
      }
    }
  }
}
int getf(int u) {
  while (fa[u] != u) u = fa[u];
  return u;
}
void Build() {
  for (int i = 2; i <= eCnt; i += 2) {
    e[i >> 1].u = from[g[i].v];
    e[i >> 1].v = from[g[i - 1].v];
    e[i >> 1].w = dis[g[i].v] + dis[g[i - 1].v] + g[i].w;
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    siz[i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    int u = getf(e[i].u), v = getf(e[i].v);
    if (u == v) continue;
    if (siz[u] > siz[v]) swap(u, v);
    siz[v] += siz[u];
    fa[u] = v;
    fw[u] = e[i].w;
  }
}
int Query(int u, int v) {
  long long ret = 0;
  while (u ^ v) {
    if (siz[u] > siz[v]) swap(u, v);
    cmax(ret, fw[u]);
    u = fa[u];
  }
  return ret;
}
void init() {
  read(n);
  read(m);
  read(k);
  read(Q);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    read(u);
    read(v);
    read(w);
    AddEdge(u, v, w);
    AddEdge(v, u, w);
  }
}
void solve() {
  Dijkstra();
  Build();
  while (Q--) {
    int x, y;
    read(x);
    read(y);
    printf("%lld\n", Query(x, y));
  }
}
int main() {
  init();
  solve();
  return 0;
}
