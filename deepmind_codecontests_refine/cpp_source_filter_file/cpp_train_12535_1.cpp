#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f, N = 1e4 + 10, M = 110;
long long n, m, k, s1, s2, t, head[N], cnt, l[M], r[M], bl[M];
bool ans[M];
struct edge {
  long long nxt, u, v, w;
} e[N + M];
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q;
void add(long long u, long long v, long long w) {
  e[cnt] = (edge){head[u], u, v, w};
  head[u] = cnt++;
}
struct Gragh {
  long long d[N];
  bool vis[N];
  void dij(long long s) {
    while (!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
      long long u = q.top().second;
      q.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      for (long long i = head[u]; i + 1; i = e[i].nxt) {
        long long v = e[i].v, w = e[i].w;
        if (d[v] > d[u] + w) {
          d[v] = d[u] + w;
          q.push(make_pair(d[v], v));
        }
      }
    }
  }
} g1, g2;
inline void read(long long &x) {
  x = 0;
  char c = getchar(), f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
signed main() {
  memset(head, -1, sizeof(head));
  read(n), read(m), read(k), read(s1), read(s2), read(t);
  long long u, v, w;
  for (long long i = 1; i <= m; ++i) {
    read(u), read(v), read(w);
    add(u, v, w);
  }
  for (long long i = 1; i <= k; ++i) {
    read(u), read(v), read(l[i]), read(r[i]);
    add(u, v, r[i]);
    bl[i] = cnt - 1;
  }
  bool flag = 1;
  while (flag) {
    g1.dij(s1);
    g2.dij(s2);
    flag = 0;
    for (long long j = 1; j <= k; ++j) {
      long long i = bl[j];
      if (e[i].w == l[j] || g1.d[e[i].u] > g2.d[e[i].u]) continue;
      e[i].w = l[j];
      ans[i] = flag = 1;
    }
  }
  g1.dij(s1);
  g2.dij(s2);
  if (g1.d[t] < g2.d[t])
    puts("WIN");
  else if (g1.d[t] == g2.d[t])
    puts("DRAW");
  else
    return puts("LOSE"), 0;
  for (long long i = 1; i <= k; ++i) printf("%lld ", ans[i] ? l[i] : r[i]);
  return 0;
}
