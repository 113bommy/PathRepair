#include <bits/stdc++.h>
using namespace std;
string s, t;
long long dp[100005][4];
int main() {
  int n;
  while (cin >> n) {
    cin >> s;
    cin >> t;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 4; j++) {
        if (s[i] == '?' && t[i] == '?') {
          for (int k = '0'; k <= '9'; k++) {
            for (int l = '0'; l <= '9'; l++) {
              if (k > l)
                dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j]) % 1000000007;
              else if (k == l)
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % 1000000007;
              else
                dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j]) % 1000000007;
            }
          }
        } else if (s[i] == '?' && t[i] != '?') {
          for (int k = '0'; k <= '9'; k++) {
            if (k > t[i])
              dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j]) % 1000000007;
            else if (k == t[i])
              dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % 1000000007;
            else
              dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j]) % 1000000007;
          }
        } else if (s[i] != '?' && t[i] == '?') {
          for (int k = '0'; k <= '9'; k++) {
            if (s[i] > k)
              dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j]) % 1000000007;
            else if (s[i] == k)
              dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % 1000000007;
            else
              dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j]) % 1000000007;
          }
        } else {
          if (s[i] > t[i])
            dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j]) % 1000000007;
          else if (s[i] == t[i])
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % 1000000007;
          else
            dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j]) % 1000000007;
        }
      }
    }
    cout << dp[n][3] << endl;
  }
}
