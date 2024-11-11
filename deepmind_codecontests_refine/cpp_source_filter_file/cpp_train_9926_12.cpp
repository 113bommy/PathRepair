#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n, m, k, a[N], ans = 1e18;
struct edge {
  long long u, v, w, nxt;
} e[N << 1], E[N];
long long cnt, head[N];
inline void add(long long u, long long v, long long w) {
  e[++cnt].u = u;
  e[cnt].v = v;
  e[cnt].w = w;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
struct node {
  long long pos, dis;
  bool operator<(const node &x) const { return dis < x.dis; }
};
priority_queue<node> q;
long long dis[N], pt[N];
bool vis[N];
inline void dij() {
  for (long long i = 1; i <= n; i++) dis[i] = 1e18;
  memset(pt, 0, sizeof(pt));
  memset(vis, 0, sizeof(vis));
  for (long long i = 1; i <= k; i++) {
    dis[a[i]] = 0;
    q.push((node){a[i], 0});
    pt[a[i]] = a[i];
  }
  while (!q.empty()) {
    long long u = q.top().pos;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (long long i = head[u]; i; i = e[i].nxt) {
      long long v = e[i].v;
      if (dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        pt[v] = pt[u];
        q.push((node){v, dis[v]});
      }
    }
  }
}
inline bool cmp(edge i, edge j) { return i.w < j.w; }
long long fa[N];
inline long long find(long long u) {
  if (fa[u] == u) return u;
  return fa[u] = find(fa[u]);
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1, u, v, w; i <= m; i++) {
    scanf("%lld%lld%lld", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  a[++k] = 1;
  dij();
  scanf("%lld", &k);
  for (long long i = 1; i <= k; i++) {
    scanf("%lld", &a[i]);
    ans = min(ans, dis[a[i]]);
  }
  dij();
  for (long long i = 1; i <= cnt; i += 2) {
    long long u = e[i].u, v = e[i].v, p = (i + 1) >> 1;
    E[p].u = pt[u];
    E[p].v = pt[v];
    E[p].w = dis[u] + dis[v] + e[i].w;
  }
  sort(E + 1, E + 1 + m, cmp);
  for (long long i = 1; i <= n; i++) fa[i] = i;
  for (long long i = 1; i <= m; i++) {
    long long u = E[i].u, v = E[i].v;
    long long fu = find(u), fv = find(v);
    if (fu == fv) continue;
    ans += E[i].w;
    fa[fu] = fv;
  }
  printf("%lld\n", ans);
  return 0;
}
