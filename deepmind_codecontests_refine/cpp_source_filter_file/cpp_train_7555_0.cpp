#include <bits/stdc++.h>
inline long long read() {
  char c = getchar();
  long long s = 0;
  bool x = 0;
  while (!isdigit(c)) x = x | (c == '-'), c = getchar();
  while (isdigit(c)) s = 10 * s + c - '0', c = getchar();
  return x ? -s : s;
}
const long long maxn = 1e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;
long long n, q, s, treeIn[maxn << 2], treeOut[maxn << 2], cnt;
bool vis[maxn * 10];
struct edge {
  long long to, nxt, dis;
} e[maxn * 10];
long long cnte, head[maxn * 10], dis[maxn];
void add(long long u, long long v, long long w) {
  e[++cnte].to = v;
  e[cnte].dis = w;
  e[cnte].nxt = head[u];
  head[u] = cnte;
  return;
}
void build(long long i, long long j, long long k) {
  if (i == j) {
    treeIn[k] = i, treeOut[k] = i;
    return;
  }
  build(i, ((i + j) >> 1), (k << 1));
  build(((i + j) >> 1) + 1, j, ((k << 1) | 1));
  treeIn[k] = ++cnt, treeOut[k] = ++cnt;
  add(treeOut[(k << 1)], treeOut[k], 0);
  add(treeOut[((k << 1) | 1)], treeOut[k], 0);
  add(treeIn[k], treeIn[(k << 1)], 0);
  add(treeIn[k], treeIn[((k << 1) | 1)], 0);
  return;
}
void updateIn(long long i, long long j, long long k, long long l, long long r,
              long long from, long long dist) {
  if (i >= l && j <= r) {
    add(from, treeIn[k], dist);
    return;
  }
  if (l <= ((i + j) >> 1))
    updateIn(i, ((i + j) >> 1), (k << 1), l, r, from, dist);
  if (r > ((i + j) >> 1))
    updateIn(((i + j) >> 1) + 1, j, ((k << 1) | 1), l, r, from, dist);
}
void updateOut(long long i, long long j, long long k, long long l, long long r,
               long long to, long long dist) {
  if (i >= l && j <= r) {
    add(treeOut[k], to, dist);
    return;
  }
  if (l <= ((i + j) >> 1))
    updateOut(i, ((i + j) >> 1), (k << 1), l, r, to, dist);
  if (r > ((i + j) >> 1))
    updateOut(((i + j) >> 1) + 1, j, ((k << 1) | 1), l, r, to, dist);
}
struct state {
  long long now, dist;
  state() {}
  state(long long u, long long w) { now = u, dist = w; }
  bool operator<(const state &b) const { return this->dist > b.dist; }
};
void dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;
  std::priority_queue<state> q;
  q.push(state(s, 0));
  while (!q.empty()) {
    long long now = q.top().now;
    q.pop();
    if (!vis[now]) {
      vis[now] = 1;
      for (signed i = head[now]; i; i = e[i].nxt) {
        long long &to = e[i].to, &w = e[i].dis;
        if (dis[to] > dis[now] + w) {
          dis[to] = dis[now] + w;
          q.push(state(to, dis[to]));
        }
      }
    }
  }
  return;
}
signed main() {
  cnt = n = read(), q = read(), s = read();
  build(1, n, 1);
  register long long opt, _u, _v, _w, _l, _r;
  while (q--) {
    opt = read();
    if (opt == 1) {
      _u = read(), _v = read(), _w = read();
      add(_u, _v, _w);
    } else {
      _u = read(), _l = read(), _r = read(), _w = read();
      if (opt == 3)
        updateOut(1, n, 1, _l, _r, _u, _w);
      else
        updateIn(1, n, 1, _l, _r, _u, _w);
    }
  }
  dijkstra();
  for (register signed i = 1; i <= n; ++i)
    printf("%lld ", dis[i] == INF ? -1 : dis[i]);
  return 0;
}
