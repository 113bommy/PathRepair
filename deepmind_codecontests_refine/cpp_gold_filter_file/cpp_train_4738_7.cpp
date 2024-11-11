#include <bits/stdc++.h>
int n, m;
struct Point {
  long double x, y;
  int seg;
  void read() {
    double xx, yy;
    scanf("%lf %lf", &xx, &yy);
    x = std::round(xx * 100);
    y = std::round(yy * 100);
  }
  bool operator==(const Point &s) const { return x == s.x && y == s.y; }
  bool operator<(const Point &s) const {
    return x < s.x || x == s.x && y < s.y;
  }
  long double distanceTo(const Point &s) const {
    return sqrt((x - s.x) * (x - s.x) + (y - s.y) * (y - s.y));
  }
};
std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << p.x / 100 << " " << p.y / 100 << " " << p.seg;
  return os;
}
struct Vector {
  long double dx, dy;
  Vector(const Point &p1, const Point &p2) : dx(p2.x - p1.x), dy(p2.y - p1.y) {}
  long double operator*(const Vector &sec) const {
    return dx * sec.dx + dy * sec.dy;
  }
};
struct Line {
  long double a, b, c;
  Line(const Point &p1, const Point &p2) {
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = -(a * p1.x + b * p1.y);
  }
  bool contains(const Point &p) { return a * p.x + b * p.y + c == 0; }
  bool cross(const Point &p1, const Point &p2, Point &r) const {
    Line s(p1, p2);
    long double d = a * s.b - s.a * b;
    if (d == 0) return false;
    r.x = (-c * s.b + s.c * b) / d;
    r.y = (-a * s.c + c * s.a) / d;
    return Vector(r, p1) * Vector(r, p2) < 0;
  }
};
std::vector<Point> p;
bool inCommonSegment(const Point &p1, const Point &p2, int &seg) {
  if (p1.seg < 0 || p2.seg < 0) return false;
  int adj1 = (p1.seg - 1 + n) % n;
  int adj2 = (p2.seg - 1 + n) % n;
  if (p1.seg == p2.seg || p1.seg == adj2) {
    seg = p1.seg;
    return true;
  }
  if (adj1 == p2.seg || adj1 == adj2) {
    seg = adj1;
    return true;
  }
  return false;
}
struct Segment {
  Point p1, p2;
  Segment(Point p1, Point p2) : p1(p1), p2(p2) {
    if (p2 < p1) std::swap(p1, p2);
  }
  bool operator<(const Segment &s) const { return p1 < s.p1; }
  long double dist() { return p1.distanceTo(p2); }
};
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    Point v;
    v.read();
    while (p.size() > 1 && Line(p[p.size() - 1], p[p.size() - 2]).contains(v)) {
      p.pop_back();
    }
    p.push_back(v);
  }
  if (Line(p[0], p[1]).contains(p.back())) {
    p[0] = p.back();
    p.pop_back();
  }
  n = p.size();
  for (int i = 0; i < n; i++) {
    p[i].seg = i;
  }
  for (int i = 0; i < m; i++) {
    Point v1, v2;
    v1.read();
    v2.read();
    Line line(v1, v2);
    std::vector<Point> p2;
    long double answer = 0;
    std::vector<Segment> s;
    for (int j1 = 0; j1 < n; j1++) {
      int j2 = (j1 + 1) % n;
      bool posA = line.contains(p[j1]);
      bool posB = line.contains(p[j2]);
      if (posA && posB) {
        s.push_back(Segment(p[j1], p[j2]));
      } else if (!posA && !posB) {
        Point c;
        if (line.cross(p[j1], p[j2], c)) {
          p2.push_back(c);
        }
      } else if (!posA && posB) {
        long double res1 = line.a * p[j1].x + line.b * p[j1].y + line.c;
        int j3 = (j2 + 1) % n;
        if (line.contains(p[j3])) {
          j3 = (j3 + 1) % n;
        }
        long double res2 = line.a * p[j3].x + line.b * p[j3].y + line.c;
        if (res1 * res2 < 0) {
          p2.push_back(p[j2]);
        }
      }
    }
    std::sort(p2.begin(), p2.end());
    for (int j = 0; j < (int)p2.size(); j += 2) {
      s.push_back(Segment(p2[j], p2[j + 1]));
    }
    std::sort(s.begin(), s.end());
    Point right;
    right.x = -1e9;
    right.y = -1e9;
    for (Segment &seg : s) {
      if (seg.p2 < right) continue;
      if (seg.p1 < right) seg.p1 = right;
      answer += seg.dist();
      right = seg.p2;
    }
    printf("%0.15f\n", (double)(answer / 100));
  }
}
