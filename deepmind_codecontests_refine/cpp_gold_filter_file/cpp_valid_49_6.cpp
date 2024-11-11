#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, fh = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    a = a * 10 + c - 48;
    c = getchar();
  }
  return a * fh;
}
long long T, n, m;
const long long N = 2e6;
long long inv[N + N + 5];
long long f[(1 << 14 | 5)], g[(1 << 14 | 5)][15], h[(1 << 14 | 5)];
long long cnt[(1 << 14 | 5)], a[15];
long long sgn(long long n) {
  if (n & 1) return (1000000007 - 1);
  return 1;
}
signed main() {
  n = read();
  inv[1] = 1;
  for (long long i = 2; i <= N + N; ++i)
    inv[i] = (1000000007 - 1000000007 / i) * inv[1000000007 % i] % 1000000007;
  for (long long i = 1; i <= n; ++i) a[i] = read();
  for (long long st = 0; st < (1 << n); ++st) {
    cnt[st] = (cnt[st >> 1] + (st & 1));
    for (long long i = 1; i <= n; ++i) {
      if ((st >> i - 1) & 1) continue;
      g[st][i] = 1;
      for (long long j = 1; j <= n; ++j)
        if ((st >> j - 1) & 1)
          g[st][i] =
              g[st][i] * inv[a[j] + a[i]] % 1000000007 * a[j] % 1000000007;
    }
  }
  for (long long st = 1; st < (1 << n); ++st) {
    h[st] = 1;
    for (long long u = (st - 1) & st; u; u = (u - 1) & st) {
      long long A = 1, B = 1;
      for (long long j = 1; j <= n; ++j) {
        if ((u >> j - 1) & 1) A = g[st - u][j] * A % 1000000007;
        if (((st - u) >> j - 1) & 1) B = g[u][j] * B % 1000000007;
      }
      A = 0;
      h[st] = (h[st] - h[u] * (A + B) % 1000000007 + 1000000007) % 1000000007;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 0; j < (1 << n); ++j) f[j] = 0;
    for (long long st = (1 << i - 1); st < (1 << n); ++st) {
      if (!((st >> i - 1) & 1)) continue;
      f[st] = (f[st] + h[st]) % 1000000007;
      long long w = ((1 << n) - 1) ^ st;
      for (long long u = w; u; u = (u - 1) & w) {
        long long to = st | u, r = 1;
        for (long long j = 1; j <= n; ++j)
          if ((u >> j - 1) & 1) r = r * g[st][j] % 1000000007;
        f[to] = (f[to] + r * f[st] % 1000000007 * h[u]) % 1000000007;
        if (!u) break;
      }
    }
    ans += f[(1 << n) - 1];
  }
  printf("%lld\n", ans % 1000000007);
  return 0;
}
