#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-16;
const double inf = 1e9;
const double max_it = 68;
vector<int> x, y, r;
vector<int> in, out;
int x1, y_one, x2, y2;
double mx, my, d;
int n;
double len(double a, double b) { return sqrt(a * a + b * b); }
int GetSign(double a, double b, double c, double d) {
  double scalar = a * d - b * c;
  if (scalar < 0) {
    return -1;
  } else {
    return 1;
  }
}
double SolveFor(double a, double b) {
  vector<pair<double, int>> actions;
  int all_sign = GetSign(x2 - x1, y2 - y_one, a, b);
  for (int i = 0; i < n; ++i) {
    int sign = GetSign(x2 - x1, y2 - y_one, x[i] - x1, y[i] - y_one);
    double left = 0, right = inf;
    if (all_sign != sign) {
      swap(left, right);
    }
    for (int it = 0; fabs(left - right) > eps && it < max_it; ++it) {
      double mid = (left + right) / 2;
      double cx = mx + a * mid, cy = my + b * mid;
      double cr = len(cx - x1, cy - y_one);
      double l = len(cx - x[i], cy - y[i]);
      if (l < cr + r[i] + eps) {
        right = mid;
      } else {
        left = mid;
      }
    }
    double begin = left;
    left = 0, right = inf;
    if (all_sign != sign) {
      swap(left, right);
    }
    for (int it = 0; fabs(left - right) > eps && it < max_it; ++it) {
      double mid = (left + right) / 2;
      double cx = mx + a * mid, cy = my + b * mid;
      double cr = len(cx - x1, cy - y_one);
      double l = len(cx - x[i], cy - y[i]);
      if (cr - r[i] - eps < l) {
        left = mid;
      } else {
        right = mid;
      }
    }
    if (begin == 0 && left == 0) {
      continue;
    }
    actions.emplace_back(begin, -sign * all_sign);
    actions.emplace_back(right, sign * all_sign);
  }
  sort(actions.begin(), actions.end());
  double result = 0;
  int balance = 0;
  for (auto [dev, diff] : actions) {
    balance += diff;
    if (balance == 0) {
      result = dev;
      break;
    }
  }
  double cur = len(mx + a * result - x1, my + b * result - y_one);
  return cur;
}
int main() {
  cin >> x1 >> y_one >> x2 >> y2;
  cin >> n;
  x.resize(n);
  y.resize(n);
  r.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
  }
  mx = x1 + x2, my = y_one + y2;
  mx /= 2, my /= 2;
  d = len(mx - x1, my - y_one);
  bool check = true;
  for (int i = 0; i < n; ++i) {
    double l = len(mx - x[i], my - y[i]);
    if (d - r[i] - eps < l && l < d + r[i] + eps) {
      check = false;
      break;
    }
  }
  if (check) {
    cout << fixed << setprecision(16) << d << std::endl;
    return 0;
  }
  double a = y_one - y2, b = x2 - x1;
  a /= 2 * d, b /= 2 * d;
  double ans = min(SolveFor(a, b), SolveFor(-a, -b));
  cout << fixed << setprecision(16) << ans;
  return 0;
}
