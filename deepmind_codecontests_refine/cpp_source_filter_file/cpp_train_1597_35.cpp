#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int N, L, K;
int P[MAXN];
int A[MAXN];
double dp[MAXN + 1][MAXN + 1][4 * MAXN + 1];
signed main() {
  ios::sync_with_stdio(0);
  cin >> N >> L >> K;
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  const int offset = MAXN;
  dp[0][0][offset + K] = 1.0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = -N; k <= N; ++k) {
        double win = 1.0 * P[i] / 100;
        double lose = 1.0 - win;
        dp[i + 1][j][offset + k] += dp[i][j][offset + k] * lose;
        if (A[i] == -1) {
          dp[i + 1][j + 1][offset + k - 1] += dp[i][j][offset + k] * win;
        } else {
          dp[i + 1][j + 1][offset + min(N, k + A[i])] +=
              dp[i][j][offset + k] * win;
        }
      }
    }
  }
  double ans = 0.0;
  for (int i = L; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      ans += dp[N][i][offset + j];
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
