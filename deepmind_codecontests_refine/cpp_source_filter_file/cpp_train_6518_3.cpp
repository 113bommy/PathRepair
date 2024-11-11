#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9 + 7;
const long long MAXL = 1e18;
const int N = 2 * 1e5 + 20;
const double eps = 1e-13;
struct Point {
  long long x1, x2, x3, x4, x5;
  Point operator+(Point b) const {
    return {x1 + b.x1, x2 + b.x2, x3 + b.x3, x4 + b.x4, x5 + b.x5};
  }
  Point operator-(Point b) const {
    return {x1 - b.x1, x2 - b.x2, x3 - b.x3, x4 - b.x4, x5 - b.x5};
  }
  long long operator*(Point b) const {
    return x1 * b.x1 + x2 * b.x2 + x3 * b.x3 + x4 * b.x4 + x5 * b.x5;
  }
};
double ang(Point a, Point b, Point c) {
  double ang = acos((double)((b - a) * (c - a)) /
                    (double)(((b - a) * (b - a)) * ((c - a) * (c - a))));
  if (!ang && (b - a) * (c - a) < 0)
    return acos(-1);
  else
    return ang;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> v;
  for (int i = 0; i < n; ++i) {
    Point p;
    cin >> p.x1 >> p.x2 >> p.x3 >> p.x4 >> p.x5;
    v.push_back(p);
  }
  if (n > 10) {
    cout << 0 << "\n";
    return 0;
  }
  vector<bool> ans(n, true);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      for (int k = 0; k < n; ++k) {
        if (k == j) continue;
        if (ang(v[i], v[j], v[k]) < acos(-1) / 2 - eps) ans[i] = false;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; ++i)
    if (ans[i]) sum++;
  cout << sum << "\n";
  for (int i = 0; i < n; ++i)
    if (ans[i]) cout << i + 1 << " ";
  return 0;
}
