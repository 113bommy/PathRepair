#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long alp = 30;
const long long inf = 1e9 + 10;
const long long mod = 1e9 + 7;
const long long MX = N * 10;
const unsigned int M = 1e6 + 1;
long long a[N];
int n, k;
int ans[N];
int cnt[MX];
bool backpack[MX];
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long binpow(long long a, long long b) {
  if (a == 0) {
    return 0;
  }
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    long long c = binpow(a, b / 2);
    return c * c % mod;
  } else {
    return a * binpow(a, b - 1) % mod;
  }
}
long long fact[N];
signed main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  if (n <= k + 1) {
    int ans = 0;
    for (int q = 1; q <= n; q++) {
      ans = (ans + binpow(q, k)) % mod;
    }
    cout << ans;
    return 0;
  }
  long long x = 1;
  for (int q = 0; q <= k + 1; q++) {
    x = x * (n - q) % mod;
  }
  fact[0] = 1;
  for (int q = 1; q <= k + 1; q++) {
    fact[q] = fact[q - 1] * q % mod;
  }
  long long y1 = 0;
  long long ans = 0;
  for (int q = 0; q <= k + 1; q++) {
    y1 = (y1 + binpow(q, k)) % mod;
    int num = x * binpow((n - q), mod - 2) % mod;
    int denom = fact[q] * fact[k + 1 - q] % mod;
    denom = binpow(denom, mod - 2);
    if ((q + k) % 2 == 1) {
      ans = (ans + y1 * num % mod * denom % mod) % mod;
    } else {
      ans = (ans + mod - y1 * num % mod * denom % mod) % mod;
    }
  }
  cout << ans;
  return 0;
}
