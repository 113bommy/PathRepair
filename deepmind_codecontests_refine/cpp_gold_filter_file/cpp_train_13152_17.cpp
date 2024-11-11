#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> dp(n + 1);
  dp[0] = 0;
  int arr[3] = {a, b, c};
  for (int i = 1; i < n; i++) {
    dp[i] = INT_MIN;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      if ((i - arr[j]) >= 0) {
        dp[i] = max(dp[i - arr[j]] + 1, dp[i]);
      }
    }
  }
  cout << dp[n];
}
