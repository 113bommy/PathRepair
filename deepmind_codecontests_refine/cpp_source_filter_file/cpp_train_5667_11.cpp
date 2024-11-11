#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
double dp[2005][2005];
int n, m, t1, t2;
bool r[2005], c[2005];
int main() {
  n = read();
  m = read();
  t1 = t2 = n;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    if (!r[x]) r[x] = 1, t1--;
    if (!r[y]) c[y] = 1, t2--;
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + (double)n / i;
    dp[0][i] = dp[0][i - 1] + (double)n / i;
  }
  for (int i = 1; i <= t1; i++)
    for (int j = 1; j <= t2; j++) {
      dp[i][j] = n * n;
      dp[i][j] += i * j * dp[i - 1][j - 1];
      dp[i][j] += i * (n - j) * dp[i - 1][j];
      dp[i][j] += j * (n - i) * dp[i][j - 1];
      dp[i][j] /= (n * n - (n - i) * (n - j));
    }
  printf("%.10lf\n", dp[t1][t2]);
  return 0;
}
