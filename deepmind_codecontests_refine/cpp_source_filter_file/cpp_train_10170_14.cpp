#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
double dp[1100][1100];
inline void prepare() {
  int i, j, s;
  double a, b, c, d, p;
  dp[0][0] = 1;
  for (i = 0; i < 1100; i++) dp[i][0] = 1;
  for (j = 0; j < 1100; j++) dp[0][j] = 1.0 / (j + 1);
  for (s = 2; s < 1100 + 1100; s++)
    for (i = 1; i < 1100; i++) {
      j = s - i;
      if (j < 1 || j >= 1100) continue;
      a = 1;
      b = 1.0 * j / (j + 1) * (1 - dp[j - 1][i]);
      c = 1 - dp[j][i - 1];
      d = 1.0 / (j + 1) + 1.0 * j / (j + 1) * (1 - dp[j - 1][i]);
      dp[i][j] = 0;
      if (fabs(a + d - b - c) > 1e-8) {
        p = (d - b) / (a - b - c + d);
        chkmax(dp[i][j], p * a + (1 - p) * b);
      }
      chkmax(dp[i][j], min(a, c));
      chkmax(dp[i][j], min(b, d));
      chkmax(dp[i][j], 1.0 / (j + 1));
    }
}
int main() {
  int N, M;
  prepare();
  scanf("%d%d", &N, &M);
  printf("%lf %lf\n", dp[N][M], 1 - dp[N][M]);
  return 0;
}
