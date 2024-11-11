#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5030;
double dp[MAXN][3], fail[MAXN];
double p[MAXN], f[MAXN];
int t[MAXN];
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d%d", &x, &t[i]);
    p[i] = x * 1.0 / 100;
  }
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) f[i] = 1, fail[i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t[i]; j++) f[i] *= (1 - p[i]);
  double sum = 0;
  if (t[1] == 1) {
    sum = 1;
    dp[1][1] = 1;
  } else {
    sum += p[1];
    dp[1][1] = p[1];
    fail[1] = (1 - p[1]);
    for (int i = 2; i <= t[1]; i++) {
      dp[i][1] = fail[i - 1] * p[1];
      sum += dp[i][1];
      fail[i] = fail[i - 1] * (1 - p[1]);
    }
    dp[t[1]][1] += f[1];
    sum += f[1];
  }
  for (int j = 2; j <= n; j++) {
    memset(fail, 0, sizeof(fail));
    for (int i = 0; i <= T; i++) dp[i][j % 2] = 0;
    for (int i = j; i <= T; i++) {
      dp[i][j % 2] = fail[i - 1] * p[j] + dp[i - 1][(j - 1) % 2] * p[j];
      fail[i] = fail[i - 1] * (1 - p[j]) + dp[i - 1][(j - 1) % 2] * (1 - p[j]);
      if (i - (j - 1) >= t[j]) {
        dp[i][j % 2] += dp[i - t[i]][(j - 1) % 2] * f[j];
        fail[i] -= dp[i - t[i]][(j - 1) % 2] * f[j];
      }
      sum += dp[i][j % 2];
    }
  }
  printf("%.8f\n", sum);
}
