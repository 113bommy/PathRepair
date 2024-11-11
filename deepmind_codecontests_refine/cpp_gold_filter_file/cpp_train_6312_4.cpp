#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powll(long long x, long long y) {
  long long res = 1LL;
  while (y) {
    if (y & 1LL) res *= x;
    res %= mod;
    x = (x * x) % mod;
    y >>= 1LL;
  }
  return res;
}
int main() {
  long long x, y;
  cin >> x >> y;
  if (y % x) {
    cout << 0 << endl;
    return 0;
  }
  y /= x;
  long long s = y;
  vector<long long> primes;
  for (int a = 2; a <= 100000; ++a) {
    if (s % a) continue;
    primes.push_back(a);
    while (s % a == 0) s /= a;
  }
  if (s > 1) primes.push_back(s);
  int n = primes.size();
  long long ans = 0;
  for (int mask = 0; mask < 1 << n; ++mask) {
    int c = 0;
    for (int i = 0; i < n; ++i) c += ((mask >> i) & 1);
    long long prod = 1;
    for (int i = 0; i < n; ++i)
      if ((mask >> i) & 1) prod *= primes[i];
    long long tmp = powll(2, y / prod - 1);
    if (c % 2 == 0)
      ans = (ans + tmp) % mod;
    else
      ans = (ans - tmp + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
