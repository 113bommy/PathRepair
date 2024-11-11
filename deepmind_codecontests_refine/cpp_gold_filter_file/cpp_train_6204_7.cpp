#include <bits/stdc++.h>
using namespace std;
void Draganov47() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
}
struct pt {
  double x, y;
};
struct vc {
  double x, y;
};
vc gv(pt a, pt b) { return {b.x - a.x, b.y - a.y}; }
double ks(vc a, vc b) { return (a.x * b.y) - (a.y * b.x); }
double sc(vc a, vc b) { return (a.x + b.x) - (a.y + b.y); }
const int MAX = 1e5 + 47;
struct mause {
  pt a, b, speed;
};
int n;
pt f, s;
mause a[MAX];
int main() {
  Draganov47();
  cin >> n;
  cin >> f.x >> f.y >> s.x >> s.y;
  double maxX = max(f.x, s.x);
  double minX = min(f.x, s.x);
  double maxY = max(f.y, s.y);
  double minY = min(f.y, s.y);
  vector<pair<double, int> > sl;
  for (int i = 1; i <= n; i++)
    cin >> a[i].a.x >> a[i].a.y >> a[i].speed.x >> a[i].speed.y;
  for (int i = 1; i <= n; i++) {
    double min_x = -1, max_x = -1;
    double l = 0, r = 1e6;
    for (int z = 1; z <= 100; z++) {
      double m = (l + r) / 2.0;
      if (a[i].speed.x > 0) {
        if (m * a[i].speed.x + a[i].a.x <= minX)
          l = m;
        else
          r = m;
      } else {
        if (m * a[i].speed.x + a[i].a.x <= minX)
          r = m;
        else
          l = m;
      }
    }
    min_x = l;
    l = 0, r = 1e6;
    for (int z = 1; z <= 100; z++) {
      double m = (l + r) / 2.0;
      if (a[i].speed.x > 0) {
        if (m * a[i].speed.x + a[i].a.x <= maxX)
          l = m;
        else
          r = m;
      } else {
        if (m * a[i].speed.x + a[i].a.x <= maxX)
          r = m;
        else
          l = m;
      }
    }
    max_x = l;
    double min_y = -1, max_y = -1;
    l = 0, r = 1e6;
    for (int z = 1; z <= 100; z++) {
      double m = (l + r) / 2.0;
      if (a[i].speed.y > 0) {
        if (m * a[i].speed.y + a[i].a.y <= minY)
          l = m;
        else
          r = m;
      } else {
        if (m * a[i].speed.y + a[i].a.y <= minY)
          r = m;
        else
          l = m;
      }
    }
    min_y = l;
    l = 0, r = 1e6;
    for (int z = 1; z <= 100; z++) {
      double m = (l + r) / 2.0;
      if (a[i].speed.y > 0) {
        if (m * a[i].speed.y + a[i].a.y <= maxY)
          l = m;
        else
          r = m;
      } else {
        if (m * a[i].speed.y + a[i].a.y <= maxY)
          r = m;
        else
          l = m;
      }
    }
    max_y = l;
    if (a[i].speed.y > 0 && a[i].a.y <= maxY) a[i].a.y = maxY;
    if (a[i].speed.y < 0 && a[i].a.y >= maxY) a[i].a.y = maxY;
    if (a[i].speed.x > 0 && a[i].a.x <= maxX) a[i].a.x = maxX;
    if (a[i].speed.x < 0 && a[i].a.x >= maxX) a[i].a.x = maxX;
    if ((a[i].a.y <= maxY || a[i].a.y >= minY) && a[i].speed.x == 0 &&
        (a[i].a.x == maxX || a[i].a.x == minX)) {
      cout << -1;
      return 0;
    }
    if ((a[i].a.x <= maxX || a[i].a.x >= minX) && a[i].speed.y == 0 &&
        (a[i].a.y == maxY || a[i].a.y == minY)) {
      cout << -1;
      return 0;
    }
    if (max_y < min_y) swap(max_y, min_y);
    if (max_x < min_x) swap(max_x, min_x);
    double min_time = max(min_x, min_y);
    double max_time = min(max_x, max_y);
    if (min_time + 0.000000000001 > max_time) {
      cout << -1;
      return 0;
    }
    sl.push_back({min_time, 1});
    sl.push_back({max_time - 0.00000000001, -1});
  }
  int status = 0;
  sort(sl.begin(), sl.end());
  for (int i = 0; i < sl.size(); i++) {
    status += sl[i].second;
    if (status == n) {
      cout << sl[i].first;
      return 0;
    }
  }
  cout << -1;
}
