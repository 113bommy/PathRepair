#include <bits/stdc++.h>
const int MAXN = 1000;
const int MAXD = 100;
int N, MOD, D;
int P[MAXN + 5];
int Dp[MAXN + 5][MAXD + 5][2];
int main() {
  scanf("%d%d%d", &N, &D, &MOD);
  P[0] = 1;
  for (int i = 1; i <= N; i++) P[i] = P[i - 1] * 10 % D;
  Dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      int cur0 = Dp[i][j][0], cur1 = Dp[i][j][1];
      if (!cur0 && !cur1) continue;
      for (int k = (i == N - 1); k < 10; k++) {
        int nxt = (k * P[i] + j) % D;
        if (cur0) {
          if (k && nxt == 0)
            Dp[i + 1][nxt][1] = (((Dp[i + 1][nxt][1]) + (cur0) >= MOD)
                                     ? ((Dp[i + 1][nxt][1]) + (cur0)-MOD)
                                     : ((Dp[i + 1][nxt][1]) + (cur0)));
          else
            Dp[i + 1][nxt][0] = (((Dp[i + 1][nxt][0]) + (cur0) >= MOD)
                                     ? ((Dp[i + 1][nxt][0]) + (cur0)-MOD)
                                     : ((Dp[i + 1][nxt][0]) + (cur0)));
        }
        if (cur1)
          Dp[i + 1][nxt][1] = (((Dp[i + 1][nxt][1]) + (cur1) >= MOD)
                                   ? ((Dp[i + 1][nxt][1]) + (cur1)-MOD)
                                   : ((Dp[i + 1][nxt][1]) + (cur1)));
      }
    }
  }
  int Ans = 0;
  for (int i = 0; i < D; i++)
    Ans = (((Ans) + (Dp[N][i][1]) >= MOD) ? ((Ans) + (Dp[N][i][1]) - MOD)
                                          : ((Ans) + (Dp[N][i][1])));
  printf("%d", Ans);
  return 0;
}
