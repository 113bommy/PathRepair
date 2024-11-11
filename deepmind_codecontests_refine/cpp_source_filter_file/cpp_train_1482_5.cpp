#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> dp;
const int MAXN = 23456;
int pmax[MAXN], smax[MAXN];
int psum2[MAXN], psum[MAXN];
int get1d(int l, int r) { return psum[r] - psum[l - 1]; }
int get2d(int l, int r) { return psum2[r] - psum2[l - 1] + get1d(l, r); }
int main() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  grid.resize(N + 2);
  dp.resize(N + 2);
  for (int i = 0; i <= N + 1; i++) {
    grid[i].resize(M + 1, 0);
    dp[i].resize(M + 1, 0);
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) scanf("%d", &grid[i][j]);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) psum2[j] = psum2[j - 1] + grid[i + 1][j];
    for (int j = 1; j <= M; j++) psum[j] = psum[j - 1] + grid[i][j];
    for (int j = 1; j <= M - K + 1; j++) {
      int cost = get2d(j, j + K - 1);
      dp[i][j] = pmax[max(0, j - K)] + cost;
      for (int k = j - K + 1; k <= j + K - 1; k++) {
        if (k < 1) continue;
        int offs = get1d(max(k, j), min(k, j) + K - 1);
        int cur = dp[i - 1][k] + cost - offs;
        dp[i][j] = max(dp[i][j], cur);
      }
      dp[i][j] = max(dp[i][j], smax[min(N + 1, j + K)] + cost);
    }
    for (int j = 1; j <= N; j++) pmax[j] = max(pmax[j - 1], dp[i][j]);
    for (int j = N; j >= 1; j--) smax[j] = max(smax[j + 1], dp[i][j]);
  }
  int ans = 0;
  for (int i = 1; i <= M - K + 1; i++) ans = max(ans, dp[N][i]);
  printf("%d\n", ans);
  return 0;
}
