#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 10;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;
int n;
long long arr[3][MAXN];
long long dp[MAXN][5];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++) cin >> arr[i][j];
  dp[0][0] = arr[0][0];
  dp[0][1] = arr[0][0] + arr[1][0];
  dp[0][2] = arr[0][0] + arr[1][0] + arr[2][0];
  dp[0][3] = -1 * INF;
  dp[0][4] = dp[0][2];
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + arr[0][i];
    dp[i][0] = max(dp[i][0], dp[i - 1][1] + arr[0][i] + arr[1][i]);
    dp[i][0] = max(dp[i][0], dp[i - 1][2] + arr[0][i] + arr[1][i] + arr[2][i]);
    dp[i][0] = max(dp[i][0], dp[i - 1][3] + arr[0][i] + arr[1][i] + arr[2][i]);
    dp[i][1] = dp[i - 1][0] + arr[0][i] + arr[1][i];
    dp[i][1] = max(dp[i][1], dp[i - 1][1] + arr[1][i]);
    dp[i][1] = max(dp[i][1], dp[i - 1][2] + arr[1][i] + arr[2][i]);
    dp[i][2] = dp[i - 1][2] + arr[2][i];
    dp[i][2] = max(dp[i][2], dp[i - 1][1] + arr[1][i] + arr[2][i]);
    dp[i][2] = max(dp[i][2], dp[i - 1][0] + arr[0][i] + arr[1][i] + arr[2][i]);
    dp[i][2] = max(dp[i][2], dp[i - 1][4] + arr[0][i] + arr[1][i] + arr[2][i]);
    dp[i][3] =
        max(dp[i - 1][3], dp[i - 1][2]) + arr[0][i] + arr[1][i] + arr[2][i];
    dp[i][4] =
        max(dp[i - 1][4], dp[i - 1][0]) + arr[0][i] + arr[1][i] + arr[2][i];
  }
  cout << dp[n - 1][2] << endl;
  return 0;
}
