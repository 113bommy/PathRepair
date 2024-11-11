#include <bits/stdc++.h>
using namespace std;
long long N, _;
long long a[4][1919810], dp[1919810][4];
int main() {
  cin >> N;
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= N; j++) cin >> _, a[i][j] = _ + a[i - 1][j];
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= 3; j++) dp[i][j] = -pow(2, 63);
  dp[0][1] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 3; j++)
      for (int k = 1; k <= 3; k++)
        dp[i][j] =
            max(dp[i - 1][k] + a[max(j, k)][i] - a[min(j, k) - 1][i], dp[i][j]);
    dp[i][1] = max(dp[i][1], a[3][i] + dp[i - 1][0]);
    dp[i][3] = max(dp[i][3], a[3][i] + dp[i - 1][0]);
    dp[i][0] = max(dp[i][0], a[3][i] + max(dp[i - 1][1], dp[i - 1][3]));
  }
  cout << dp[N][3] << endl;
}
