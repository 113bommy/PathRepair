#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000005;
const long long dd = (long long)(1e9) + 7;
long long n, q;
long long dp[maxn * 3][3], sum[maxn], isum[maxn];
inline long long read() {
  long long ret = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
inline long long qpow(long long x, long long p) {
  long long ans = 1;
  if (x == 0) return 0;
  while (p) {
    if (p & 1) ans = ans * x % dd;
    x = x * x % dd;
    p >>= 1;
  }
  return ans % dd;
}
inline long long inv(long long x) { return qpow(x, dd - 2) % dd; }
inline long long mod1(long long x) { return x >= dd ? x - dd : x; }
inline long long mod2(long long x) { return x < 0 ? x + dd : x; }
signed main() {
  n = read() * 3;
  q = read();
  isum[0] = sum[0] = 1;
  for (long long k = 1; k <= n + 2; k++) sum[k] = sum[k - 1] * k % dd;
  isum[n + 2] = inv(sum[n + 2]);
  for (long long k = n + 1; k; k--) isum[k] = isum[k + 1] * (k + 1) % dd;
  dp[n][0] = sum[n];
  for (long long k = n - 1; k; k--) {
    long long ix = sum[k] * isum[k + 1] % dd;
    dp[k][0] = mod2(mod1(sum[n + 1] * isum[n - k] % dd + dp[k + 1][1]) -
                    dp[k + 1][0]) *
               ix % dd;
    dp[k][1] = mod2(dp[k + 1][2] - dp[k + 1][1]) * ix % dd;
    dp[k][2] = mod2(dp[k + 1][0] - dp[k + 1][2]) * ix % dd;
  }
  for (long long k = 1; k <= q; k++) {
    long long x = read();
    printf("%lld\n", dp[x][0] * isum[x] % dd);
  }
  return 0;
}
