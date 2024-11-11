#include <bits/stdc++.h>
using namespace std;
int N, K;
int grid[4010][4010];
int dp[4010][810];
int pre[4010][4010];
int ans;
int rect(int x, int y) {
  if (x == 0) {
    return pre[y][y];
  } else {
    return pre[y][y] - pre[x - 1][y] - pre[y][x - 1] + pre[x - 1][x - 1];
  }
}
void solve(int i, int l, int r, int optl, int optr) {
  if (l > r) {
    return;
  }
  int mid = (l + r) / 2;
  int opt = -1;
  for (int k = optl; k <= min(optr, mid - 1); k++) {
    if (dp[i - 1][k] + rect(k + 1, mid) < dp[i][mid]) {
      dp[i][mid] = dp[i - 1][k] + rect(k + 1, mid);
      opt = k;
    }
  }
  solve(i, l, mid - 1, optl, opt);
  solve(i, mid + 1, r, opt, optr);
}
int32_t main() {
  if (fopen("cf321e.in", "r")) {
    freopen("cf321e.in", "r", stdin);
    freopen("cf321e.out", "w", stdout);
  }
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      char c = getchar();
      while (c < '0') {
        c = getchar();
      }
      grid[i][j] = c - '0';
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      pre[i][j] =
          pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i][j];
    }
  }
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= N; j++) {
      dp[i][j] = 1000000001;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= K; i++) {
    solve(i, 0, N + 1, 0, N);
  }
  assert((dp[K][N] % 2) == 0);
  cout << dp[K][N] / 2 << '\n';
  return 0;
}
