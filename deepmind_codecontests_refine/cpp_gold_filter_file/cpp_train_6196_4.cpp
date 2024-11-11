#include <bits/stdc++.h>
using namespace std;
long long n, a[505], dp[505][505];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], dp[i][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int l = 1; l + i - 1 <= n; l++) {
      long long r = l + i - 1;
      dp[l][r] = dp[l + 1][r] + 1;
      for (int k = l + 1; k <= r; k++) {
        if (a[l] == a[k])
          if (k - l > 2)
            dp[l][r] = min(dp[l][r], dp[l + 1][k - 1] + dp[k + 1][r]);
          else
            dp[l][r] = min(dp[l][r], dp[k + 1][r] + 1);
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}
