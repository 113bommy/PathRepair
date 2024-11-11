#include <bits/stdc++.h>
using namespace std;
bool inside(double angle, double r, double x, double y) {
  double cx = r * cos(angle), cy = r * sin(angle);
  double dx = cx - x, dy = cy - y;
  return dx * dx + dy * dy <= r * r;
}
double norm(double x) {
  if (x < 0) return norm(x + 2 * 3.14159265358979323846);
  return x - floor(x / (2.0 * 3.14159265358979323846)) * 2.0 *
                 3.14159265358979323846;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<double> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    int X, Y;
    cin >> X >> Y;
    x[i] = X;
    y[i] = Y;
  }
  double lo = 0, hi = 2e5;
  vector<pair<double, int>> events;
  for (int it = 0; it < 35; ++it) {
    events.clear();
    double r = (lo + hi) / 2.0;
    for (int i = 0; i < n; ++i) {
      if (x[i] == 0 && y[i] == 0) continue;
      double dist = sqrt(x[i] * x[i] + y[i] * y[i]);
      double angle = acos(x[i] / dist);
      if (y[i] < 0) angle = 2.0 * 3.14159265358979323846 - angle;
      if (!inside(angle, r, x[i], y[i])) continue;
      double da = acos(dist / (2.0 * r));
      events.emplace_back(norm(angle + da), i);
      events.emplace_back(norm(angle - da), i);
    }
    vector<bool> active(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (inside(0, r, x[i], y[i])) {
        cnt++;
        active[i] = true;
      }
    }
    bool can = cnt >= k;
    sort(events.begin(), events.end());
    for (auto e : events) {
      if (!active[e.second]) {
        cnt++;
        active[e.second] = true;
      } else {
        cnt--;
        active[e.second] = false;
      }
      if (cnt >= k) can = true;
    }
    if (can)
      hi = r;
    else
      lo = r;
  }
  cout << setprecision(10) << fixed << lo << "\n";
}
