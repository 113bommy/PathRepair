#include <bits/stdc++.h>
using namespace std;
long long h[1000010], nxt[1000010], v[1000010], ct, w[1000010], s, t,
    pre[1000010], dis[1000010], pa[1000010], ec, ans, co[1000010], n, m, k, c,
    d, inq[1000010];
void add(long long a, long long b, long long c, long long d) {
  v[++ec] = b;
  w[ec] = c;
  nxt[ec] = h[a];
  co[ec] = d;
  h[a] = ec;
}
long long id(long long i, long long j) { return i + j * n; }
void adj(long long a, long long b, long long c, long long d) {
  add(a, b, c, d);
  add(b, a, 0, -d);
}
bool bfs() {
  for (long long i = 0; i <= t; i++) {
    dis[i] = 9999999999;
    pre[i] = -1;
  }
  dis[s] = 0;
  queue<long long> q;
  q.push(s);
  inq[s] = 1;
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    inq[x] = 0;
    for (long long i = h[x]; i; i = nxt[i])
      if (w[i] > 0 && co[i] + dis[x] < dis[v[i]]) {
        dis[v[i]] = co[i] + dis[x];
        pa[v[i]] = i;
        pre[v[i]] = x;
        if (!inq[v[i]]) {
          inq[v[i]] = 1;
          q.push(v[i]);
        }
      }
  }
  if (pre[t] == -1) return false;
  return true;
}
long long mcmf() {
  long long c = 0, f = 0;
  while (bfs()) {
    long long fl = 1e9;
    for (long long i = t; s != i; i = pre[i]) fl = min(fl, w[pa[i]]);
    f += fl;
    c += fl * dis[t];
    for (long long i = t; i != s; i = pre[i])
      w[pa[i]] -= fl, w[pa[i] ^ 1] += fl;
  }
  ans = f;
  return c;
}
signed main() {
  ec = 1;
  scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &c, &d);
  t = n * 101 + 3;
  for (long long i = 1; i <= k; i++) {
    long long x;
    scanf("%lld", &x);
    adj(s, id(x, 0), 1, 0);
  }
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    for (long long j = 0; j < 100; j++) {
      for (long long l = 1; l <= k; l++) {
        adj(id(x, j), id(y, j + 1), 1, (l * 2 - 1) * d);
      }
    }
    for (long long j = 0; j < 100; j++) {
      for (long long l = 1; l <= k; l++) {
        adj(id(y, j), id(x, j + 1), 1, (l * 2 - 1) * d);
      }
    }
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j < 100; j++) adj(id(i, j), id(i, j + 1), 1e9, 0);
  for (long long j = 0; j <= 100; j++) adj(id(1, j), t, 1e9, j * c);
  printf("%lld\n", mcmf());
}
