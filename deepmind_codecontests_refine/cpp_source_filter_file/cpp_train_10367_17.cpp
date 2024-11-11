#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
const long long mod = 1000000007;
long long fact[N], inv_fact[N], f, w, h;
long long binPow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
long long C(long long k, long long n) {
  if (k > n) return 0;
  long long ans = 1;
  ans *= fact[n];
  ans %= mod;
  ans *= inv_fact[k];
  ans %= mod;
  ans *= inv_fact[n - k];
  ans %= mod;
  return ans;
}
signed main() {
  fact[0] = inv_fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
    inv_fact[i] = binPow(fact[i], mod - 2);
  }
  scanf("%lld %lld %lld", &f, &w, &h);
  if (h == 0) return !printf("%d", 0);
  long long ans = 0;
  h++;
  for (long long i = 1; i <= w / h; i++) {
    long long res = (1LL * C(i, f + 1) * C(i - 1, w - h * i + i - 1)) % mod;
    ans = (ans + res) % mod;
  }
  if (w == 0) ans = 1;
  if (f == 0) ans = (w >= h);
  ans = (ans * binPow(C(f, f + w), mod - 2)) % mod;
  printf("%lld", ans);
  return 0;
}
