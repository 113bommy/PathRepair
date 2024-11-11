#include <bits/stdc++.h>
using namespace std;
long long dp[1005][1005], pre[1005][1005], A[1005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, i, j;
  cin >> n >> m >> k;
  for (i = 1; i <= 1000; i++) {
    for (j = 0; j <= 1000; j++) {
      if (j == 0)
        dp[i][j] = 1;
      else if (j > (i - 1) / 2)
        dp[i][j] = 0;
      else
        dp[i][j] = A[j - 1];
      pre[i][j] = (pre[i - 1][j] + dp[i][j]) % 1000000007;
    }
    for (j = 0; j <= 1000; j++) A[j] = (A[j] + pre[i - 1][j]) % 1000000007;
  }
  cout << (dp[n][k] * dp[m][k]) % 1000000007;
  return 0;
}
