#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
double dp[2010][2010];
bool visR[2010], visC[2010];
int numR, numC;
int n, m;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; ++i) {
    int r = read(), c = read();
    if (!visR[r]) numR++;
    if (!visC[c]) numC++;
    visR[r] = visC[c] = true;
  }
  dp[n][n] = 0;
  for (int i = n; i >= 0; --i) {
    for (int j = n; j >= 0; --j) {
      if (i == n && j == n) continue;
      dp[i][j] = 1 + 1.0 * (n - i) * j / (n * n * 1.0) * dp[i + 1][j] +
                 1.0 * i * (n - j) / (n * n * 1.0) * dp[i][j + 1] +
                 1.0 * (n - i) * (n - j) / (n * n) * dp[i + 1][j + 1];
      dp[i][j] /= (1.0 - 1.0 * i * j / (n * n));
    }
  }
  printf("%.10lf\n", dp[numR][numC]);
}
