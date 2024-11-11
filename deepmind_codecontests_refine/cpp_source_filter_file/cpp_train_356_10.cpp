#include <bits/stdc++.h>
using namespace std;
double dp[2][(505)];
double sum[(505)];
int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  for (int j = 1; j < (505); j++) sum[j] = sum[j - 1] + j;
  int pre = 0;
  int now = 1;
  double c1 = 1.0 * (K - 1) / K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < (505) - 1; j++) {
      dp[now][j] = c1 * dp[pre][j];
      dp[now][j] +=
          (j * dp[pre][j] + dp[pre][j + 1] + j + sum[j]) / K / (j + 1);
    }
    pre ^= 1;
    now ^= 1;
  }
  printf("%.9lf\n", dp[pre][1] * K);
  return 0;
}
