#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5050;
const int OFFSET = 5050;
int n, T, t[MAXN];
double dp[2][MAXN * 2], p[MAXN];
int P[MAXN];
double factor[101][MAXN];
double *f[2];
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &P[i], &t[i]);
    p[i] = P[i] / 100.0;
  }
  double res = 0;
  f[0] = dp[0];
  f[1] = dp[1];
  for (int k = OFFSET; k <= OFFSET + T; k++) {
    f[0][k] = 1;
  }
  for (int i = 0; i <= 100; i++) {
    factor[i][0] = 1;
    for (int k = 1; k <= t[i]; k++) {
      factor[i][k] = factor[i][k - 1] * (1.0 - i / 100.0);
    }
  }
  cerr << "ok" << endl;
  for (int i = 1; i <= n; i++) {
    double delta = 0;
    f[1][OFFSET] = 0;
    for (int j = OFFSET + 1; j <= OFFSET + T; j++) {
      delta *= 1 - p[i];
      if (j - t[i] >= OFFSET)
        delta -= f[0][j - t[i]] * factor[P[i]][t[i] - 1] * p[i];
      delta += f[0][j - 1] * p[i];
      f[1][j] = delta;
      if (j - t[i] >= OFFSET)
        f[1][j] += factor[P[i]][t[i] - 1] * f[0][j - t[i]];
    }
    res += (i - 1) * (f[0][OFFSET + T] - f[1][OFFSET + T]);
    swap(f[0], f[1]);
  }
  res += n * f[0][OFFSET + T];
  printf("%.6f\n", res);
}
