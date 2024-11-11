#include <bits/stdc++.h>
const long long M = 1e9 + 7;
using namespace std;
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long res = 1;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % 1000000007;
    }
    x = x * x % 1000000007;
    y /= 2;
  }
  return res;
}
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long dp[205][404];
long long a[205];
long long n;
long long sol(long long i, long long k) {
  if (i == n) return 0;
  if (k == 2 * n + 1) return 1000000007;
  if (dp[i][k] != -1) return dp[i][k];
  long long ans = 1000000007;
  ans = min(ans, sol(i, k + 1));
  ans = min(ans, abs(a[i] - k) + sol(i + 1, k + 1));
  return dp[i][k] = ans;
}
void solve() {
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << sol(0, 1) << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
