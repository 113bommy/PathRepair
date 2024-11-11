#include <bits/stdc++.h>
const int D = 5010;
const int inf = 0x3f3f3f3f;
const double eps = 1e-10;
using namespace std;
int h1, t1, l1, r1, h2, t2, l2, r2;
double dp1[D][209], dp2[D][209], p1, p2;
int main() {
  scanf("%d%d%d%d%lf", &h1, &t1, &l1, &r1, &p1);
  scanf("%d%d%d%d%lf", &h2, &t2, &l2, &r2, &p2);
  if (p2 == 100) {
    printf("1\n");
    return 0;
  }
  if (p1 == 100) {
    printf("0\n");
    return 0;
  }
  dp1[0][h1] = 1.0;
  p1 /= 100, p2 /= 100;
  for (int i = 0; i < 5000; i++)
    for (int j = 0; j <= h1; j++) {
      if (dp1[i][j] <= eps) continue;
      double p = 1.0 / (r2 - l2 + 1);
      for (int k = l2; k <= r2; k++)
        dp1[i + 1][j > k ? j - k : 0] += dp1[i][j] * p * (1 - p2);
      dp1[i + 1][j] += dp1[i][j] * p2;
    }
  dp2[0][h2] = 1.0;
  for (int i = 0; i < 5000; i++)
    for (int j = 0; j <= h2; j++) {
      if (dp2[i][j] <= eps) continue;
      double p = 1.0 / (r1 - l1 + 1);
      for (int k = l1; k <= r1; k++)
        dp2[i + 1][j > k ? j - k : 0] += dp2[i][j] * p * (1 - p1);
      dp2[i + 1][j] += dp2[i][j] * p1;
    }
  double sum = 0, ret = 0;
  for (int i = 1; i <= 5000 && i * t1 / t2 < 5000; i++) {
    sum = dp2[i][0] - dp2[i - 1][0];
    ;
    double s = 0;
    for (int j = 1; j <= h1; j++)
      s += dp1[((i - 1) * t1 % t2 == 0) ? (i - 1) * t1 / t2
                                        : (i - 1) * t1 / t2 + 1][j];
    ret += s * sum;
  }
  printf("%.11f\n", ret);
  return 0;
}
