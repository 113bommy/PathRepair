#include <bits/stdc++.h>
using namespace std;
const int N = 110;
double dp[N][N][N], pa, pb, pc;
int a, b, c;
int main() {
  scanf("%d%d%d", &a, &b, &c);
  dp[a][b][c] = 1;
  for (int i = a; i >= 0; --i) {
    for (int j = b; j >= 0; --j) {
      for (int k = c; k >= 0; --k) {
        if (!i && !j && !k) break;
        if (i * j + i * k + j * k == 0) continue;
        double ij = (i * j * 1.0) / (i * j + i * k + j * k);
        double ik = (i * k * 1.0) / (i * j + i * k + j * k);
        double jk = (j * k * 1.0) / (i * j + i * k + j * k);
        if (j - 1 >= 0) dp[i][j - 1][k] += ij * dp[i][j][k];
        if (k - 1 >= 0) dp[i][j][k - 1] += jk * dp[i][j][k];
        if (i - 1 >= 0) dp[i - 1][j][k] += ik * dp[i][j][k];
      }
    }
  }
  for (int i = a; i >= 1; --i) pa += dp[i][0][0];
  for (int i = b; i >= 1; --i) pb += dp[0][i][0];
  for (int i = c; i >= 1; --i) pc += dp[0][0][i];
  printf("%lf %lf %lf\n", pa, pb, pc);
  return 0;
}
