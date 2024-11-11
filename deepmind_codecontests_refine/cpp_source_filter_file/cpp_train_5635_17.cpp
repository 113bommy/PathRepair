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
  long long t;
  cin >> t;
  cout << setprecision(20);
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (n >= 32) {
      cout << "YES " << 0 << endl;
      continue;
    }
    long long total = (pow(4, n) - 1) / 3;
    if (k > total) {
      cout << "NO" << endl;
      continue;
    }
    long long left;
    bool first = 0;
    for (long long i = n; i >= 1; i--) {
      left = pow(2, i + 1) - (i + 2);
      long long curr = (2 * (i) + 1) * (pow(4, n - i) / 3);
      if (total - curr >= k && k >= left) {
        cout << "YES " << n - i << endl;
        first = 1;
        break;
      }
    }
    if (!first) cout << "NO\n";
  }
  return 0;
}
