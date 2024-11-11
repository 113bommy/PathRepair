#include <bits/stdc++.h>
using namespace std;
const int N = 300009;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n + 1];
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  long long int sub[n + 1][n + 1];
  sub[0][0] = a[0];
  for (int i = 1; i < n; i++) {
    for (int j = i; j < n; j++) {
      sub[i][j] = a[j] - a[i - 1];
    }
    sub[0][i] = a[i];
  }
  long long int dp[k + 1][n + 1];
  long long int ans = 0;
  for (int i = 60; i >= 0; i--) {
    ans += 1ll << i;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int x = 1; x <= k; x++) {
      for (int y = 0; y <= n; y++) {
        if (dp[x - 1][y]) {
          for (int z = y + 1; z <= n; z++) {
            if ((sub[y][z - 1] & ans) == ans) {
              dp[x][z] = 1;
            }
          }
        }
      }
    }
    if (dp[k][n] != 1) ans -= 1ll << i;
  }
  cout << ans << endl;
  return 0;
}
