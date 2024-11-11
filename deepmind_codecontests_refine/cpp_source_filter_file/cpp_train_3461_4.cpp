#include <bits/stdc++.h>
using namespace std;
long long m = 998244353;
long long fact[1000000 + 1];
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInverse(long long b) {
  long long x, y;
  long long g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
long long modDivide(long long a, long long b) {
  a = a % m;
  long long inv = modInverse(b);
  return (inv * a) % m;
}
long long calc(long long n, long long k) {
  if (n < k) return 0;
  long long y = (fact[n - k] * fact[k]) % m;
  long long x = modDivide(fact[n], y);
  return x;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  fact[0] = 1;
  for (long long i = 1; i < n + 1; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= m;
  }
  for (long long i = 1; i < n; i++) {
    long long d = n / i;
    ans += calc(d - 1, k - 1);
    ans %= m;
  }
  cout << ans;
}
