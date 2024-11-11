#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6;
const long long mod = 1e9 + 7;
const long double PI = 4 * atan((long double)1);
long long pw(long long a, long long b) {
  return (!b ? 1
             : (b & 1 ? a * pw(a * a % mod, b / 2) % mod
                      : pw(a * a % mod, b / 2) % mod));
}
int n, a[maxn];
long long dp[1000][31000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][10000] = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = -20000; j <= 20000; j++) {
      dp[i][j + 10000] =
          ((dp[i - 1][j + a[i] + 10000] + dp[i - 1][j - a[i] + 10000])) % mod;
    }
    ans += dp[i][10000];
    dp[i][10000]++;
    ans %= mod;
  }
  cout << ans;
  return (0);
}
