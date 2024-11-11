#include <bits/stdc++.h>
using namespace std;
const int MN = 55;
const int MM = 6e4 + 5;
int N, M, K, A[MN][MM];
int ps[MN][MM], lft[MN][MM], rgt[MN][MM], dp[MN][MM];
int query(int r, int c1, int c2) { return ps[r][c2] - ps[r][c1 - 1]; }
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) cin >> A[i][j];
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      ps[i][j] = ps[i][j - 1] + A[i][j];
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j + K - 1 <= M; j++) {
      int sum = query(i, j, j + K - 1) + query(i + 1, j, j + K - 1);
      if (i == 1) {
        dp[i][j] = sum;
        continue;
      }
      if (j > K) dp[i][j] = max(dp[i][j], lft[i - 1][j - K] + sum);
      if (j + K - 1 <= M - K) dp[i][j] = max(dp[i][j], rgt[i - 1][j + K] + sum);
      for (int k = max(1, j - K + 1); k <= min(M - K + 1, j + K - 1); k++) {
        dp[i][j] =
            max(dp[i][j], dp[i - 1][k] + sum -
                              query(i, max(k, j), min(k + K - 1, j + K - 1)));
      }
    }
    for (int j = 1; j <= M - K + 1; j++)
      lft[i][j] = max(lft[i][j - 1], dp[i][j]);
    for (int j = M - K + 1; j >= 1; j--)
      rgt[i][j] = max(rgt[i][j + 1], dp[i][j]);
  }
  int ans = 0;
  for (int j = 1; j <= M; j++) ans = max(ans, dp[N][j]);
  cout << ans << "\n";
}
