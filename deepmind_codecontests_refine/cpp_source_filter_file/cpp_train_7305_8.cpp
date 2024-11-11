#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    unsigned long long int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    unsigned long long int dp[n + 2][2];
    for (int i = 0; i <= n + 1; i++) {
      dp[i][0] = dp[i][1] = (unsigned long long int)INT_MAX * 10;
    }
    dp[0][0] = b;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a + b);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2 * a + 2 * b);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a + 2 * b);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a * 2 + b);
      } else {
        dp[i + 1][1] = min(dp[i + 1][1], a + 2 * b + dp[i][1]);
      }
    }
    cout << dp[n][0] << endl;
  }
}
