#include <bits/stdc++.h>
using namespace std;
double dis(double x1, double y1, double x2, double y2) {
  double ans = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
  return ans;
}
int main() {
  double x1, y1, x2, x3, y2, y3, x4, y4,
      maxa = 999999999999, maxb = 999999999999, maxa2 = 999999999999,
      maxb2 = 999999999999, sum = 0, t3, t4;
  int n, i1, i2;
  scanf("%lf %lf %lf %lf %lf %lf %d", &x1, &y1, &x2, &y2, &x3, &y3, &n);
  while (n--) {
    scanf("%lf%lf", &x4, &y4);
    t3 = (dis(x4, y4, x3, y3)) * 2;
    sum += t3;
    t4 = dis(x4, y4, x1, y1) + (t3 / 2);
    t4 = t4 - t3;
    if (t4 < maxa) {
      maxa2 = maxa;
      maxa = t4;
      i1 = n;
    } else if (t4 < maxa2)
      maxa2 = t4;
    t4 = dis(x4, y4, x2, y2) + (t3 / 2);
    t4 = t4 - t3;
    if (t4 < maxb) {
      maxb2 = maxb;
      maxb = t4;
      i2 = n;
    } else if (t4 < maxb2)
      maxb2 = t4;
  }
  if (i1 == i2) {
    t4 = min(maxa, (maxa2 + maxb));
    t4 = min(t4, (maxa + maxb2));
    t4 = min(t4, maxb);
  } else {
    t4 = min(maxa, maxb);
    t4 = min(t4, (maxa + maxb));
  }
  sum += t4;
  printf("%0.9lf", sum);
  return 0;
}
