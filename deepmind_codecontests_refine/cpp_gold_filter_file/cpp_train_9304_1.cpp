#include <bits/stdc++.h>
using namespace std;
int w, h, a;
double alpha;
double s, s1, s2;
double calculate(int w, int h) {
  return 1.0 / 8.0 * tan(alpha) *
         pow((double(w) - double(h) * tan(alpha / 2.0)), 2.0);
}
bool less_or_equal(double a1, double a2) {
  if (abs(a1 - a2) <= 0.000000000001L || a1 > a2) {
    return true;
  }
  return false;
}
void check() {
  if (h > w) {
    swap(h, w);
  }
  if (a > 90) {
    a = 90 - (a - 90);
    alpha = (double(a)) * 3.141592653589L / 180;
  }
}
int main() {
  scanf("%d%d%d", &w, &h, &a);
  alpha = double(a) * 3.141592653589L / 180;
  s = double(w) * double(h);
  check();
  if (less_or_equal(2.0 * atan(double(h) / double(w)), alpha)) {
    s1 = calculate(w, h);
    s2 = calculate(h, w);
    printf("%lf\n", s - 2.0 * (s1 + s2));
  } else {
    printf("%lf\n", s - double(h) * (double(w) - double(h) / sin(alpha)));
  }
  return 0;
}
