#include <bits/stdc++.h>
using namespace std;
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
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long int log2_32bit(long long int x) {
  long long int res = 0;
  while (x >>= 1) res++;
  return res;
}
long long int isPowerof2(long long int x) { return (x && !(x & x - 1)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    ;
    long long int b[n];
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    long long int ans = 1000000007;
    long long int pre[n - 1];
    pre[0] = b[0];
    for (int i = 1; i < n - 1; i++) {
      pre[i] = pre[i - 1] + b[i];
    }
    long long int suf[n - 1];
    suf[n - 2] = a[n - 1];
    for (int i = n - 2; i >= 1; i--) {
      suf[i - 1] = suf[i] + a[i];
    }
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        ans = min(ans, suf[i]);
      } else if (i == n) {
        ans = min(ans, pre[i - 1]);
      } else {
        ans = min(ans, max(suf[i], pre[i - 1]));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
