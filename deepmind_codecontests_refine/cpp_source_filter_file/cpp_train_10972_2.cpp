#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e+9;
long long powmod(long long r) {
  long long res = 1, p = 2;
  while (r) {
    if (r & 1) res = (res * p) % mod;
    p = (p * p) % mod;
    r >>= 1;
  }
  return res;
}
long long cal(long long p) { return (powmod(p) - 1) * 2 % mod; }
int main() {
  long long n, m, k;
  while (cin >> n >> m >> k) {
    long long c = n - m + 1;
    if (c * (k - 1) >= m)
      cout << m % mod << endl;
    else {
      long long res = (c - 1) * (k - 1);
      m -= res;
      long long p = m / k;
      res = (res + k * cal(p) % mod + m - p * k) % mod;
      cout << res << endl;
    }
  }
  return 0;
}
