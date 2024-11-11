#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
const int MAXM = 100000;
const double g = 9.8;
const double EPS = 1e-8;
double v0;
int n, m;
pair<double, double> ans[MAXN + 10];
struct Formula {
  double angle;
  Formula(double _angle) : angle(_angle) {}
  double at(double x) {
    double t = x / v0 / cos(angle);
    return v0 * sin(angle) * t - g * t * t / 2;
  }
  double zero() {
    double t = v0 * sin(angle) / (g / 2);
    return t * cos(angle) * v0;
  }
};
int main() {
  scanf("%d%lf", &n, &v0);
  vector<pair<double, int> > v;
  for (int i = 1; i <= n; i++) {
    double x;
    scanf("%lf", &x);
    v.push_back(make_pair(x, i));
  }
  sort(v.begin(), v.end());
  vector<pair<double, double> > wall;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    wall.push_back(make_pair(x, y));
  }
  sort(wall.begin(), wall.end());
  wall.push_back(make_pair(1e9, 0));
  int ptr = 0;
  for (size_t i = 0; i < v.size(); i++) {
    Formula form(v[i].first);
    while (form.at(wall[ptr].first) - wall[ptr].second > EPS) ptr++;
    if (form.at(wall[ptr].first) < 0) {
      ans[v[i].second] = make_pair(form.zero(), 0.);
    } else {
      ans[v[i].second] = make_pair(wall[ptr].first, form.at(wall[ptr].first));
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%.6f %.6f\n", ans[i].first, ans[i].second);
  return 0;
}
