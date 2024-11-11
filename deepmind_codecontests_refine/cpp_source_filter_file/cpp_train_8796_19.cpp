#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
int n, r, v;
int S, T;
double ask(double x, double y) {
  int q = x / y;
  return x - q * y;
}
int chk(double t) {
  double rad = ask(v * t, 2 * pi * r) / r / 2;
  return v * t + 2 * r * abs(sin(rad)) >= T - S;
}
int main() {
  scanf("%d %d %d", &n, &r, &v);
  while (n--) {
    scanf("%d %d", &S, &T);
    double l = 0, r = 1e18;
    double res;
    for (int i = 0; i < 50; i++) {
      double md = (l + r) / 2;
      if (chk(md)) {
        res = md;
        r = md;
      } else
        l = md;
    }
    printf("%.12lf\n", res);
  }
  return 0;
}
