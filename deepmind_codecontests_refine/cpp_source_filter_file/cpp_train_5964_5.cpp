#include <bits/stdc++.h>
const long long N = 2001;
const long long inf = 0x3f3f3f3f3f3f3f3f;
template <class T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
long long n, a[N], l[N], r[N], k, cur, ans, f[N];
inline void solve() {
  read(n);
  read(k);
  for (long long i = 1; i <= n; i++) read(l[i]), read(r[i]), read(a[i]);
  for (long long i = 1; i <= n; i++) {
    f[i] = a[i] + (l[i + 1] == r[i] ? f[i - 1] : 0);
    if (((r[i] - l[i] + 1) * k) < f[i]) return (void)(puts("-1"));
    f[i] -= (r[i] - l[i]) * k;
    f[i] = std::max(f[i], 0ll);
  }
  cur = k;
  for (long long i = 1; i <= n; i++) {
    if (cur < f[i]) ans += cur, cur = k;
    ans += a[i];
    cur = ((cur - a[i]) % k + k) % k;
  }
  printf("%lld\n", ans);
}
signed main() { solve(); }
