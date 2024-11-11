#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point() { x = y = 0.0; }
  Point(double a, double b) : x(a), y(b) {}
  Point operator-(const Point &pepe) { return Point(x - pepe.x, y - pepe.y); }
  Point operator+(const Point &pepe) { return Point(x + pepe.x, y + pepe.y); }
  double operator^(const Point &pepe) { return x * pepe.y - y * pepe.x; }
  double operator*(Point pepe) { return x * pepe.x + y * pepe.y; }
};
vector<Point> uno;
vector<Point> dos;
double angle(Point a, Point o, Point b) {
  Point oa = a - o;
  Point ob = b - o;
  return acos((oa ^ ob) / sqrt((oa * oa) * (ob * ob)));
}
int cross(Point A, Point B, Point C) {
  double a = (B - A) ^ (C - A);
  if (fabs(a) < 1e-7) return 0;
  return (a < 0.0) ? -1 : 1;
}
bool onSegment(Point p1, Point p2, Point q1) {
  return (q1.x <= max(p1.x, p2.x) and q1.x >= min(p1.x, p2.x) and
          q1.y <= max(p1.y, p2.y) and q1.y >= min(p1.y, p2.y));
}
bool inteserct(Point p1, Point p2, Point q1, Point q2) {
  int o1, o2, o3, o4;
  o1 = cross(p1, p2, q1);
  o2 = cross(p1, p2, q2);
  o3 = cross(q1, q2, p1);
  o4 = cross(q1, q2, p2);
  if (o1 != o2 and o3 != o4) return true;
  if (o1 == 0 and onSegment(p1, p2, q1)) return true;
  if (o2 == 0 and onSegment(p1, p2, q2)) return true;
  if (o3 == 0 and onSegment(q1, q2, p1)) return true;
  if (o4 == 0 and onSegment(q1, q2, p2)) return true;
  return false;
}
bool inPolygon(Point p, int which) {
  double sum = 0.0;
  if (which == 1) {
    for (int i = 0; i < uno.size() - 1; i++) {
      if (cross(p, uno[i], uno[i + 1]) == 1)
        sum += angle(uno[i], p, uno[i + 1]);
      else
        sum -= angle(uno[i], p, uno[i + 1]);
    }
    return fabs(fabs(sum) - 2 * acos(-1)) < 1e-7;
  } else {
    for (int i = 0; i < dos.size() - 1; i++) {
      if (cross(p, dos[i], dos[i + 1]) == 1)
        sum += angle(dos[i], p, dos[i + 1]);
      else
        sum -= angle(dos[i], p, dos[i + 1]);
    }
    return fabs(fabs(sum) - 2 * acos(-1)) < 1e-7;
  }
}
bool check() {
  bool res;
  for (int i = 0; i < uno.size() - 1; i++) {
    for (int j = 0; j < dos.size() - 1; j++) {
      if (inteserct(uno[i], uno[i + 1], dos[j], dos[j + 1])) return true;
    }
  }
  return (inPolygon(uno[0], 2) or inPolygon(dos[0], 1));
}
int main() {
  int a, b;
  uno.resize(4);
  dos.resize(4);
  for (int i = 0; i < 4; i++) cin >> uno[i].x >> uno[i].y;
  uno.push_back(uno[0]);
  for (int i = 0; i < 4; i++) cin >> dos[i].x >> dos[i].y;
  dos.push_back(dos[0]);
  if (check())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
