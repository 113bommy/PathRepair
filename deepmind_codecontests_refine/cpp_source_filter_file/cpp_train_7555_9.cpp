#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  int fl = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') fl = -fl;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= fl;
}
template <class T>
inline void wr(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  int tmp[30] = {0}, cnt = 0;
  while (x) tmp[cnt++] = x % 10, x /= 10;
  for (register int i = cnt - 1; i >= 0; --i) putchar(tmp[i] + '0');
}
const long long N = 5e5 + 5, D = 5e5, INF = 1e17;
long long n, m, st, dis[N << 1], node[N];
bool vst[N << 1];
vector<pair<long long, long long> > es[N];
inline void build(long long x, long long l, long long r) {
  if (l == r) {
    node[l] = x;
    return;
  }
  es[x].push_back(make_pair(0, (x << 1)));
  es[x].push_back(make_pair(0, (x << 1 | 1)));
  es[(x << 1) + D].push_back(make_pair(0, x + D));
  es[(x << 1 | 1) + D].push_back(make_pair(0, x + D));
  build((x << 1), l, ((l + r) >> 1));
  build((x << 1 | 1), ((l + r) >> 1) + 1, r);
}
inline void add(long long x, long long l, long long r, long long L, long long R,
                long long v, long long w, long long op) {
  if (L <= l && r <= R) {
    if (op == 2)
      es[v].push_back(make_pair(w, x));
    else
      es[x + D].push_back(make_pair(w, v));
    return;
  }
  if (L <= ((l + r) >> 1)) add((x << 1), l, ((l + r) >> 1), L, R, v, w, op);
  if (R > ((l + r) >> 1))
    add((x << 1 | 1), ((l + r) >> 1) + 1, r, L, R, v, w, op);
}
inline void dijkstra(long long s) {
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      q;
  fill(dis, dis + (N << 1) + 1, INF);
  dis[s] = 0;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    long long x = q.top().second, sum = q.top().first;
    q.pop();
    if (vst[x]) continue;
    vst[x] = 1;
    for (register long long i = 0; i < es[x].size(); ++i) {
      long long t = es[x][i].second, w = es[x][i].first;
      if (dis[t] > sum + w) {
        dis[t] = sum + w;
        q.push(make_pair(dis[t], t));
      }
    }
  }
}
signed main() {
  rd(n);
  rd(m);
  rd(st);
  build(1, 1, n);
  for (register long long i = 1; i <= n; ++i)
    es[node[i]].push_back(make_pair(0, node[i] + D)),
        es[node[i] + D].push_back(make_pair(0, node[i]));
  for (register long long i = 1; i <= m; ++i) {
    long long op, u, v, w, l, r;
    rd(op);
    if (op == 1) {
      rd(v);
      rd(u);
      rd(w);
      es[node[v]].push_back(make_pair(w, node[u]));
    } else {
      rd(v);
      rd(l);
      rd(r);
      rd(w);
      add(1, 1, n, l, r, node[v], w, op);
    }
  }
  dijkstra(node[st]);
  for (register long long i = 1; i <= n; ++i) {
    if (dis[node[i]] == INF)
      cout << "-1 ";
    else
      wr(dis[node[i]]), putchar(' ');
  }
  puts("");
  return 0;
}
