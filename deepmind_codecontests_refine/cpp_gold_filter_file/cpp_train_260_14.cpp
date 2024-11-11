#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx,avx2")
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const long long N = 25, M = 1e5 + 5, S = 1 << 21;
long long a[S], b[S], ans = 1e9, n, m, mp[N][M];
void fwtxor(long long *f, long long n, long long op) {
  for (long long len = 2, k = 1; k < n; len <<= 1, k <<= 1)
    for (long long i = 0; i < n; i += len)
      for (long long j = 0; j < k; j++) {
        long long x = f[i + j], y = f[i + j + k];
        f[i + j] = x + y;
        f[i + j + k] = x - y;
        if (op == -1) f[i + j] >>= 1, f[i + j + k] >>= 1;
      }
}
signed main() {
  read(n, m);
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) scanf("%1d", &mp[i][j]);
  for (long long i = 0; i < m; i++) {
    long long s = 0;
    for (long long j = 0; j < n; j++) s |= mp[j][i] << j;
    a[s]++;
  }
  for (long long i = 0; i < (1 << n); i++) {
    long long cnt = 0;
    for (long long j = 0; j < n; j++) cnt += i >> j & 1;
    b[i] = min(cnt, n - cnt);
  }
  fwtxor(a, 1 << n, 1);
  fwtxor(b, 1 << n, 1);
  for (long long i = 0; i < (1 << n); i++) a[i] = a[i] * b[i];
  fwtxor(a, 1 << n, -1);
  for (long long i = 0; i < (1 << n); i++) ans = min(ans, a[i]);
  write(ans);
}
