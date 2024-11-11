#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v, id;
  long double w;
  Edge() {}
  Edge(int u, int v, long double w, int id) : u(u), v(v), w(w), id(id) {}
  bool operator<(const Edge &d) const { return w < d.w; }
};
const int N = (int)5e3 + 10;
const int M = (int)1e5 + 10;
const int INF = (int)1e6;
int n, m, k, deg[N];
int cnt, ans[N], p[N];
Edge G[M], E[M];
int Root(int u) {
  if (p[u] < 0) return u;
  return p[u] = Root(p[u]);
}
bool Merge(int u, int v) {
  u = Root(u);
  v = Root(v);
  if (u == v) return false;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return true;
}
int MST(long double x) {
  for (int i = 1; i <= m; ++i) {
    E[i] = G[i];
    if (E[i].u == 1 || E[i].v == 1) E[i].w += x;
  }
  for (int i = 1; i <= n; ++i) p[i] = -1;
  sort(E + 1, E + m + 1);
  int d = cnt = 0;
  for (int i = 1; i <= m; ++i) {
    int u = E[i].u, v = E[i].v;
    if (Merge(u, v)) ans[++cnt] = E[i].id, d += (u == 1 || v == 1);
  }
  return d;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[i] = Edge(u, v, w, i);
    deg[G[i].u]++;
    deg[G[i].v]++;
  }
  long double l = -INF, r = INF, f = 2 * INF;
  for (int i = 1; i <= 200; ++i) {
    long double m = (l + r) / 2;
    int R = MST(m);
    if (R >= k) {
      if (R == k) f = m;
      l = m;
    } else
      r = m;
  }
  if (abs(f - 2 * INF) < 1e-9) {
    puts("-1");
    return 0;
  }
  MST(f);
  assert(cnt == n - 1);
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i) printf("%d ", ans[i]);
  return 0;
}
