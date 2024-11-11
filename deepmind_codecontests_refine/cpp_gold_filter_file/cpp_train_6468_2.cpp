#include <bits/stdc++.h>
using namespace std;
const int ms = 111;
long long dp[ms][ms][ms];
int a[ms];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = n - 1; i > -1; i--) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = 0; k < n; k++) {
        dp[i][j][k] = a[k] + dp[i + 1][j][0];
        for (int l = i + 1; l < j; l++) {
          if (s[i] == s[l])
            dp[i][j][k] = max(dp[i][j][k], dp[i + 1][l][0] + dp[l][j][k + 1]);
        }
      }
    }
  }
  cout << dp[0][n][0] << endl;
}
