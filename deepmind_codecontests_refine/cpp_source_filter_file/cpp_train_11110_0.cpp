#include <bits/stdc++.h>
using namespace std;
double a, b, l;
double w;
inline double f(double x) {
  return (a * cos(x) + b * sin(x) - l * cos(x) * sin(x));
}
void solve() {
  double r1 = 0, r2 = acos(0.0);
  for (int i = 0; i < 1000; i++) {
    double r11 = (2.0 / 3.0) * r1 + (1.0 / 3.0) * r2;
    double r22 = (1.0 / 3.0) * r1 + (2.0 / 3.0) * r2;
    if (f(r11) > f(r22))
      r1 = r11;
    else
      r2 = r22;
  }
  w = max(w, f((r1 + r2) / 2));
  w = min(w, l);
  if (w < 1e-7)
    printf("My poor head = (\n");
  else
    printf("%.7lf\n", w);
}
int main() {
  scanf("%lf%lf%lf", &a, &b, &l);
  w = 0;
  if (a > b) swap(a, b);
  if (l <= a) {
    printf("%.7lf\n", l);
    return 0;
  }
  if (l <= b) {
    printf("%.7lf\n", a);
    return 0;
  }
  solve();
  return 0;
}
