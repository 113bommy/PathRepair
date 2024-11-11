#include <bits/stdc++.h>
using namespace std;
const long long N = 800001;
long long n, m, tot, k, ans, q;
long long head[N], f[N], d[N], c[N];
struct lll {
  long long to, next;
} e[N];
inline long long read() {
  long long x = 0, k = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') k = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * k;
}
void add(long long u, long long v) {
  e[++tot].to = v;
  e[tot].next = head[u];
  head[u] = tot;
}
long long find(long long x) {
  if (f[x] == x)
    return x;
  else
    return f[x] = find(f[x]);
}
long long dfs(long long u, long long fa) {
  long long m1 = 0, m2 = 0;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (v == fa) continue;
    long long r = dfs(v, u) + 1;
    if (m1 < r)
      m2 = m1, m1 = r;
    else if (m2 < r)
      m2 = r;
    ans = max(ans, m1 + m2);
  }
  return m1;
}
signed main() {
  n = read();
  m = read();
  q = read();
  for (long long i = 1; i <= n; i++) f[i] = i;
  for (long long i = 1; i <= m; i++) {
    long long x = read(), y = read();
    add(x, y);
    add(y, x);
    f[find(y)] = find(x);
  }
  for (long long i = 1; i <= n; i++) {
    long long fi = find(i);
    if (c[fi] == 0) {
      c[fi] = 1;
      ans = 0;
      dfs(i, 0);
      d[fi] = ans;
    }
  }
  for (long long i = 1; i <= q; i++) {
    long long opt = read();
    if (opt == 1) {
      long long x = read();
      long long fx = find(x);
      printf("%lld\n", d[fx]);
    } else if (opt == 2) {
      long long x = read(), y = read();
      long long fx = find(x), fy = find(y);
      if (fx == fy) continue;
      f[fy] = fx;
      d[fx] = max(d[fx], max(d[fy], (d[fx] + 1) / 2 + (d[fy] + 1) / 2) + 1);
    }
  }
  return 0;
}
