#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e6 + 3;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if ((y & 1) == 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  if (n <= 60 && (1ll << n) <= k) return cout << "1 1", 0;
  long long powertwocommon = 0;
  for (long long i = 2; i <= k - 1; i *= 2) {
    powertwocommon += (k - 1) / i;
    powertwocommon %= (mod - 1);
  }
  long long denpow = ((n % (mod - 1)) * (k % (mod - 1))) % (mod - 1);
  denpow -= (n % (mod - 1) + powertwocommon);
  denpow += 2 * (mod - 1);
  denpow %= (mod - 1);
  long long den = power(2, denpow, mod);
  if (k >= mod + 10) return cout << den << " " << den, 0;
  long long num = 1;
  for (long long i = 1; i <= k - 1; i++) {
    long long temp = i;
    long long ct = 0;
    while (temp % 2 == 0) temp /= 2, ct++;
    num *= (power(2, (n - ct) % (mod - 1), mod) - temp + 2 * mod) % mod;
    num %= mod;
  }
  num = (den - num + mod) % mod;
  cout << num << " " << den << '\n';
}
