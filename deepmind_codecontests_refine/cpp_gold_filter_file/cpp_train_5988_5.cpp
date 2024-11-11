#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, a[N], dp[N][N], j;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], dp[i][i] = 1;
  for (int s = 2; s <= n; s++) {
    for (int i = 1; i <= n - s + 1; i++) {
      j = i + s - 1;
      dp[i][j] = 1 + dp[i + 1][j];
      for (int k = i; k <= j; k++) {
        if (a[i] == a[k])
          dp[i][j] = min(dp[i][j], max(dp[i + 1][k - 1], 1) + dp[k + 1][j]);
      }
    }
  }
  cout << dp[1][n] << '\n';
}
