#include <bits/stdc++.h>
using namespace std;
const long long N = 150;
long long n, m, d[N], ans = 1e18;
queue<long long> q;
struct Edge {
  long long u, v, d;
} e[N];
struct matrix {
  bitset<N> a[N];
  friend bitset<N> operator*(const bitset<N> &z, const matrix &b) {
    bitset<N> c;
    for (long long i = 0; i < n; ++i) c[i] = (z & b.a[i]).any();
    return c;
  }
  matrix operator*(const matrix &b) {
    matrix c;
    for (long long i = 0; i < n; ++i) c.a[i].reset();
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < n; ++j)
        if (a[i][j]) c.a[i] |= b.a[j];
    return c;
  }
} g;
bitset<N> vis;
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 0; i < m; ++i)
    scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].d), --e[i].u, --e[i].v;
  sort(e, e + m, [](Edge x, Edge y) { return x.d < y.d; }), vis[0] = 1;
  for (long long i = 0, lst = 0; i < m; ++i) {
    if (e[i].d >= ans) break;
    matrix tmp = g;
    for (long long p = e[i].d - lst; p; p >>= 1, tmp = tmp * tmp)
      if (p & 1) vis = vis * tmp;
    g.a[e[i].v][e[i].u] = 1, lst = e[i].d;
    for (long long j = 0; j < n; ++j)
      if (vis[j])
        q.push(j), d[j] = 0;
      else
        d[j] = 1e9;
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      for (long long j = 0; j < n; ++j)
        if (g.a[j][u] && d[j] == 1e18) d[j] = d[u] + 1, q.push(j);
    }
    ans = min(ans, lst + d[n - 1]);
  }
  if (ans == 1e18)
    puts("Impossible");
  else
    printf("%lld", ans);
  return 0;
}
