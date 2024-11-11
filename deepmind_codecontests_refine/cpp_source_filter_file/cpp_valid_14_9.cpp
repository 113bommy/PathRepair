#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++) cin >> a[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    long long ma = 0;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j <= n; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (a[i] == i - j) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
        if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
    for (long long j = 0; j <= n; j++)
      if (dp[n][j] >= k) {
        ma = j;
        break;
      }
    if (ma == 0)
      cout << "-1\n";
    else
      cout << ma << '\n';
  }
  return 0;
}
