#include <bits/stdc++.h>
double dp[1005][1005];
int main() {
  int w, b;
  scanf("%d%d", &w, &b);
  for (int i = 0; i <= w; ++i) dp[i][0] = 1;
  for (int i = 0; i <= b; ++i) dp[0][i] = 0;
  for (int i = 1; i <= w; ++i) {
    for (int j = 1; j <= b; ++j) {
      dp[i][j] = (double)i / (i + j);
      if (j >= 3)
        dp[i][j] += (double)j / (i + j) * (double)(j - 1) / (i + j - 1) *
                    (double)(j - 2) / (i + j - 2) * dp[i][j - 3];
      if (j >= 2)
        dp[i][j] += (double)j / (i + j) * (double)(j - 1) / (i + j - 1) *
                    (double)i / (i + j - 2) * dp[i - 1][j - 2];
    }
  }
  printf("%.9lf\n", dp[w][b]);
  return 0;
}
