#include <bits/stdc++.h>
using namespace std;
double dp[210][410], P;
int main() {
  int X, K;
  scanf("%d%d%lf", &X, &K, &P);
  P /= 100.0;
  for (int i = 0; i <= K; i++) dp[0][i] = __builtin_ctz(X + i);
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j <= K; j++) {
      dp[i][j] += (dp[i - 1][j + 1]) * (1.0 - P);
      dp[i][j << 1] += (dp[i - 1][j] + 1) * P;
    }
  }
  printf("%.10lf\n", dp[K][0]);
  return 0;
}
