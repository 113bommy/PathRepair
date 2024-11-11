#include <bits/stdc++.h>
using namespace std;
const double PI = (acos(-1.0));
struct Point {
  long long x, y;
  Point(long long ix = 0, long long iy = 0) : x(ix), y(iy) {}
  Point &operator=(const Point &b) {
    x = b.x;
    y = b.y;
    return *this;
  }
  Point &operator-=(const Point &b) {
    x -= b.x;
    y -= b.y;
    return *this;
  }
  Point operator-(const Point &b) {
    Point res = *this;
    res -= b;
    return res;
  }
  friend long long dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
  }
  friend long long cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
  }
  friend double dist(const Point &a) {
    return sqrt(double(a.x * a.x + a.y * a.y));
  }
  friend double dist(const Point &a, const Point &b) {
    Point c = a;
    c -= b;
    return dist(c);
  }
  bool operator<(const Point &b) {
    const Point &a = *this;
    bool ka = a.y < 0 || a.y == 0 && a.x < 0;
    bool kb = b.y < 0 || b.y == 0 && b.x < 0;
    return ka < kb || ka == kb && cross(a, b) > 0;
  }
};
double getAnsver(Point p[1002], Point line[2], int n) {
  vector<pair<double, int>> ans;
  double a = dist(line[1]);
  int i;
  i = (1);
  for (int _n = (int)(n + 1), _di = (i > _n) ? -1 : 1; i != _n; i += _di) {
    long long y0 = cross(p[i] - line[0], line[1]);
    long long y1 = cross(p[i + 1] - line[0], line[1]);
    long long y2 = cross(p[i - 1] - line[0], line[1]);
    if (y0 == 0) {
      if ((y1 == 0) != (y2 == 0)) {
        double res = dist(p[i], line[0]);
        int flag = (y1 + y2 > 0) ? 1 : -1;
        ans.push_back(make_pair(res, flag));
      } else if (y1 < 0 != y2 < 0) {
        double res = dist(p[i], line[0]);
        ans.push_back(make_pair(res, 0));
      }
    } else if (y0 > 0 && y1 < 0 || y0 < 0 && y1 > 0) {
      double a0 = cross(p[i + 1] - p[i], line[0] - p[i]);
      double ca0 = dot(p[i + 1] - p[i], line[0] - p[i]);
      double cy0 = dot(p[i] - line[0], line[1]);
      double bb = dot(p[i] - line[0], p[i] - line[0]);
      double res = bb * a * a0 / (a0 * cy0 + ca0 * y0);
      ans.push_back(make_pair(res, 0));
    }
  }
  double result = 0.;
  bool inPolygon = false;
  sort(ans.begin(), ans.end());
  i = (0);
  for (int _n = (int)(ans.size()), _di = (i > _n) ? -1 : 1; i != _n; i += _di) {
    if (inPolygon) {
      result += ans[i].first;
      inPolygon = false;
      if (ans[i].second && i + 1 < ans.size() && ans[i + 1].second) {
        result += ans[i + 1].first - ans[i].first;
        if (ans[i].second * ans[i + 1].second == 1) {
          result -= ans[i + 1].first;
          inPolygon = true;
        }
        i++;
      }
    } else {
      result -= ans[i].first;
      inPolygon = true;
      if (ans[i].second && i + 1 < ans.size() && ans[i + 1].second) {
        if (ans[i].second * ans[i + 1].second == 1) {
          result += ans[i + 1].first;
          inPolygon = false;
        }
        i++;
      }
    }
  }
  ans.clear();
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, i, j;
  double x, y;
  Point p[1002], line[2];
  cin >> n >> m;
  i = (0);
  for (int _n = (int)(n), _di = (i > _n) ? -1 : 1; i != _n; i += _di) {
    cin >> x >> y;
    p[i] = Point(x * 100, y * 100);
  }
  p[n] = p[0];
  p[n + 1] = p[1];
  j = (0);
  for (int _n = (int)(m), _di = (j > _n) ? -1 : 1; j != _n; j += _di) {
    cin >> x >> y;
    line[0] = Point(x * 100, y * 100);
    cin >> x >> y;
    line[1] = Point(x * 100, y * 100);
    line[1] -= line[0];
    long long step = 3e7 / max(abs(line[1].x), abs(line[1].y));
    line[0].x += step * line[1].x;
    line[0].y += step * line[1].y;
    cout << setprecision(16) << getAnsver(p, line, n) / 100 << endl;
  }
  return 0;
}
