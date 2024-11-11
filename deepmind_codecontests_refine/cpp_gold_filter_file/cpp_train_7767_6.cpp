#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[55];
int dp[55][2];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dp[n][0] = a[n];
  for (int i = n - 1; i > 0; --i) {
    dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + a[i]);
    dp[i][1] = min(dp[i + 1][0], dp[i + 1][1] + a[i]);
  }
  cout << dp[1][1] << " " << dp[1][0];
  return 0;
}
