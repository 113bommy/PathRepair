#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100, mod = 1e9 + 7, maxa = 1e6 + 100, maxb = 23,
          maxs = 340;
const long long inf = 2e18 + 13;
long long max(long long x, long long y) { return (x > y ? x : y); }
long long min(long long x, long long y) { return (x < y ? x : y); }
long long dp[maxn][2];
long long a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = inf;
  if (n == 1) {
    cout << a[1] - 1;
    return 0;
  }
  dp[1][0] = 1;
  if (a[2] >= a[1]) {
    dp[1][1] = a[1] - 1;
  } else {
    dp[1][0] = a[1] - a[2];
    dp[1][1] = a[2] - 1;
  }
  for (int i = 2; i <= n; i++) {
    dp[i][0] += (dp[i - 1][0] + dp[i - 1][1]) % mod;
    if (a[i + 1] < a[i]) {
      dp[i][0] += (a[i] - a[i + 1]) % mod;
      dp[i][1] += (a[i + 1] - 1) % mod;
      if (a[i - 1] >= a[i]) {
        dp[i][0] += (a[i] - a[i + 1]) * dp[i - 1][1] % mod;
        dp[i][1] += (a[i + 1] - 1) * dp[i - 1][1] % mod;
      }
      if (a[i - 1] < a[i] && a[i - 1] >= a[i + 1]) {
        dp[i][0] += (a[i - 1] - a[i + 1]) * dp[i - 1][1] % mod;
        dp[i][1] += (a[i + 1] - 1) * dp[i - 1][1] % mod;
      }
      if (a[i - 1] < a[i] && a[i - 1] < a[i + 1]) {
        dp[i][1] += (a[i - 1] - 1) * dp[i - 1][1] % mod;
      }
    }
    if (a[i + 1] >= a[i]) {
      dp[i][1] += (a[i] - 1) % mod;
      if (a[i - 1] >= a[i]) {
        dp[i][1] += (a[i] - 1) * dp[i - 1][1] % mod;
      } else {
        dp[i][1] += (a[i - 1] - 1) * dp[i - 1][1] % mod;
      }
    }
  }
  cout << ((dp[n][1] + dp[n][0] - 1) + mod) % mod;
  return 0;
}
