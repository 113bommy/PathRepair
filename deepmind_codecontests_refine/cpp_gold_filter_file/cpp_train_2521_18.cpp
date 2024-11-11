#include <bits/stdc++.h>
const long long N = 1e6 + 10;
const long long M = 100000;
const long long mod = 1e9 + 7;
using namespace std;
long long dpx[1005][1005];
long long ax[2005];
long long bx[2005];
long long add(long long a, long long b) { return ((a % mod + b % mod) % mod); }
long long sub(long long a, long long b) {
  return ((a % mod - b % mod + mod) % mod);
}
long long mul(long long a, long long b) {
  return (((a % mod) * (b % mod)) % mod);
}
long long dp[100017];
long long power(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return ans;
}
long long ncr(long long n, long long r) {
  long long x = 1, y = 1, z = 1;
  for (long long i = 1; i <= n; i++) {
    x = (x * i) % mod;
    if (i <= r) y = (y * i) % mod;
    if (i <= n - r) z = (z * i) % mod;
  }
  z = (z * y) % mod;
  long long ans = (x * power(z, mod - 2)) % mod;
  return ans;
}
int32_t main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (2 * k >= n or 2 * k >= m) return cout << 0, 0;
  cout << mul(ncr(n - 1, 2 * k), ncr(m - 1, 2 * k)) % mod;
  return 0;
}
