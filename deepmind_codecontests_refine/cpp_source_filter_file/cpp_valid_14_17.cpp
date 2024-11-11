#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e3 + 10;
long long dp[N][N];
long long n, k;
long long A[N];
long long dfs(long long i, long long removed) {
  if (removed < 0) {
    return -MOD;
  }
  if (i == 0) {
    return removed == 0 ? 0 : -MOD;
  }
  long long &ans = dp[i][removed];
  if (ans != -1) {
    return ans;
  }
  ans = dfs(i - 1, removed) + (A[i] == i - removed);
  ans = max(ans, dfs(i - 1, removed - 1));
  return ans;
}
void Perform() {
  cin >> n >> k;
  for (long long i = 0; i <= n; ++i) {
    for (long long j = 0; j <= k; ++j) {
      dp[i][j] = -1;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  for (long long i = 0; i <= n; ++i) {
    if (dfs(n, i) >= k) {
      cout << i << "\n";
      return;
    }
  }
  cout << "-1\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    Perform();
  }
  return 0;
}
