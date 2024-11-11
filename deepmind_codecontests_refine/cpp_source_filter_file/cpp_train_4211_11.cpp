#include <bits/stdc++.h>
using namespace std;
long long int ans, dp[1010][1010];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) dp[0][i] = 1;
  for (int i = 1; i < k; i++)
    for (int j = 1; j <= n; j++)
      for (int l = 1; l * l <= j; l++)
        if (j % l == 0) {
          dp[i][j] = (dp[i][j] + dp[i - 1][l]) % 1000000007;
          if (j / l != l) dp[i][j] = (dp[i][j] + dp[i - 1][j / l]) % 1000000007;
        }
  for (int i = 1; i <= n; i++) ans = (ans + dp[k - 1][i]) % 1000000007;
  cout << ans << "\n";
  return 0;
}
