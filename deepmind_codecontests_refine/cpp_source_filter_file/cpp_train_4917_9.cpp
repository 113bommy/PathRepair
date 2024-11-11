#include <bits/stdc++.h>
using namespace std;
long long int dp[505][505][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int x = 0; x < n; x++) cin >> a[x];
    memset(dp, 0, sizeof(dp));
    for (int x = 0; x < n; x++) {
      dp[x][x][0] = a[x];
      dp[x][x][1] = a[x];
      dp[x][x][2] = 1;
    }
    for (int x = 1; x < n; x++) {
      for (int y = 0; y < n - x; y++) {
        long long int l = y;
        long long int r = y + x;
        dp[l][r][0] = a[l];
        dp[l][r][1] = a[r];
        dp[l][r][2] = r - l + 1;
        for (int z = l; z < r; z++) {
          if (dp[l][z][1] == dp[z + 1][r][0]) {
            if (dp[l][r][2] >= (dp[l][z][2] + dp[z + 1][r][2] - 1)) {
              long long int i = 0;
              if (dp[l][z][2] == 1) i = 1;
              dp[l][r][0] = dp[l][z][0] + i;
              i = 0;
              if (dp[z + 1][r][2] == 0) i = 1;
              dp[l][r][1] = dp[z + 1][r][1] + i;
              dp[l][r][2] = dp[l][z][2] + dp[z + 1][r][2] - 1;
            }
          } else {
            if (dp[l][r][2] >= (dp[l][z][2] + dp[z + 1][r][2])) {
              dp[l][r][0] = dp[l][z][0];
              dp[l][r][1] = dp[z + 1][r][1];
              dp[l][r][2] = dp[l][z][2] + dp[z + 1][r][2];
            }
          }
        }
      }
    }
    cout << dp[0][n - 1][2];
  }
}
