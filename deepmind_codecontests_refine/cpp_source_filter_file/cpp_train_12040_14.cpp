#include <bits/stdc++.h>
using namespace std;
int dp[200005];
int sum[1000005][10];
int solve(int n) {
  if (dp[n] != -1) return dp[n];
  if (n < 10)
    return dp[n] = n;
  else {
    int res = 1, nn = n;
    while (nn > 0) {
      int lastDigit = nn % 10;
      if (lastDigit != 0) res *= lastDigit;
      nn /= 10;
    }
    return dp[n] = solve(res);
  }
}
int main() {
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= 200000; i++) {
    int x = solve(i);
    for (int j = 1; j <= 9; j++) sum[i][j] = sum[i - 1][j];
    sum[i][x]++;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << sum[r][k] - sum[l - 1][k] << endl;
  }
  return 0;
}
