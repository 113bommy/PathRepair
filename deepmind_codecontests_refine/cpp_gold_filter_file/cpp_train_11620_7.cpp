#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int a[300], b[300], dp[2][300][5210];
int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    while (x % 5 == 0) {
      a[i]++;
      x /= 5;
    }
    while (x % 2 == 0) {
      b[i]++;
      x /= 2;
    }
  }
  for (int j = 0; j <= k; j++) {
    for (int l = 0; l <= 5200; l++) dp[0][j][l] = dp[1][j][l] = -inf;
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l <= 5200; l++) {
        dp[(i + 1) % 2][j][l] = max(dp[(i + 1) % 2][j][l], dp[i % 2][j][l]);
        int x = l + a[i];
        dp[(i + 1) % 2][j + 1][x] =
            max(dp[(i + 1) % 2][j + 1][x], b[i] + dp[i % 2][j][l]);
      }
    }
  }
  for (int i = 0; i <= 5200; i++) ans = max(ans, min(i, dp[n % 2][k][i]));
  cout << ans;
  return 0;
}
