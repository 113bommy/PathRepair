#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, m, k;
long long is[N];
struct edge {
  long long to, val, nxt;
} e[N << 1];
long long h[N], cnt = 0;
inline long long read() {
  long long x, f = 1;
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') f = -1;
  x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void add(long long from, long long to, long long val) {
  e[++cnt] = edge{to, val, h[from]};
  h[from] = cnt;
}
long long dis[N], p[N];
bool used[N];
void dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  memset(used, false, sizeof used);
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      Q;
  for (long long i = 1; i <= k; i++)
    dis[is[i]] = 0, p[is[i]] = is[i], Q.push(make_pair(0, is[i]));
  while (!Q.empty()) {
    long long u = Q.top().second;
    Q.pop();
    if (used[u]) break;
    used[u] = true;
    for (long long i = h[u]; i; i = e[i].nxt) {
      long long v = e[i].to, w = e[i].val;
      if (dis[v] > dis[u] + w)
        dis[v] = dis[u] + w, p[v] = p[u], Q.push(make_pair(dis[v], v));
    }
  }
}
struct E {
  long long u, v, w;
  bool operator<(const E x) const { return w < x.w; }
} a[N << 1];
long long tot = 0;
long long fa[N];
long long find(long long x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
long long kruskal() {
  for (long long u = 1; u <= n; u++)
    for (long long i = h[u]; i; i = e[i].nxt) {
      long long v = e[i].to, w = e[i].val;
      a[++tot] = E{p[u], p[v], dis[u] + w + dis[v]};
    }
  for (long long i = 1; i <= n; i++) fa[i] = i;
  sort(a + 1, a + tot + 1);
  long long ret = 0;
  for (long long i = 1; i <= tot; i++) {
    long long u = a[i].u, v = a[i].v, w = a[i].w;
    if (find(u) == find(v)) continue;
    fa[find(u)] = find(v);
    ret += w;
  }
  return ret;
}
signed main() {
  n = read(), m = read();
  for (long long i = 1, x, y, w; i <= m; i++) {
    x = read(), y = read(), w = read();
    add(x, y, w);
    add(y, x, w);
  }
  k = read();
  for (long long i = 1; i <= k; i++) is[i] = read();
  dijkstra();
  printf("%lld", kruskal() + dis[1]);
  return 0;
}
