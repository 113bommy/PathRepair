#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long fac[1000100], ifac[1000100];
long long pw1[1000100], pw2[1000100];
long long n, m;
long long Pow(long long x, long long y) {
  if (y == 0) return 1;
  long long res = Pow(x, y >> 1);
  res = res * res % mod;
  if (y & 1) res = res * x % mod;
  return res;
}
long long C(long long x, long long y) {
  return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main() {
  cin >> n >> m;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
    ifac[i] = Pow(fac[i], mod - 2);
  }
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw1[i] = pw1[i - 1] * m % mod;
    pw2[i] = pw2[i - 1] * (m - 1) % mod;
  }
  long long ans = Pow(m, n);
  for (int i = 1; i <= n; i++) {
    long long cur = pw2[n - i] * pw1[i] % mod * C(n, i - 1) % mod;
    ans = (ans + cur) % mod;
  }
  cout << ans << endl;
  return 0;
}
