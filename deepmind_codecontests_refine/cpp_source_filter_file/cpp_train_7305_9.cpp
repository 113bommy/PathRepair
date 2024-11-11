#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    int A[n];
    for (int i = 0; i < (int)n; i++) scanf("%1d", &A[i]);
    long long dp[n][2];
    if (A[1] == 1) {
      dp[0][0] = (long long)1e12;
    } else {
      dp[0][0] = a + b;
    }
    dp[0][1] = 2 * a + b;
    for (int i = 1; i <= n - 2; i++) {
      if (A[i + 1] == 1 || A[i] == 1) {
        dp[i][0] = (long long)1e12;
        dp[i][1] = min(dp[i - 1][0] + 2 * a + b, dp[i - 1][1] + a + 2 * b);
      } else {
        dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * b + 2 * a);
        dp[i][1] = min(dp[i - 1][0] + b + 2 * a, dp[i - 1][1] + 2 * b + a);
      }
    }
    cout << min(dp[n - 2][1] + 2 * a + 3 * b, dp[n - 2][0] + a + 2 * b) << "\n";
  }
  return 0;
}
