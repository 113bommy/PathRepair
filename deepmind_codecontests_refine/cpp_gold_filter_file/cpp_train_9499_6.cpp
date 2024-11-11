#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353, N = 5005;
long long n, f[N][N], ans[N], fac[N], inv[N];
inline long long C(long long x, long long y) {
  return fac[x] * inv[y] % M * inv[x - y] % M;
}
inline long long ksm(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % M)
    if (y & 1) (ans *= x) %= M;
  return ans;
}
signed main() {
  fac[0] = inv[0] = 1;
  for (long long i = 1; i < N; i++)
    fac[i] = fac[i - 1] * i % M, inv[i] = ksm(fac[i], M - 2);
  scanf("%lld", &n);
  f[0][0] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= i; j++) {
      f[i][j] = (j * f[i - 1][j] + (i - j + 1) * f[i - 1][j - 1]) % M;
      ans[j] = (ans[j] + f[i][j] * C(n, i) % M * fac[n - i]) % M;
    }
  for (long long i = 1; i <= n; i++) printf("%lld ", ans[i]);
}
