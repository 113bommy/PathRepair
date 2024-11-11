#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int n = 100001;
int m;
long long a[n], dp[n];
long long ipow(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x] = y;
  }
  for (int i = n - 1; i; i--) {
    long long k = 0, x = 0, y = 0;
    for (int j = i; j < n; j += i) {
      k += a[j];
      (x += a[j] * j) %= mod;
      (y += a[j] * j % mod * j) %= mod;
      (dp[i] += mod - dp[j]) %= mod;
    }
    if (k < 2) continue;
    long long p = ipow(2, (mod + k - 4) % (mod - 1));
    k %= mod;
    (dp[i] += 2 * p * (mod + k - 1) % mod * y) %= mod;
    (dp[i] += p * k % mod * (mod + x * x % mod - y)) %= mod;
  }
  cout << dp[1] << '\n';
  return 0;
}
