#include <bits/stdc++.h>
using namespace std;
const int N = (int)105;
const int M = (int)5555;
int n, r;
int a[N];
int b[N];
int c[N];
const double inf = 1e18;
double dp[N][M];
int check(double p) {
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= r; ++j) {
      double z1 = 0, z2 = 0;
      if (j + a[i + 1] > r) {
        z1 = (p + a[i + 1]) * c[i + 1] / 100.0;
      } else {
        z1 = (dp[i + 1][j + a[i + 1]] + a[i + 1]) * c[i + 1] / 100.0;
      }
      if (j + b[i + 1] > r) {
        z2 = (p + b[i + 1]) * (100 - c[i + 1]) / 100.0;
      } else {
        z2 = (dp[i + 1][j + b[i + 1]] + b[i + 1]) * (100 - c[i + 1]) / 100.0;
      }
      dp[i][j] = min(p, z1 + z2);
    }
  }
  return dp[0][0] < p;
}
int main() {
  scanf("%d %d", &n, &r);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
  }
  double st = 0.0;
  double ed = 2e5;
  for (int cas = 0; cas < 100; ++cas) {
    double mid = (st + ed) / 2;
    if (check(mid)) {
      ed = mid;
    } else {
      st = mid;
    }
  }
  printf("%.20lf\n", (st + ed) / 2);
  return 0;
}
