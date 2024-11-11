#include <bits/stdc++.h>
using namespace std;
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gli() {
  long long a;
  scanf("%lld", &a);
  return a;
}
double search(double a) {
  double l = 0;
  double r = 3.14159265358979323846264338327950288;
  while (r - l > 1e-10) {
    double m = (l + r) / 2.0;
    if (m + sin(m) > a) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}
int main() {
  int n = gi();
  double r = gi();
  double v = gi();
  double c = 2.0 * 3.14159265358979323846264338327950288 * r;
  double t1 = c / v;
  for (int i = 0; i < n; i++) {
    int sii = gi();
    int fii = gi();
    double d = fii - sii;
    double num = floor(d / c);
    double res = t1 * num;
    d = (d - num * c) / 2.0;
    double th = search(d / r);
    res += th * t1 / 3.14159265358979323846264338327950288;
    printf("%.10lf\n", res);
  }
  return 0;
}
