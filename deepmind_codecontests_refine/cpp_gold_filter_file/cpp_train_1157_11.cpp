#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
long long power(long long x, long long y, long long mod = 2e18) {
  long long ans = 1;
  x %= mod;
  while (y) {
    if (y & 1) ans = (x * ans) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 1e18;
  for (long long i = 1; i <= 100; i++) {
    long long ct = 0;
    for (long long j = 1; j <= n; j++) {
      ct += (abs(j - i) + i + j - 2) * 2 * a[j - 1];
    }
    ans = min(ans, ct);
  }
  cout << ans;
  return 0;
}
