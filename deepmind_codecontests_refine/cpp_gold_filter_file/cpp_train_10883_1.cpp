#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-12;
int main() {
  double x0, y0, v, t;
  scanf("%lf %lf %lf %lf", &x0, &y0, &v, &t);
  double r0 = v * t;
  int n;
  scanf("%d", &n);
  vector<pair<double, double> > list;
  while (n--) {
    double x, y, r;
    scanf("%lf %lf %lf", &x, &y, &r);
    double d = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
    if (d < r + eps) {
      printf("%lf\n", 1.0);
      return 0;
    }
    if (r + r0 < d - eps) continue;
    double mid = atan2(y - y0, x - x0);
    if (mid < 0) mid += 2 * pi;
    double range;
    double tan = sqrt(d * d - r * r);
    if (tan < r0 + eps)
      range = asin(r / d);
    else
      range = acos((r0 * r0 - r * r + d * d) / (2 * d * r0));
    double begin = mid - range;
    double end = mid + range;
    if (begin < 0)
      list.push_back(pair<double, double>(begin + 2 * pi, 2 * pi)), begin = 0;
    if (end > 2 * pi)
      list.push_back(pair<double, double>(0, end - 2 * pi)), end = 2 * pi;
    list.push_back(pair<double, double>(begin, end));
  }
  double sum = 0;
  double begin = -1;
  double end = -1;
  sort(list.begin(), list.end());
  for (auto p : list) {
    if (p.first < end)
      end = max(end, p.second);
    else {
      sum += (end - begin);
      begin = p.first;
      end = p.second;
    }
  }
  sum += (end - begin);
  printf("%lf\n", sum / (2 * pi));
}
