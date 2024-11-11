#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long INF = 1e15;
int n, a[3][N];
long long dp[4][N];
long long sum(int x, int l, int r) {
  if (l > r) swap(l, r);
  long long res = 0;
  for (int i = l; i <= r; i++) res += a[i][x];
  return res;
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < 3; i++)
      for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < 4; i++)
      for (int j = 0; j <= n; j++) dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
          dp[j][i] = max(dp[j][i], dp[k][i - 1] + sum(i, j, k));
      dp[0][i] = max(dp[0][i], dp[3][i - 1] + sum(i, 0, 2));
      dp[2][i] = max(dp[2][i], dp[3][i - 1] + sum(i, 0, 2));
      dp[3][i] = max(dp[3][i], max(dp[0][i - 1], dp[2][i - 1]) + sum(i, 0, 2));
    }
    printf("%I64d\n", dp[2][n]);
  }
  return 0;
}
