#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
struct Point {
  double x, y, z;
} p[10123];
double dist(Point &a, Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n + 1; ++i) cin >> p[i].x >> p[i].y >> p[i].z;
  double vp, vs;
  cin >> vp >> vs;
  Point start;
  cin >> start.x >> start.y >> start.z;
  int idx = 1;
  double cum_time = 0.0;
  while (idx <= n) {
    double time_s = dist(p[idx], p[idx - 1]) / vs,
           time_p = dist(start, p[idx]) / vp;
    if (cum_time + time_s - eps > time_p) break;
    cum_time += time_s;
    idx++;
  }
  if (idx == n + 1) return cout << "NO\n", 0;
  double l = 0, r = 1, mid = 0, time_p = 0, time_s = 0;
  Point pt;
  for (int i = 0; i < 200; ++i) {
    mid = (l + r) / 2;
    pt = (Point){p[idx - 1].x * mid + p[idx].x * (1.0 - mid),
                 p[idx - 1].y * mid + p[idx].y * (1.0 - mid),
                 p[idx - 1].z * mid + p[idx].z * (1.0 - mid)};
    time_s = dist(p[idx - 1], pt) / vs, time_p = dist(start, pt) / vp;
    if (cum_time + time_s > time_p)
      l = mid;
    else
      r = mid;
  }
  cout << "YES\n";
  cout << fixed << setprecision(10) << time_p << "\n";
  cout << fixed << setprecision(10) << pt.x << " " << pt.y << " " << pt.z
       << '\n';
}
