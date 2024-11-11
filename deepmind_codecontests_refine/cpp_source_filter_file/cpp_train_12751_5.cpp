#include <bits/stdc++.h>
using namespace std;
const int MAX = 500;
int N, M, B, MOD, arr[MAX + 5], dp[2][MAX + 5][MAX + 5];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> B >> MOD;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int j = 0; j <= M; j++) {
    if (j * arr[0] > B) break;
    dp[0][j][j * arr[0]] = 1;
  }
  for (int pos = 1; pos < N; pos++) {
    int i = pos % 2;
    for (int j = 0; j <= M; j++)
      for (int k = 0; k <= B; k++) {
        dp[i][j][k] = dp[i ^ 1][j][k];
        if (j > 0 && k - arr[i] >= 0) {
          dp[i][j][k] += dp[i][j - 1][k - arr[i]];
          dp[i][j][k] %= MOD;
        }
      }
  }
  int ans = 0;
  for (int k = 0; k <= B; k++) {
    ans += dp[(N - 1) % 2][M][k];
    ans %= MOD;
  }
  cout << ans << "\n";
}
