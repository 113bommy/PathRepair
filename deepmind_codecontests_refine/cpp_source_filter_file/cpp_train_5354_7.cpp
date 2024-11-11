#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
inline long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f ? x : -x;
}
double dp[N][N], r[N], c[N];
int n, m, t, t2;
int main() {
  n = rd(), m = rd(), t = t2 = n;
  int x, y;
  for (int i = 1; i <= m; i++) {
    x = rd(), y = rd();
    if (!r[x]) r[x] = 1, t--;
    if (!c[x]) c[x] = 1, t2--;
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + (double)n / i;
    dp[0][i] = dp[0][i - 1] + (double)n / i;
  }
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= t2; j++) {
      dp[i][j] = n * n;
      dp[i][j] += i * j * dp[i - 1][j - 1];
      dp[i][j] += i * (n - j) * dp[i - 1][j];
      dp[i][j] += j * (n - i) * dp[i][j - 1];
      dp[i][j] /= (n * n - (n - i) * (n - j));
    }
  }
  printf("%.10lf\n", dp[t][t2]);
  return 0;
}
