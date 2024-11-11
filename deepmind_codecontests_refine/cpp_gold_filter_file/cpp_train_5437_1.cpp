#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[1005][15];
long long fac[3005];
long long q_pow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long C(long long n, long long m) {
  if (m > n) return 0;
  return (fac[n] * q_pow(fac[m], mod - 2) % mod * q_pow(fac[n - m], mod - 2) %
          mod) %
         mod;
}
void init() {
  fac[0] = 1;
  for (long long i = 1; i <= 3000; i++) fac[i] = fac[i - 1] * i % mod;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  init();
  long long ans = C(2 * m + n - 1, n - 1);
  cout << ans << endl;
}
