#include <bits/stdc++.h>
using namespace std;
long long get() {
  long long x = 0;
  char s = getchar();
  while (s < '0' || s > '9') s = getchar();
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s ^ 48), s = getchar();
  return x;
}
long long Min(const long long x, const long long y) {
  if (x < y) return x;
  return y;
}
const long long M = 1e5 + 5;
long long n, m, s, t, head[M], headr[M], heads[M], cntedge, cntedger,
    cntedges = 1, dis[M], disr[M];
long long dfn[M], low[M], tot, ans[M];
bool uniq[M];
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q;
struct edge {
  long long to, nxt, w;
  edge() {}
  edge(const long long T, const long long NX, const long long W) {
    to = T, nxt = NX, w = W;
  }
} e[M], er[M], es[M << 1];
void add(const long long u, const long long v, const long long w) {
  e[++cntedge] = edge(v, head[u], w), head[u] = cntedge;
}
void addr(const long long u, const long long v, const long long w) {
  er[++cntedger] = edge(v, headr[u], w), headr[u] = cntedger;
}
void adds(const long long u, const long long v, const long long id) {
  es[++cntedges] = edge(v, heads[u], id), heads[u] = cntedges;
}
void dijkstra(long long *Head, edge *E, long long *Dis, const long long S) {
  for (long long i = 1; i <= n; ++i) Dis[i] = 0x3f3f3f3f3f3f3f3f;
  Dis[S] = 0;
  q.push(pair<long long, long long>(0, S));
  while (!q.empty()) {
    pair<long long, long long> p = q.top();
    q.pop();
    for (long long i = Head[p.second], v; i; i = E[i].nxt)
      if (Dis[v = E[i].to] > Dis[p.second] + E[i].w)
        q.push(pair<long long, long long>(Dis[v] = Dis[p.second] + E[i].w, v));
  }
}
void tarjan(const long long u, const long long faedge) {
  dfn[u] = low[u] = ++tot;
  for (long long i = heads[u], v; i; i = es[i].nxt) {
    if (!dfn[v = es[i].to]) {
      tarjan(v, i);
      if (low[v] > dfn[u]) uniq[es[i].w] = 1;
      low[u] = Min(low[u], low[v]);
    } else if (dfn[u] > dfn[v] && (i ^ 1 ^ faedge))
      low[u] = Min(low[u], dfn[v]);
  }
}
signed main() {
  n = get(), m = get(), s = get(), t = get();
  for (long long i = 1, u, v, w; i <= m; ++i) {
    u = get(), v = get(), w = get();
    add(u, v, w), addr(v, u, w);
  }
  dijkstra(head, e, dis, s), dijkstra(headr, er, disr, t);
  long long mndis = dis[t];
  for (long long i = 1, v; i <= n; ++i)
    for (long long j = head[i]; j; j = e[j].nxt) {
      v = e[j].to;
      if (dis[i] + e[j].w + disr[v] == mndis) adds(i, v, j), adds(v, i, j);
    }
  for (long long i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i, 0);
  for (long long i = 1; i <= n; ++i)
    for (long long j = head[i]; j; j = e[j].nxt) {
      long long v = e[j].to, tmp = dis[i] + disr[v];
      if (uniq[j])
        ans[j] = 0;
      else {
        ans[j] = e[j].w - (mndis - tmp - 1);
        if (e[j].w <= ans[j]) ans[j] = -1;
      }
    }
  for (long long i = 1; i <= m; ++i)
    if (!ans[i])
      printf("YES\n");
    else if (~ans[i])
      printf("CAN %lld\n", ans[i]);
    else
      printf("NO\n");
  return 0;
}
