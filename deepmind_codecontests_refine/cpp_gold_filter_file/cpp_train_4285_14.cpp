#include <bits/stdc++.h>
using namespace std;
const long long N = 100;
const long long M = 1e4;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
long long read() {
  long long s = 0;
  register bool neg = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) neg |= (c == '-');
  for (; c >= '0' && c <= '9'; s = s * 10 + (c ^ 48), c = getchar())
    ;
  s = (neg ? -s : s);
  return s;
}
long long a, b, inv[N + 5], s[N + 5];
struct mat {
  long long s[105][105], n, m;
  mat(long long _n = 0, long long _m = 0) {
    n = _n, m = _m, memset(s, 0, sizeof(s));
  }
  mat operator*(const mat &o) const {
    mat res(n, o.m);
    for (long long i = (0); i <= (n); ++i)
      for (long long j = (0); j <= (o.m); ++j)
        for (long long k = (0); k <= (m); ++k)
          (res.s[i][j] += s[i][k] * o.s[k][j] % mod) %= mod;
    return res;
  }
  void print() {
    for (long long i = 0; i <= n; ++i, puts(""))
      for (long long j = (0); j <= (m); ++j) printf("%lld ", s[i][j]);
  }
} S;
mat operator^(mat n, long long m) {
  mat res = n;
  --m;
  for (; m; m >>= 1) {
    if (m & 1) res = res * n;
    n = n * n;
  }
  return res;
}
void init() {
  inv[0] = inv[1] = 1;
  for (long long i = (2); i <= (N); ++i)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
signed main() {
  init();
  a = read();
  b = read();
  long long p[2] = {0, 0}, q = 0;
  for (long long i = (1); i <= (a); ++i) s[i] = read(), p[s[i]]++;
  S.n = p[0];
  S.m = p[0];
  for (long long i = (1); i <= (p[0]); ++i) q += s[i];
  long long tmp = inv[a] % mod * inv[a - 1] * 2 % mod;
  for (long long i = (0); i <= (min(p[1], p[0])); ++i) {
    long long sum = 0;
    if (i) S.s[i][i - 1] = i * i * tmp % mod, (sum += S.s[i][i - 1]) %= mod;
    if (i != p[0])
      S.s[i][i + 1] = (p[0] - i) * (p[1] - i) * tmp % mod,
                 (sum += S.s[i][i + 1]) %= mod;
    S.s[i][i] = (1 - sum + mod) % mod;
  }
  S = S ^ b;
  printf("%lld", S.s[q][0]);
  return 0;
}
