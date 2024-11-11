#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 5;
const long long MOD = 1e9 + 7;
long long n, k;
long long a[MAXN], sum;
long long fac[MAXN], inv[MAXN];
inline long long qpow(long long x, long long y) {
  long long sum = 1;
  while (y > 1) {
    if (y % 2 == 0)
      x = x * x % MOD;
    else
      sum *= x, sum %= MOD, x = x * x % MOD;
    y >>= 1;
  }
  return x * sum % MOD;
}
inline long long stl(long long x, long long y) {
  long long cnt = 0;
  for (register long long i = 0; i <= y; i++)
    cnt = (cnt + ((i & 1) ? MOD - 1 : 1) * inv[i] % MOD * qpow(y - i, x) % MOD *
                     inv[y - i] % MOD) %
          MOD;
  return cnt;
}
signed main() {
  scanf("%lld%lld", &n, &k);
  for (register long long i = 1; i <= n; i++)
    scanf("%lld", &a[i]), sum = (sum + a[i]) % MOD;
  fac[0] = 1;
  for (register long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
  inv[n] = qpow(fac[n], MOD - 2);
  for (register long long i = n - 1; i >= 0; i--)
    inv[i] = inv[i + 1] * (i + 1) % MOD;
  printf("%lld", sum * (stl(n, k) + (n - 1) * stl(n - 1, k) % MOD) % MOD);
  return 0;
}
