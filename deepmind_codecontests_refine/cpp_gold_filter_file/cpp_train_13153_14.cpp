#include <bits/stdc++.h>
const int INF = 0x3F3F3F3F;
struct edg {
  int v, c, i;
  edg *e, *f, *g;
} GR[(5000 + 200 * 4 + 1) * 2], *GS = GR, *GT, *GA[(200 * 2 + 3)],
                                *GC[(200 * 2 + 3)];
inline void edg_ins(int u, int v, int c, int i = 0) {
  if (c) {
    if (GA[u]) GA[u]->f = GS;
    *GS = (edg){v, c, i, GA[u], NULL, GS + 1}, GA[u] = GS++;
    if (GA[v]) GA[v]->f = GS;
    *GS = (edg){u, 0, 0, GA[v], NULL, GS - 1}, GA[v] = GS++;
  }
}
inline void edg_del(edg *e) {
  if (e->e) e->e->f = e->f;
  if (e->f) e->f->e = e->e;
  if (e == GA[e->g->v]) GA[e->g->v] = e->e;
  if (e->g->e) e->g->e->f = e->g->f;
  if (e->g->f) e->g->f->e = e->g->e;
  if (e->g == GA[e->v]) GA[e->v] = e->g->e;
}
int V, Ql, Qr, Q[(200 * 2 + 3)], dis[(200 * 2 + 3)];
inline bool bfs(const int &s, const int &t) {
  int u;
  edg *e;
  memset(dis, -1, V * sizeof(int));
  Ql = Qr = -1, dis[Q[++Qr] = s] = 0;
  while (Ql < Qr)
    for (e = GA[u = Q[++Ql]]; e; e = e->e)
      if (e->c && !~dis[e->v]) dis[Q[++Qr] = e->v] = dis[u] + 1;
  return ~dis[t];
}
inline int dfs(const int &s, int u, int c = INF) {
  if (u == s || c == 0) return c;
  int f = 0, d;
  for (edg *e = GC[u]; e && c; e = e->e)
    if (dis[u] == dis[e->v] + 1 && (d = dfs(s, e->v, std::min(c, e->g->c))))
      e->c += d, e->g->c -= d, f += d, c -= d;
  if (c) dis[u] = -1;
  return f;
}
inline void dnc(const int &s, const int &t) {
  for (; bfs(s, t); dfs(s, t)) memcpy(GC, GA, V * sizeof(edg *));
}
int M, N, E, K, i, u, v, s, t, b, c, f, sum, a[5000 + 1], d[200 * 2 + 1];
edg *e;
int main() {
  scanf("%d %d %d %d", &M, &N, &E, &K);
  s = M + N + 1, t = s + 1, V = t + 1;
  for (i = 1; i <= E; ++i)
    scanf("%d %d", &u, &v), edg_ins(u, M + v, 1, i), a[i] = 1, ++d[u],
                                                     ++d[M + v];
  for (u = 1; u <= M + N; ++u) sum += bool(d[u] % K);
  printf("%d\n", sum);
  GT = GS;
  for (; K > 1; --K) {
    GS = GT, f = 0;
    for (e = GA[0]; e; e = e->e) edg_del(e);
    for (e = GA[s]; e; e = e->e) edg_del(e);
    for (e = GA[t]; e; e = e->e) edg_del(e);
    for (u = 1; u <= M; ++u)
      b = d[u] / K, c = (d[u] + K - 1) / K, edg_ins(s, u, b),
      edg_ins(0, u, c - b), f -= b;
    for (v = M + 1; v <= M + N; ++v)
      b = d[v] / K, c = (d[v] + K - 1) / K, edg_ins(v, t, b),
      edg_ins(v, 0, c - b), f += b;
    if (f > 0)
      edg_ins(s, 0, +f);
    else if (f < 0)
      edg_ins(0, t, -f);
    dnc(s, t);
    for (u = 1; u <= M; ++u)
      for (e = GA[u]; e; e = e->e)
        if (e->i && !e->c) a[e->i] = K, --d[u], --d[e->v], edg_del(e);
  }
  for (i = 1; i <= E; ++i) printf("%d%c", a[i], i < E ? ' ' : '\n');
  return 0;
}
