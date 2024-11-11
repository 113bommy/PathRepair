#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int viscol[3030];
int visrow[3030];
double dp[3030][3030];
int n, m, C, R;
void ReadData() {
  C = n;
  R = n;
  int r, c;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &r, &c);
    if (!viscol[c]) {
      viscol[c] = true;
      C--;
    }
    if (!visrow[r]) {
      visrow[c] = true;
      R--;
    }
  }
}
void Compute() {
  dp[0][0] = 0;
  for (int i = 1; i <= R; i++) {
    dp[i][0] = dp[i - 1][0] + n / (double)i;
  }
  for (int j = 1; j <= C; j++) {
    dp[0][j] = dp[0][j - 1] + n / (double)j;
  }
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      dp[i][j] = (n * n + dp[i - 1][j] * (i * (n - j)) +
                  dp[i][j - 1] * (j * (n - i)) + dp[i - 1][j - 1] * (i * j)) /
                 (double)((double)n * n - (double)(n - i) * (n - j));
    }
  }
  printf("%.10lf\n", dp[R][C]);
}
int main() {
  int c, r;
  while (~scanf("%d%d", &n, &m)) {
    ReadData();
    Compute();
  }
  return 0;
}
