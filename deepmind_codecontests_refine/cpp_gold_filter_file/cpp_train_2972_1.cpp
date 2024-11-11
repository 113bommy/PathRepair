#include <bits/stdc++.h>
using namespace std;
class Point {
 public:
  long long x, y;
  Point(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
};
long long getArea(Point a, Point b, Point c) {
  long long area = 0;
  area += (b.x - a.x) * (b.y + a.y);
  area += (c.x - b.x) * (c.y + b.y);
  area += (a.x - c.x) * (a.y + c.y);
  if (area < 0) {
    area = -area;
  }
  return (area);
}
int clockwise(Point a, Point b, Point c) {
  long long area = 0;
  area += (b.x - a.x) * (b.y + a.y);
  area += (c.x - b.x) * (c.y + b.y);
  area += (a.x - c.x) * (a.y + c.y);
  if (area == 0) {
    return 0;
  } else {
    if (area > 0) {
      return 1;
    } else {
      return -1;
    }
  }
}
bool cmp(Point a, Point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
vector<Point> hull(vector<Point> p) {
  sort(begin(p), end(p), cmp);
  int n = p.size(), m = 1;
  vector<Point> e;
  e.emplace_back(p[0]);
  for (int i = 1; i < n; ++i) {
    while (m >= 2 && clockwise(e[m - 2], e[m - 1], p[i]) != 1) {
      e.pop_back();
      --m;
    }
    e.emplace_back(p[i]);
    ++m;
  }
  int old = m - 1;
  for (int i = n - 2; i >= 0; --i) {
    while (m - old >= 2 && clockwise(e[m - 2], e[m - 1], p[i]) != 1) {
      e.pop_back();
      --m;
    }
    e.emplace_back(p[i]);
    ++m;
  }
  e.pop_back();
  --m;
  return e;
}
long long n, S;
vector<Point> p;
int main() {
  cin >> n >> S;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p.emplace_back(x, y);
  }
  p = hull(p);
  n = p.size();
  long long ii = 0, jj = 1, kk = 2, area = getArea(p[0], p[1], p[2]);
  for (int i = 0; i < n - 2; ++i) {
    Point a = p[i];
    int k = 0;
    for (int j = 1; j <= n - 2; ++j) {
      Point b = p[(i + j) % n];
      if (k > 0) --k;
      if (area < getArea(a, b, p[(i + j + k) % n])) {
        area = getArea(a, b, p[(i + j + k) % n]);
        ii = i;
        jj = (i + j) % n;
        kk = (i + j + k) % n;
      }
      for (k; k + j <= n - 1; ++k) {
        Point c = p[(i + j + k) % n];
        if (getArea(a, b, c) > getArea(a, b, p[(i + j + k + 1) % n])) {
          break;
        }
        if (area < getArea(a, b, p[(i + j + k) % n])) {
          area = getArea(a, b, p[(i + j + k) % n]);
          ii = i;
          jj = (i + j) % n;
          kk = (i + j + k) % n;
        }
      }
      if (area < getArea(a, b, p[(i + j + k) % n])) {
        area = getArea(a, b, p[(i + j + k) % n]);
        ii = i;
        jj = (i + j) % n;
        kk = (i + j + k) % n;
      }
    }
  }
  Point a = p[ii], b = p[jj], c = p[kk];
  cout << -a.x + b.x + c.x << " " << -a.y + b.y + c.y << "\n";
  cout << +a.x - b.x + c.x << " " << +a.y - b.y + c.y << "\n";
  cout << +a.x + b.x - c.x << " " << +a.y + b.y - c.y << "\n";
}
