#include <bits/stdc++.h>
const long long N = 1e6 + 1;
const long long p = 1e9 + 7;
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
long long n, a[N], fa[N], sm[N], f[N], tmp, g[N], ans;
inline long long gcd(long long a, long long b) {
  return (!b) ? a : gcd(b, a % b);
}
inline void solve() {
  read(n);
  for (long long i = 1; i <= n; i++) read(a[i]);
  for (long long i = 2; i <= n; i++) read(fa[i]);
  for (long long i = n; i >= 1; i--) sm[i] += a[i], sm[fa[i]] += sm[i];
  for (long long i = 1; i <= n; i++) {
    tmp = sm[1] / gcd(sm[1], sm[i]);
    if (tmp > n) continue;
    for (long long j = tmp; j <= n; j += tmp) f[j]++;
  }
  for (long long i = 1; i <= n; i++) f[i] = (f[i] == i), g[i] = f[i];
  for (long long i = 2; i <= n; i++)
    if (g[i])
      for (long long j = i + i; j <= n; j += i) (f[j] += f[i]) %= p;
  for (long long i = 1; i <= n; i++) (ans += g[i] * f[i]) %= p;
  printf("%lld\n", ans);
}
signed main() { solve(); }
