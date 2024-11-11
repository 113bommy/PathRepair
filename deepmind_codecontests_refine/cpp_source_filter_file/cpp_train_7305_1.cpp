#include <bits/stdc++.h>
using namespace std;
long long int dp[200010][2];
long long int llmax = 1000000000000000;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, a, b;
    cin >> n >> a >> b;
    string r;
    cin >> r;
    dp[0][0] = a + b;
    dp[0][1] = (2 * a) + b;
    for (int j = 1; j < n + 1; j++) {
      dp[j][0] = llmax;
      dp[j][1] = llmax;
    }
    for (int j = 1; j <= n; j++) {
      if (j == n) {
        dp[j][0] = min(dp[j][0], dp[j - 1][0] + b);
        dp[j][0] = min(dp[j][0], dp[j - 1][1] + a + b);
      } else {
        if (r[j] == '0') {
          if (r[j - 1] == '0') {
            dp[j][0] = min(dp[j][0], dp[j - 1][0] + a + b);
            dp[j][0] = min(dp[j][0], dp[j - 1][1] + 2 * a + 2 * b);
            dp[j][1] = min(dp[j][1], dp[j - 1][0] + 2 * a + b);
            dp[j][1] = min(dp[j][1], dp[j - 1][1] + a + 2 * b);
          }
          if (r[j - 1] == '1') {
            dp[j][1] = min(dp[j][1], dp[j - 1][1] + a + 2 * b);
          }
        } else {
          if (r[j - 1] == '0') {
            dp[j][1] = min(dp[j][1], dp[j - 1][0] + 2 * a + 2 * b);
            dp[j][1] = min(dp[j][1], dp[j - 1][1] + a + 2 * b);
          }
          if (r[j - 1] == '1') {
            dp[j][1] = min(dp[j][1], dp[j - 1][1] + a + 2 * b);
          }
        }
      }
    }
    cout << dp[n][0] << endl;
  }
}
