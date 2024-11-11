#include <bits/stdc++.h>
using namespace std;
double yy1[100011];
double yy2[100011];
double l[100011];
double dis(double a, double b, double c, double d) {
  return sqrt((c - a) * (c - a) + (d - b) * (d - b));
}
double Abs(double a) { return a < 0 ? -a : a; }
int main() {
  double n, m, a, b;
  while (scanf("%lf%lf%lf%lf", &n, &m, &a, &b) > 0) {
    for (int i = 0; i < n; i++) scanf("%lf", &yy1[i]);
    for (int i = 0; i < m; i++) scanf("%lf", &yy2[i]);
    for (int i = 0; i < m; i++) scanf("%lf", &l[i]);
    int mini = 0, mini2 = 0;
    double minn = 99999999999999999.99999;
    for (int i = 0; i < m; i++) {
      double res = l[i];
      int l = 0, r = n - 1;
      double best = (double)yy2[i] * a / b;
      while (l < r - 2) {
        int m1 = l + r >> 1;
        int mm = r + m1 >> 1;
        if (Abs(yy1[mm] - best) < Abs(yy1[m1] - best))
          l = m1;
        else
          r = mm;
      }
      int q = 0;
      double qq = 0x7fffffff;
      for (int ii = l; ii <= r; ii++)
        if (Abs(yy1[ii] - best) < qq) q = ii, qq = Abs(yy1[ii] - best);
      res += dis(0, 0, a, yy1[q]) + dis(a, yy1[q], b, yy2[i]);
      if (res < minn) minn = res, mini = q, mini2 = i;
    }
    printf("%d %d\n", mini + 1, mini2 + 1);
  }
  return 0;
}
