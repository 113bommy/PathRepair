#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a, long long n, long long MOD) {
  long long res = 1;
  long long tmp = a;
  while (n) {
    if (n & 1) {
      res = res * tmp % MOD;
    }
    tmp = tmp * tmp % MOD;
    n >>= 1;
  }
  return res;
}
long long inv(long long a, long long MOD) { return qpow(a, MOD - 2, MOD); }
int main() {
  long long a, b, p, x;
  cin >> a >> b >> p >> x;
  long long ans = 0;
  for (long long i = 1; i < p; i++) {
    long long t = b * inv(qpow(a, i, p), p) % p;
    long long n = i + (p - 1) * ((i - t + p) % p);
    ans += x / (p * (p - 1)) + (x % (p * (p - 1))) >= n ? 1 : 0;
  }
  cout << ans << endl;
  return 0;
}
