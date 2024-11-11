#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MOD = 1e9 + 7;
int n, d, k, dp[MAXN][MAXN];
int solve(int sum, int sat) {
  if (sum > n) return 0;
  if (sum == n) return sat;
  if (dp[sum][sat] >= 0) return dp[sum][sat];
  int &ans = dp[sum][sat] = 0;
  for (int i = 1; i <= k; ++i) (ans += solve(sum + i, sat | (i >= d))) %= MOD;
  return ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> k >> d;
  cout << solve(0, 0);
  return 0;
}
