#include <bits/stdc++.h>
int main(int agrc, char* argv[]) {
  double a, v;
  scanf("%lf%lf", &a, &v);
  double l, d, w;
  scanf("%lf%lf%lf", &l, &d, &w);
  if (d <= w * w / (2 * a) || v <= w) {
    double tbes = sqrt(2 * l / a);
    double t1 = v / a;
    if (tbes < t1) {
      printf("%lf\n", tbes);
    } else {
      double s1 = a * t1 * t1 / 2;
      double t2 = (l - s1) / v;
      printf("%lf\n", t1 + t2);
    }
    return 0;
  }
  double hv = w / a;
  double tend = -hv + sqrt(hv * hv + 2 * (l - d) / a);
  if (tend * a >= v - w) {
    tend = (v - w) / a;
    tend = tend + (l - d - w * tend - a * tend * tend / 2) / v;
  }
  double t1 = v / a;
  double t3 = (v - w) / a;
  double t2 = (d - a * t1 * t1 / 2 - t3 * (v + w) / 2) / v;
  if (t2 < 0) {
    t1 = sqrt((d + w * w / (2 * a)) / a);
    t2 = t1 - w / a;
    printf("%lf\n", t1 + t2 + tend);
  } else {
    printf("%lf\n", t1 + t2 + t3 + tend);
  }
  return 0;
}
