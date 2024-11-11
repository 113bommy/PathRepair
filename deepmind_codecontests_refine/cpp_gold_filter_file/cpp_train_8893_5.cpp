#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;
const int maxn = (int)1e5 + 13;
const long long INFL = 9223372036854775807;
const int INF = 2147483646;
const long long MOD = 1e9 + 7;
const long long base = 31;
long long sum(long long a, long long b) { return (a + b) % MOD; }
long long dp[maxn][2];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n, k, d;
  cin >> n >> k >> d;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= d - 1; ++j) {
      if (i >= j) dp[i][0] = sum(dp[i - j][0], dp[i][0]);
    }
    for (int j = d; j <= k; ++j) {
      if (i >= j) dp[i][1] = sum(dp[i - j][0], dp[i][1]);
    }
    for (int j = 1; j <= k; ++j) {
      if (i >= j) dp[i][1] = sum(dp[i - j][1], dp[i][1]);
    }
  }
  cout << dp[n][1] << "\n";
  return 0;
}
