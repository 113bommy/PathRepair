#include <bits/stdc++.h>
using namespace std;
long long int nck(long long int n, long long int k) {
  long long int ans = 1;
  for (int i = 0; i < k; i++) {
    ans = ans * (n - i);
  }
  for (int i = 1; i <= k; i++) {
    ans = ans / i;
  }
  return ans;
}
long long int nck2(long long int n, long long int k) {
  long long int dp[n + 1][n + 1];
  dp[0][0] = 1;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = 1;
    for (int j = 1; j < i; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
    dp[i][i] = 1;
  }
  return dp[n][k];
}
int main() {
  int n, k;
  cin >> n >> k;
  long long int ans = 1, f[] = {0, 0, 1, 2, 9};
  for (int i = 1; i <= k; i++) {
    ans = ans + nck2(n, i) * f[i];
  }
  cout << ans << endl;
  return 0;
}
