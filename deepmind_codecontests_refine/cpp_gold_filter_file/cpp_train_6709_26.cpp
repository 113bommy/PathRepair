#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const double eps = 1e-12, Pi = acos(-1.0);
pair<double, double> p[N], a[11];
double w, h, mn[11];
inline double dis(pair<double, double> a, pair<double, double> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
bool check(pair<double, double> a) {
  return a.first > -eps && a.first < w + eps && a.second > -eps &&
         a.second < h + eps;
}
int main() {
  int n;
  scanf("%lf%lf%d", &w, &h, &n);
  double x = 0.0, y = 0.0, mn2 = 0.0;
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &p[i].first, &p[i].second);
  for (int i = 1; i <= 10; ++i) {
    a[i].first = w * ((rand() % 100) / 100.0);
    a[i].second = h * ((rand() % 100) / 100.0);
    mn[i] = 0.0;
  }
  for (double d = sqrt(w * w + h * h); d > eps; d *= 0.99) {
    for (int i = 1; i <= 10; ++i) {
      for (int j = 0; j < 8; ++j) {
        pair<double, double> t;
        double tmn1 = 1e15, tmn2 = 1e15;
        double ang = (rand() % 100) / 100.0 * 2.0 * Pi;
        t.first = a[i].first + d * cos(ang);
        t.second = a[i].second + d * sin(ang);
        if (!check(t)) continue;
        for (int k = 1; k <= n; ++k) {
          double dist = dis(t, p[k]);
          if (dist < tmn1)
            tmn2 = tmn1, tmn1 = dist;
          else if (dist < tmn2)
            tmn2 = dist;
        }
        if (tmn2 > mn[i]) a[i] = t, mn[i] = tmn2;
      }
    }
  }
  double ans = 0.0;
  for (int i = 1; i <= 10; ++i) ans = max(ans, mn[i]);
  printf("%.10lf\n", sqrt(ans));
  return 0;
}
