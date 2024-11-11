#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, k;
  cin >> n >> k;
  std::vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long dp[k + 1][n];
  for (long long i = 0; i < n; i++) {
    dp[0][i] = 0;
  }
  for (long long i = 0; i <= k; i++) {
    dp[i][0] = 0;
  }
  long long mx;
  for (int kk = 1; kk <= k; kk++) {
    mx = -1LL * LONG_LONG_MAX;
    for (int j = 1; j < n; j++) {
      mx = max(mx, dp[kk - 1][j - 1] - v[j - 1]);
      dp[kk][j] = max(dp[kk][j - 1], mx + v[j]);
    }
  }
  cout << dp[k][n - 1] << endl;
  return 0;
}
