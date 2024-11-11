#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int dp[N][N][11][2];
int a[N];
int main() {
  int l1, l2, K;
  char s1[N], s2[N];
  cin >> l1 >> l2 >> K;
  cin >> s1 >> s2;
  int ans = -1;
  for (int i = 1; i <= l1; i++) {
    for (int j = 1; j <= l2; j++) {
      for (int k = 1; k <= K; k++) {
        for (int l = 0; l < 2; l++) {
          dp[i][j][k][0] = max(dp[i][j][k][0], dp[i][j - 1][k][l]);
          dp[i][j][k][0] = max(dp[i][j][k][0], dp[i - 1][j][k][l]);
          if (s1[i - 1] == s2[j - 1]) {
            if (l)
              dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j - 1][k][l] + 1);
            dp[i][j][k][1] =
                max(dp[i][j][k][1], dp[i - 1][j - 1][k - 1][l] + 1);
          }
        }
        dp[i][j][k][0] = max(dp[i][j][k][1], dp[i][j][k][0]);
      }
      ans = max(ans, dp[i][j][K][0]);
    }
  }
  cout << ans << endl;
}
