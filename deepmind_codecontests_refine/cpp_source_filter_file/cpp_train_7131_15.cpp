#include <bits/stdc++.h>
using namespace std;
int dp[200][50000];
int a[200];
int main() {
  int m, n, i, j, k;
  long long s;
  cin >> n >> m >> s;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  s += (m * (m + 1) / 2);
  long long st = 33333;
  s = min(s, st);
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  for (i = 1; i <= n; i++) {
    for (j = m; j >= 1; j--) {
      for (k = 33333; k >= i; k--)
        dp[j][k] = min(dp[j][k], dp[j - 1][k - i] + a[i]);
    }
  }
  int ans = 99999999;
  for (i = 0; i <= s; i++) ans = min(ans, dp[m][i]);
  cout << ans << endl;
}
