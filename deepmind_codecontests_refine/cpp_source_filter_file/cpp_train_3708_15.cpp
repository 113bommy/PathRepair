#include <bits/stdc++.h>
using namespace std;
long long dp[100100][4];
long long a[100100], b[100100];
int main() {
  int n;
  cin >> n;
  cin >> b[1] >> b[2] >> b[3];
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = -(1ll << 60);
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= 3; j++) dp[i][j] = -(1ll << 60);
  for (int i = 1; i <= n; i++) {
    dp[i][1] = max(dp[i - 1][1], b[1] * a[i]);
    dp[i][2] = max(dp[i - 1][2], dp[i][1] + b[2] * a[i]);
    dp[i][3] = max(dp[i - 1][3], dp[i][2] + b[3] * a[i]);
  }
  cout << dp[n][3] << endl;
  return 0;
}
