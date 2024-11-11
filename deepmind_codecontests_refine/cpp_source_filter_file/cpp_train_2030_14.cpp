#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n > 5 * m) {
    cout << "YES";
    return 0;
  }
  bool dp[n][m + 1];
  for (int i = 0; i <= m; i++) dp[0][i] = false;
  for (int i = 0; i < n; i++) dp[i][0] = true;
  if (arr[0] == m)
    dp[0][m] = true;
  else
    dp[0][arr[0] % m] = true;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++)
      dp[i][j] = dp[i - 1][j] || dp[i - 1][(j - (arr[i] % m) + m) % m];
  }
  if (dp[n - 1][m])
    cout << "YES";
  else
    cout << "NO";
}
