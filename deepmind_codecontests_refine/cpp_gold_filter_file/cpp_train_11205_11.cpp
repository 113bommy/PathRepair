#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932384626433832795;
const int MAXN = 10;
const double EPS = 1e-10;
double x[MAXN], y[MAXN], r[MAXN];
vector<pair<double, double> > ans;
double sqr(double x) { return x * x; }
double dist(double x_1, double y_1, double x_2, double y_2) {
  return sqrt(sqr(x_1 - x_2) + sqr(y_1 - y_2));
}
int main() {
  int t1, t2;
  scanf("%d%d", &t1, &t2);
  for (int i = 0; (i) < (3); ++i) scanf("%lf%lf", &x[i], &y[i]);
  for (int i = (3) - 1; (i) >= 0; --i) x[i] -= x[0], y[i] -= y[0];
  double a = dist(x[0], y[0], x[1], y[1]);
  double b = dist(x[0], y[0], x[2], y[2]);
  double c = dist(x[1], y[1], x[2], y[2]);
  if (b + c <= a + t2) {
    printf("%.20f\n", min(b + c + t1, a + t2));
    return 0;
  }
  double ll = 0, rr = min(b + c + t1, a + t2);
  for (int qq = 0; (qq) < (1000); ++qq) {
    double mm = (ll + rr) / 2;
    r[0] = mm;
    r[1] = a + t2 - mm;
    r[2] = b + t1 - mm;
    if (r[0] < 0 || r[1] < 0 || r[2] < 0) {
      rr = mm;
      continue;
    }
    bool ok = 0;
    for (int i = 0; (i) < (3); ++i)
      for (int j = (i + 1); (j) < (3); ++j) {
        double d = dist(x[i], y[i], x[j], y[j]);
        if (d > r[i] + r[j] + EPS) continue;
        if (d + r[i] <= r[j] + EPS) {
          int g = 3 - i - j;
          if (dist(x[g], y[g], x[i], y[i]) <= r[i] + r[g]) ok = 1;
          continue;
        }
        if (d + r[j] <= r[i] + EPS) {
          int g = 3 - i - j;
          if (dist(x[g], y[g], x[j], y[j]) <= r[j] + r[g]) ok = 1;
          continue;
        }
        double aa = x[j] - x[i], bb = y[j] - y[i],
               cc = (r[i] * r[i] + d * d - r[j] * r[j]) / (2 * r[i]);
        ans.clear();
        if (bb == 0) {
          double x_0 = cc / aa, y_0 = sqrt(1 - x_0 * x_0);
          ans.push_back(make_pair(x_0, y_0));
          y_0 *= -1;
          ans.push_back(make_pair(x_0, y_0));
        } else {
          double a0 = (aa * aa) / (bb * bb) + 1,
                 b0 = (-2 * aa * cc / (bb * bb)),
                 c0 = (cc * cc) / (bb * bb) - 1;
          double dis = max(0.0, b0 * b0 - 4 * a0 * c0);
          double x_0, y_0;
          x_0 = (-b0 - sqrt(dis)) / (2 * a0);
          y_0 = (cc - aa * x_0) / bb;
          ans.push_back(make_pair(x_0, y_0));
          x_0 = (-b0 + sqrt(dis)) / (2 * a0);
          y_0 = (cc - aa * x_0) / bb;
          ans.push_back(make_pair(x_0, y_0));
        }
        for (int g = 0; (g) < (3); ++g)
          if (g != i && g != j)
            for (auto np : ans) {
              if (dist(x[g], y[g], x[i] + r[i] * np.first,
                       y[i] + r[i] * np.second) <= r[g] + EPS)
                ok = 1;
            }
      }
    if (ok)
      ll = mm;
    else
      rr = mm;
  }
  printf("%.20f\n", ll);
  return 0;
}
