#include <bits/stdc++.h>
const int N = 2010;
int a, b, s;
double dp[N][N], sol;
int main() {
  scanf("%d %d", &a, &b);
  dp[a][b] = 1;
  s = a + b;
  for (int p = 1; s >= 0; p++) {
    for (int i = 0; i <= s; i++) {
      int j = s - i;
      if (p & 1) {
        if (j) dp[i][j - 1] += dp[i][j] * j / (i + j);
        sol += dp[i][j] * i / (i + j);
      } else {
        if (i && j)
          dp[i - 1][j - 1] += dp[i][j] * j / (i + j) * i / (i + j - 1);
        if (j >= 2)
          dp[i][j - 2] += dp[i][j] * j / (i + j) * (j - 1) / (i + j - 1);
      }
    }
    if (p & 1)
      s--;
    else
      s -= 2;
  }
  printf("%.12lf", sol);
  return 0;
}
