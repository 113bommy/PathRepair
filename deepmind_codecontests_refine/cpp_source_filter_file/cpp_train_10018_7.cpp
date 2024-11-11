#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const int N = 2000 + 10;
const long long MOD = 1000000000 + 7;
const long long INF = 1000000000000000010;
const long long LOG = 20;
int A[N], second[N], C[N], n, m;
long long dp[N << 1][N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> second[i];
  for (int i = 1; i <= n; i++) cin >> C[i];
  for (int i = 0; i < N * 2; i++)
    for (int j = 0; j < N; j++) dp[i][j] = -INF;
  for (int i = 0; i < N * 2; i++) dp[i][0] = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--)
      dp[A[i]][j] = max(dp[A[i]][j], dp[A[i]][j - 1] - second[i] + C[A[i]]);
    int Now = n / 2;
    for (int j = A[i] + 1; j <= n + m; j++) {
      for (int k = 0; k <= Now; k++)
        dp[j][k] = max(dp[j][k],
                       max(dp[j - 1][2 * k], dp[j - 1][2 * k + 1]) + C[j] * k);
      Now /= 2;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n + m; i++) ans = max(ans, dp[i][1]);
  cout << ans;
  return 0;
}
