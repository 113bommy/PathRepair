#include <bits/stdc++.h>
using namespace std;
long long res[200000] = {0};
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCrModPFermat(long long n, long long r, long long p) {
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (n == 2) {
    cout << 0;
    return 0;
  }
  long long p = 998244353;
  long long ans, z, y;
  ans = nCrModPFermat(m, n - 1, p);
  z = (n - 2) % p;
  ans = ans * z;
  ans = ans % p;
  y = power(2, n - 3, p);
  ans = ans * y;
  ans = ans % 998244353;
  cout << ans << endl;
}
