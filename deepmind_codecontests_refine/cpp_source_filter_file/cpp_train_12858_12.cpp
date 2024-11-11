#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long cal(long long n, long long x, long long y) {
  long long st = n % y, ed = n % x;
  long long tot = y - x + 1;
  tot %= mod;
  st = (st + ed) % mod;
  return tot * st % mod * (mod + 1) / 2 % mod;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  if (n < m) {
    ans = (m - n) % n * (n % mod) % mod;
    m = n;
  }
  for (long long i = 1; i <= m;) {
    long long d = n / i, j = min(m, n / d);
    ans += cal(n, i, j);
    i = j + 1;
  }
  cout << ans % mod << endl;
  return 0;
}
