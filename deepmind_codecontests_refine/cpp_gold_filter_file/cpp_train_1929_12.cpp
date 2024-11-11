#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point operator-(const Point &r) {
    Point p;
    p.x = x - r.x;
    p.y = y - r.y;
    return p;
  }
  Point operator+(const Point &r) {
    Point p;
    p.x = x + r.x;
    p.y = y + r.y;
    return p;
  }
  Point rotate(double ang) {
    double ty = y * cos(ang) + x * sin(ang);
    x = x * cos(ang) - y * sin(ang);
    y = ty;
    return *this;
  }
};
int main() {
  Point p[7], o, v;
  double a, b, c, d;
  cout << fixed << setprecision(9);
  while (cin >> o.x >> o.y >> v.x >> v.y >> a >> b >> c >> d) {
    p[0] = o;
    p[0].y += b;
    p[1] = o;
    p[1].x -= a / 2;
    p[2] = o;
    p[2].x -= c / 2;
    p[3] = p[2];
    p[3].y -= d;
    p[4] = p[3];
    p[4].x += c;
    p[5] = p[4];
    p[5].y += d;
    p[6] = o;
    p[6].x += a / 2;
    double ang = -atan2(v.x, v.y);
    for (int i = int(0); i < int(7); i++) {
      p[i] = (p[i] - o).rotate(ang) + o;
      cout << p[i].x << " " << p[i].y << endl;
    }
  }
  return 0;
}
