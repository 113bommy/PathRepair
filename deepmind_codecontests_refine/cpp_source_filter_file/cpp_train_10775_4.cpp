#include <bits/stdc++.h>
using namespace std;
long double sq(long double a) { return a * a; }
int main() {
  long double x1, y1, r1, x2, y2, r2;
  scanf("%Lff%Lff%Lf%Lf%Lf%Lf", &x1, &y1, &r1, &x2, &y2, &r2);
  long double d = sqrt(sq(x2 - x1) + sq(y2 - y1));
  if (r1 + d <= r2 + 1e-9) {
    printf("%.12Lf\n", (double)2 * acos(0.0) * sq(r1));
    return 0;
  }
  if (r2 + d <= r1 + 1e-9) {
    printf("%.12Lf\n", (double)2 * acos(0.0) * sq(r2));
    return 0;
  }
  if (r1 + r2 < d) {
    printf("0\n");
    return 0;
  }
  long double one = (sq(d) + sq(r1) - sq(r2)) / (2 * d * r1);
  one = sq(r1) * (acos(one) - one * sin(acos(one)));
  long double two = (sq(d) + sq(r2) - sq(r1)) / (2 * d * r2);
  two = sq(r2) * (acos(two) - two * sin(acos(two)));
  printf("%.20Lf\n", (double)one + two);
}
