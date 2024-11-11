#include <bits/stdc++.h>
const long long MaxN = 1000010;
struct query {
  long long l, r, id, pos;
};
query q[MaxN];
long long n, t, size;
long long ans[MaxN], sum;
long long a[MaxN], cnt[MaxN];
inline long long cmp(query a, query b) {
  if (a.pos != b.pos) return a.pos < b.pos;
  return a.r < b.r;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch <= '9' && ch >= '0')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x;
}
inline void add(long long x) {
  sum += a[x] * (2 * cnt[a[x]] + 1);
  cnt[a[x]]++;
}
inline void del(long long x) {
  sum -= a[x] * (2 * cnt[a[x]] - 1);
  cnt[a[x]]--;
}
inline void solve() {
  long long l = 1, r = 0;
  for (long long i = 1; i <= t; i++) {
    while (l > q[i].l) --l, add(l);
    while (r < q[i].r) ++r, add(r);
    while (l < q[i].l) del(l), ++l;
    while (r > q[i].r) del(r), --r;
    ans[q[i].id] = sum;
  }
}
signed main() {
  n = read(), t = read();
  size = pow(n, 0.55);
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= t; i++) {
    q[i].l = read(), q[i].r = read();
    q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
  }
  std::sort(q + 1, q + t + 1, cmp);
  solve();
  for (long long i = 1; i <= t; i++) printf("%lld\n", ans[i]);
  return 0;
}
