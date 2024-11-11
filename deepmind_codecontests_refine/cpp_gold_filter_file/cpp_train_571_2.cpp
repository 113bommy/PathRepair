#include <bits/stdc++.h>
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
using namespace std;
int n;
pair<double, double> p[1234567], q;
double dist(pair<double, double> a, pair<double, double> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
bool small(pair<double, double> a, pair<double, double> b,
           pair<double, double> c) {
  double x1 = b.first - a.first;
  double y1 = b.second - a.second;
  double x2 = c.first - a.first;
  double y2 = c.second - a.second;
  return x1 * x2 + y1 * y2 > 0;
}
int Main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> q.first >> q.second;
  for (int i = 0; i < int(n); ++i) cin >> p[i].first >> p[i].second;
  double l = dist(p[0], q);
  double r = l;
  for (int i = 0; i < int(n); ++i) l = min(l, dist(p[i], q));
  for (int i = 0; i < int(n); ++i) r = max(r, dist(p[i], q));
  for (int i = 0; i < int(n); ++i) {
    if (small(p[i], q, p[(i + 1) % n]) && small(p[(i + 1) % n], q, p[i])) {
      double l1 = dist(p[i], q);
      double l2 = dist(p[(i + 1) % n], q);
      double len = dist(p[i], p[(i + 1) % n]);
      double s = (l1 + l2 + len) / 2;
      double area = sqrt(s * (s - l1) * (s - l2) * (s - len));
      l = min(l, area * 2 / len);
    }
  }
  cout << fixed << setprecision(19) << acos(-1.0) * (r * r - l * l) << endl;
  return 0;
}
int main() { return Main(); }
