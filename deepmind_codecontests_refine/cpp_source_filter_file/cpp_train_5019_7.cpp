#include <bits/stdc++.h>
using namespace std;
const long long N = 1000010;
const long long inf = 1e9;
const long long mod = 998244353;
inline long long read() {
  long long p = 0;
  long long f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    p = p * 10 + ch - '0';
    ch = getchar();
  }
  return p * f;
}
long long qpow(long long x, long long k, long long mo) {
  long long s = 1;
  while (k) {
    if (k & 1) s = s * x % mo;
    x = x * x % mo;
    k >>= 1;
  }
  return s;
}
long long n, m, k, S[5010][5010];
int main() {
  n = read();
  m = read();
  k = read();
  S[0][0] = 1;
  S[1][0] = 0;
  for (long long i = 1; i <= k; i++)
    for (long long j = 0; j <= k; j++) {
      if (j == 0)
        S[i][j] = 0;
      else
        S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j % mod) % mod;
    }
  long long s = 1;
  long long ans = 0;
  long long mb = qpow(m, n, mod);
  long long invm = qpow(m, mod - 2, mod);
  for (long long j = 0; j <= min(n, k); j++) {
    ans = (ans + S[k][j] * s % mod * mb % mod);
    mb = mb * invm % mod, s = s * (n - j) % mod;
  }
  return printf("%lld\n", ans * qpow(qpow(m, n, mod), mod - 2, mod) % mod), 0;
}
