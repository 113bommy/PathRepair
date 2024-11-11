#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int dp[2][52][52], n, p, power[51];
void add(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}
int main() {
  scanf("%d%d", &n, &p);
  power[0] = 1;
  for (int i = 1; i <= 50; i++) power[i] = (power[i - 1] << 1) % M;
  dp[0][0][0] = 1;
  for (int u = 0, col; u < n; u++) {
    scanf("%d", &col);
    int at = u & 1, to = !at;
    for (int wo = 0; wo <= u; wo++)
      for (int bo = 0; bo + wo <= u; bo++) {
        int &ref = dp[at][wo][bo], even = u - wo - bo;
        if (col) {
          int val = power[even + wo] * 1LL * power[max(0, bo - 1)] % M;
          if (bo) add(dp[to][wo][bo], ref * 1LL * val % M);
          add(dp[to][wo + 1][bo], ref * 1LL * val % M);
        }
        if (col != 1) {
          int val = power[even + bo] * 1LL * power[max(0, wo - 1)] % M;
          if (wo) add(dp[to][wo][bo], ref * 1LL * val % M);
          add(dp[to][wo][bo + 1], ref * 1LL * val % M);
        }
        ref = 0;
      }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j + i <= n; j++)
      if (((i + j) & 1) == p) add(ans, dp[n & 1][i][j]);
  printf("%d\n", ans);
}
