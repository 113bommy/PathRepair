#include <bits/stdc++.h>
using namespace std;
const double eps = 0.25e-6;
double func_0(double v, double r, double t) {
  return r * sin(v / r * t) + v * t;
}
double func_pi(double v, double r, double t) {
  return -r * sin(v / r * t) + v * t;
}
int main() {
  int n, r, v;
  cin >> n >> r >> v;
  for (int i = 0; i < n; ++i) {
    int s, f;
    scanf("%d%d", &s, &f);
    double d = (f - s) / 2.0;
    double t1, t2;
    double lt = 0, rt = (d + r) / v;
    while (abs(rt - lt) > eps) {
      double m = (lt + rt) / 2;
      if (func_0(v, r, m) > d) {
        rt = m;
      } else {
        lt = m;
      }
    }
    t1 = lt;
    lt = 0;
    rt = (d + r) / v;
    while (abs(rt - lt) > eps) {
      double m = (lt + rt) / 2;
      if (func_pi(v, r, m) > d) {
        rt = m;
      } else {
        lt = m;
      }
    }
    t2 = lt;
    printf("%.6f\n", min(t1, t2) * 2);
  }
  return 0;
}
