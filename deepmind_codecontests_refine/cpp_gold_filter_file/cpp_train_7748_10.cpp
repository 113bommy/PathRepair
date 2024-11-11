#include <bits/stdc++.h>
using namespace std;
int const m = 1000000007;
int n, k, dp[2000][2001], sumdp[2000][2000];
int main() {
  cin >> n >> k;
  int x = 0;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = 1;
  }
  for (int i = 1; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int l = 2; l * l <= j; l++) {
        if (j % l == 0) {
          x = j;
          while (x % l == 0) {
            x = x / l;
          }
          dp[i][j] = (dp[i][j] + dp[i - 1][l]) % m;
          if (j / l != l) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j / l]) % m;
          }
        }
      }
      dp[i][j] = (dp[i][j] + dp[i - 1][j]) % m;
      if (j != 1) {
        dp[i][j] = (dp[i][j] + dp[i - 1][1]) % m;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = (sum + dp[k - 1][i]) % m;
  }
  cout << sum;
}
