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
long long n, k, m;
long long a[46];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k >> m;
  for (long long i = 0; i < k; i++) {
    cin >> a[i];
  }
  sort(a, a + k);
  long long ans = 0, sum = 0;
  for (long long i = 0; i < k; i++) {
    sum += a[i];
  }
  for (long long i = 0; i <= n; i++) {
    long long t = sum * i;
    if (t > m) {
      break;
    } else {
      long long T = m - t;
      long long cur = (k + 1) * i;
      for (long long j = 0; j < k; j++) {
        for (long long k = i + 1; k <= n; k++) {
          if (T >= a[j]) {
            cur++;
            T -= a[j];
          }
        }
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
