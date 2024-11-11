#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double inf = 1e18;
bool lt(double a, double b) { return b - a > eps; }
struct pt {
  double x, y;
  int id;
  bool operator<(const pt& other) const {
    if (y != other.y) {
      return y < other.y;
    }
    return x < other.x;
  }
};
double dist(const pt& a, const pt& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  int n, k;
  cin >> n >> k;
  --k;
  vector<pt> p(n + 1);
  for (int i = 0; i <= n; ++i) {
    cin >> p[i].x;
    p[i].y = 0;
    p[i].id = i;
  }
  cin >> p[n].y;
  sort((p).begin(), (p).end());
  for (int i = 0; i <= n; ++i) {
    if (p[i].id == k) {
      k = i;
      break;
    }
  }
  cout << fixed;
  cout.precision(12);
  double ans = 0;
  if (k == n) {
    double val1 = dist(p[0], p[n]);
    double val2 = dist(p[n - 1], p[n]);
    if (lt(val1, val2)) {
      ans = val1 + p[n - 1].x - p[0].x;
    } else {
      ans = val2 + p[n - 1].x - p[0].x;
    }
    cout << ans << "\n";
    return 0;
  }
  ans = inf;
  for (int i = 0; i <= k; ++i) {
    double val1 = p[k].x - p[i].x + p[n - 1].x - p[i].x + dist(p[n - 1], p[n]);
    double val2 = p[n - 1].x - p[k].x + p[n - 1].x - p[i].x + dist(p[i], p[n]);
    double relax;
    if (lt(val1, val2)) {
      relax = val1;
    } else {
      relax = val2;
    }
    if (i) {
      val1 = dist(p[n], p[i - 1]) + p[i - 1].x - p[0].x;
      val2 = dist(p[n], p[0]) + p[i - 1].x - p[0].x;
      if (lt(val1, val2)) {
        relax += val1;
      } else {
        relax += val2;
      }
    }
    if (lt(relax, ans)) {
      ans = relax;
    }
  }
  for (int i = k; i < n; ++i) {
    double val1 = p[k].x - p[0].x + p[i].x - p[0].x + dist(p[i], p[n]);
    double val2 = p[i].x - p[k].x + p[i].x - p[0].x + dist(p[0], p[n]);
    double relax;
    if (lt(val1, val2)) {
      relax = val1;
    } else {
      relax = val2;
    }
    if (i != n - 1) {
      val1 = dist(p[n], p[i + 1]) + p[n - 1].x - p[i + 1].x;
      val2 = dist(p[n], p[n - 1]) + p[n - 1].x - p[i + 1].x;
      if (lt(val1, val2)) {
        relax += val1;
      } else {
        relax += val2;
      }
    }
    if (lt(relax, ans)) {
      ans = relax;
    }
  }
  cout << ans << "\n";
}
