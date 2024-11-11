#include <bits/stdc++.h>
const long long lim = 3e8 + 5;
const long long inf = 0x3f3f3f3f;
long long n, m, s, t, ans, head[10010], to[200010], nxt[200010], w[200010], cnt,
    cur[200010];
void add(const long long& x, const long long& y, const long long& z) {
  to[cnt] = y;
  w[cnt] = z;
  nxt[cnt] = head[x];
  head[x] = cnt++;
}
long long d[10010], que[10010], *hd, *tl;
bool bfs() {
  d[t] = 1;
  hd = tl = que;
  *tl++ = t;
  while (tl != hd) {
    long long x = *hd++;
    for (long long i = head[x]; ~i; i = nxt[i]) {
      if (w[i ^ 1] && !d[to[i]]) {
        *tl++ = to[i];
        d[to[i]] = d[x] + 1;
      }
    }
  }
  return d[s];
}
long long dfs(const long long& x, const long long& low) {
  if (x == t) {
    ans -= low;
    return low;
  }
  for (long long& i = cur[x]; ~i; i = nxt[i])
    if (w[i] && d[to[i]] + 1 == d[x]) {
      long long res = dfs(to[i], w[i] < low ? w[i] : low);
      if (res) {
        w[i] -= res;
        w[i ^ 1] += res;
        return res;
      }
    }
  return 0;
}
signed main() {
  memset(head, -1, sizeof(head));
  scanf("%lld", &n);
  t = n + n + 1, s = 0;
  for (long long m, x, i = 1; i <= n; i++) {
    scanf("%lld", &m);
    while (m--) {
      scanf("%lld", &x);
      add(i, x + n, inf);
      add(x + n, i, 0);
    }
  }
  for (long long i = 1, x; i <= n; i++)
    scanf("%lld", &x), add(s, i, lim - x), add(i, s, 0), ans += lim - x;
  for (long long i = 1; i <= n; i++) add(i + n, t, lim), add(t, i + n, 0);
  while (bfs()) {
    for (long long i = s; i <= t; i++) cur[i] = head[i];
    while (dfs(s, 0x7fffffff))
      ;
    memset(d, 0, sizeof(d));
  }
  printf("%lld", ans < 0 ? 0 : -ans);
  return 0;
}
