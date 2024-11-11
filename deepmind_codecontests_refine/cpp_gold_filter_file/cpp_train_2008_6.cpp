#include <bits/stdc++.h>
using namespace std;
long long int fac[300005];
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int m = 998244353;
  fac[0] = 1;
  for (int i = 1; i < 300005; i++) fac[i] = (fac[i - 1] * i) % m;
  int n;
  cin >> n;
  int a[2 * n];
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a, a + 2 * n);
  long long int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i < n)
      sum1 += a[i];
    else
      sum2 += a[i];
  }
  long long int ans = nCrModPFermat(2 * n, n, m);
  ans *= (sum2 - sum1) % m;
  ans %= m;
  cout << ans << "\n";
  return 0;
}
