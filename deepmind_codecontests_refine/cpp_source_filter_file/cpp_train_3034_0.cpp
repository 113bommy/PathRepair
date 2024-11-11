#include <bits/stdc++.h>
using namespace std;
int S[3000];
long long int dp[3000][3000];
int match[3000][3000];
int main() {
  int i;
  int m;
  scanf("%d", &m);
  for (i = 0; i < m; i++) scanf("%d", &S[i]);
  int j;
  for (i = 0; i < m; i++) {
    for (j = i; j < m; j++) {
      dp[i][j] = 0;
      if (j - i + 1 >= 1) dp[i][j] += (j == i) ? 1 : dp[i][j - 1];
      if (j - i + 1 >= 2) dp[i][j] += (j == i + 1) ? 1 : dp[i][j - 2];
      if (j - i + 1 >= 3) dp[i][j] += (j == i + 2) ? 1 : dp[i][j - 3];
      if (j - i + 1 >= 4) {
        int b = (S[j - 3] << 8) | (S[j - 2] << 4) | (S[j - 1] << 2) | S[j];
        if ((b != 3) && (b != 5) && (b != 14) && (b != 15))
          dp[i][j] += (j == i + 3) ? 1 : dp[i][j - 4];
      }
      dp[i][j] %= 1000000007;
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j <= i; j++) {
      if (S[i] != S[j])
        match[i][j] = 0;
      else
        match[i][j] = ((i > 0) && (j > 0)) ? match[i - 1][j - 1] + 1 : 1;
    }
  }
  int ans = 0;
  for (i = 0; i < m; i++) {
    int x = 0;
    for (j = 0; j < i; j++) x = max(x, match[i][j]);
    for (j = 0; j <= i - x; j++) ans += dp[j][i], ans %= 1000000007;
    printf("%d\n", ans);
  }
  return 0;
}
