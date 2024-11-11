#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 100;

int n, w[N], b[N];
int dp[N][N];
int cw[N][N], cb[N][N];

int main() {
  char s[5];
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) {
    int x;
    scanf("%s %d", s + 1, &x);
    if (s[1] == 'W') {
      w[x] = i;
    } else {
      b[x] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (w[i] < w[j]) {
        cw[i][0]++;
      }
    }
    for (int j = 1; j <= n; j++) {
      cw[i][j] = cw[i][j - 1];
      if (w[i] < b[j]) {
        cw[i][j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (b[i] < b[j]) {
        cb[0][i]++;
      }
    }
    for (int j = 1; j <= n; j++) {
      cb[j][i] = cb[j - 1][i];
      if (b[i] < w[j]) {
        cb[j][i]++;
      }
    }
  }
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; i++) {
    c1 += cw[i][0];
    c2 += cb[0][i];
    dp[i][0] = c1;
    dp[0][i] = c2;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = min(dp[i - 1][j] + cw[i][j], dp[i][j - 1] + cb[i][j]);
    }
  }
  printf("%d\n", dp[n][n]);
  return 0;
}