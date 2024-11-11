#include <bits/stdc++.h>
using namespace std;
long long int dp[101][2];
long long int n, k, d;
long long int solve(long long int sum, long long int chk) {
  if (sum > n) return 0;
  if (sum == n) {
    if (chk) return 1;
    return 0;
  }
  if (dp[sum][chk] != -1) return dp[sum][chk];
  long long int ans = 0;
  for (long long int i = 1; i < k + 1; i++) {
    if (i >= d)
      ans = (ans + solve(sum + i, 1)) % 1000000007;
    else
      ans = (ans + solve(sum + i, 0)) % 1000000007;
  }
  return dp[sum][chk] = ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> d;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0);
}
