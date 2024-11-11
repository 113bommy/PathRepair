#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
  bool operator<(const node &p) const { return y > p.y; }
};
struct mp {
  long long n, m, a[1205], t[400005], d[400005], d2[605][605], d3[1205],
      nx[400005], h[1205];
  long long t1, t2, t3, te;
  long long sx, tx, px[1205];
  void init(long long x, long long y, long long z, long long w) {
    n = x, m = y, sx = z, tx = w;
    te = 0, memset(h, 0, sizeof(h));
    return;
  }
  void add() {
    te++;
    t[te] = t2, nx[te] = h[t1], d[te] = t3;
    h[t1] = te;
    return;
  }
  void dijkstra(long long x) {
    memset(d2[x], 63, sizeof(d2[x]));
    node tn;
    tn.x = x, tn.y = 0, d2[x][x] = 0;
    priority_queue<node> q;
    q.push(tn);
    while (q.size()) {
      tn = q.top();
      q.pop();
      if (d2[x][tn.x] != tn.y) continue;
      for (long long i = h[tn.x]; i; i = nx[i]) {
        if (d2[x][t[i]] <= d2[x][tn.x] + d[i]) continue;
        d2[x][t[i]] = d2[x][tn.x] + d[i];
        node ttn;
        ttn.x = t[i], ttn.y = d2[x][t[i]];
        q.push(ttn);
      }
    }
    return;
  }
  inline long long bfs() {
    memset(d3, 63, sizeof(d3));
    queue<long long> q;
    q.push(sx), d3[sx] = 0, px[sx] = h[sx];
    while (q.size()) {
      long long x = q.front();
      q.pop();
      for (long long i = h[x]; i; i = nx[i]) {
        if (d[i] == 0 || d3[t[i]] != d3[0]) continue;
        d3[t[i]] = d3[x] + 1, px[t[i]] = h[t[i]], q.push(t[i]);
        if (t[i] == tx) return 1;
      }
    }
    return 0;
  }
  inline long long dfs(long long x, long long y) {
    if (y == 0 || x == tx) return y;
    long long r = 0;
    for (long long &i = px[x]; i && y; i = nx[i]) {
      if (d[i] == 0 || d3[t[i]] != d3[x] + 1) continue;
      long long z = dfs(t[i], min(d[i], y));
      if (z == 0) continue;
      y -= z, r += z, d[i] -= z, d[((i - 1) ^ 1) + 1] += z;
    }
    return r;
  }
  long long dinic() {
    long long r = 0;
    memset(px, 0, sizeof(px));
    while (bfs()) r += dfs(sx, d3[0]);
    return r;
  }
} d1, d2;
long long n, m;
long long l1, l2;
long long l3[100005];
inline long long chk(long long x) {
  d2.init((n + 1) << 1, m + (n << 1), (n << 1) | 1, (n + 1) << 1);
  for (long long i = 1; i <= n; i++) {
    d2.t1 = i + n, d2.t2 = d2.tx, d2.t3 = 1;
    d2.add();
    swap(d2.t1, d2.t2), d2.t3 = 0;
    d2.add();
    for (long long j = 1; j <= n; j++) {
      if (d1.d2[i][j] <= x) {
        d2.t1 = i, d2.t2 = j + n, d2.t3 = 1;
        d2.add();
        swap(d2.t1, d2.t2), d2.t3 = 0;
        d2.add();
      }
    }
  }
  long long y = 1;
  for (long long i = 1; i <= l1; i++) {
    if (l3[i] != l3[i + 1]) {
      d2.t1 = d2.sx, d2.t2 = l3[i], d2.t3 = y;
      d2.add();
      swap(d2.t1, d2.t2), d2.t3 = 0;
      d2.add();
      y = 0;
    }
    y++;
  }
  return d2.dinic() >= l2;
}
signed main() {
  scanf("%lld%lld%lld%lld", &n, &m, &l1, &l2);
  for (long long i = 1; i <= l1; i++) {
    scanf("%lld", &l3[i]);
  }
  sort(l3 + 1, l3 + l1 + 1);
  l3[l1 + 1] = 0;
  d1.init(n, m, 0, 0);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &d1.t1, &d1.t2, &d1.t3);
    d1.add();
    swap(d1.t1, d1.t2);
    d1.add();
  }
  for (long long i = 1; i <= n; i++) d1.dijkstra(i);
  if (chk(1731311) == 0) {
    puts("-1");
    return 0;
  }
  long long l = 0, r = 1731311, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (chk(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld", l);
  return 0;
}
