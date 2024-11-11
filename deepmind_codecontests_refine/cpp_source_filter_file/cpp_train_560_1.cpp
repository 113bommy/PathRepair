#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[30];
int B[30];
int dp[100000][100];
const int INF = 1e9;
const int R = 300;
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", A + i);
  for (int i = 0; i < n; i++) scanf("%d", B + i);
  for (int i = 0; i < n * R; i++) fill(dp[i], dp[i] + sizeof(dp[i]), INF);
  dp[0][1] = A[0];
  for (int i = 1; i < n * R; i++) {
    int X = A[i % n];
    int Y = B[i % n];
    dp[i][0] = min(INF, dp[i - 1][1] + Y);
    dp[i][100] = min(INF, dp[i - 1][99] + X);
    for (int j = 1; j <= 99; j++) {
      dp[i][j] = min(dp[i - 1][j - 1] + X, dp[i - 1][j + 1] + Y);
    }
  }
  if (m <= R) {
    printf("%d", dp[n * m - 1][0]);
  } else {
    printf("%d",
           dp[n * R - 1][0] +
               (dp[n * R - 1][0] - dp[n * (R - 2) - 1][0]) * ((m - R) / 2));
  }
  return 0;
}
