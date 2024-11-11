#include <bits/stdc++.h>
using namespace std;
double distance(double x1, double x2, double y1, double y2) {
  double a, b, ans;
  a = x2 - x1;
  b = y2 - y1;
  ans = sqrt(a * a + b * b);
  return ans;
}
int main() {
  double R, x1, y1, x2, y2, x3, y3, xap, yap, r, dis;
  scanf("%lf %lf %lf %lf %lf", &R, &x1, &y1, &x2, &y2);
  dis = distance(x1, x2, y1, y2);
  if (dis >= R) {
    printf("%lf %lf %lf", x1, y1, R);
    return 0;
  } else if (dis == 0) {
    xap = x1 + R / 2;
    yap = y1;
    r = R / 2;
  } else {
    x3 = ((dis + R) * x1 - R * x2) / dis;
    y3 = ((dis + R) * y1 - R * y2) / dis;
    xap = (x2 + x3) / 2;
    yap = (y2 + y3) / 2;
    r = distance(x2, xap, y2, yap);
  }
  printf("%.10lf %.10lf %.10lf", xap, yap, r);
  return 0;
}
