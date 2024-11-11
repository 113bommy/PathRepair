#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1), eps = 1e-4;
struct point2d {
  double x, y;
  point2d() {}
  point2d(double x, double y) : x(x), y(y) {}
  point2d &operator+=(const point2d &t) {
    x += t.x;
    y += t.y;
    return *this;
  }
  point2d &operator-=(const point2d &t) {
    x -= t.x;
    y -= t.y;
    return *this;
  }
  point2d &operator*=(double t) {
    x *= t;
    y *= t;
    return *this;
  }
  point2d &operator/=(double t) {
    x /= t;
    y /= t;
    return *this;
  }
  point2d operator+(const point2d &t) const { return point2d(*this) += t; }
  point2d operator-(const point2d &t) const { return point2d(*this) -= t; }
  point2d operator*(double t) const { return point2d(*this) *= t; }
  point2d operator/(double t) const { return point2d(*this) /= t; }
  bool operator==(point2d p) {
    if (abs(p.x - x) < eps && abs(p.y - y) < eps) return 1;
    return 0;
  }
};
point2d operator*(double a, point2d b) { return b * a; }
double dot(point2d a, point2d b) { return a.x * b.x + a.y * b.y; }
double cross(point2d a, point2d b) { return a.x * b.y - a.y * b.x; }
double norm(point2d a) { return dot(a, a); }
double abs(point2d a) { return sqrtl(norm(a)); }
double proj_parallel(point2d a, point2d b) { return dot(a, b) / abs(b); }
double proj_perpendicular(point2d a, point2d b) { return cross(a, b) / abs(b); }
double distance_pt_line(point2d a, point2d b, point2d p) {
  return abs(proj_perpendicular(p - b, a - b));
}
double angle(point2d a, point2d b) {
  return acos(dot(a, b) / (abs(a) * abs(b)));
}
double angle(point2d a) { return acos(a.x / abs(a)); }
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
  return a1 + (cross(d2, a1 - a2) / cross(d1, d2)) * d1;
}
ostream &operator<<(ostream &out, const point2d p) {
  out << p.x << " " << p.y;
  return out;
}
point2d rotate90(point2d p1) {
  point2d p;
  p.x = p1.y, p.y = -p1.x;
  return p;
}
point2d circumcenter(point2d p1, point2d p2, point2d p3) {
  return intersect((p1 + p2) / 2, rotate90(p2 - p1), (p2 + p3) / 2,
                   rotate90(p3 - p2));
}
double area_of_triangle(point2d p1, point2d p2, point2d p3) {
  return (cross(p2, p1) * dot(p2, p1) + cross(p3, p1) * dot(p3, p1)) /
         (2 * dot(p1, p1));
}
bool point_in_segment(point2d p, point2d p1, point2d p2) {
  if (abs(cross(p1 - p, p2 - p)) > eps) return 0;
  return (dot(p1 - p, p2 - p) < eps);
}
bool point_in_or_on_traingle(point2d p1, point2d p2, point2d p3, point2d p) {
  return abs(abs(cross(p1 - p, p2 - p)) + abs(cross(p2 - p, p3 - p)) +
             abs(cross(p3 - p, p1 - p)) - abs(cross(p2 - p1, p3 - p1))) < eps;
}
bool point_inside_traingle(point2d p1, point2d p2, point2d p3, point2d p) {
  if (point_in_segment(p, p1, p2) || point_in_segment(p, p2, p3) ||
      point_in_segment(p, p3, p1))
    return 0;
  return point_in_or_on_traingle(p1, p2, p3, p);
}
pair<bool, point2d> intersection_pt_of_segments(point2d a1, point2d b1,
                                                point2d a2, point2d b2) {
  point2d p;
  if (abs(cross(b1 - a1, b2 - a2)) < eps || a1 == a2 || b1 == b2 || a1 == b2 ||
      b1 == a2) {
    return {0, p};
  }
  p = intersect(a1, b1 - a1, a2, b2 - a2);
  if (point_in_segment(p, a1, b1) && point_in_segment(p, a2, b2)) {
    return {1, p};
  }
  return {0, p};
}
vector<array<point2d, 3>> triangle;
vector<array<point2d, 2>> seg;
vector<array<point2d, 2>> v;
int main() {
  double ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    point2d p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    triangle.push_back({p1, p2, p3});
    seg.push_back({p1, p2}), seg.push_back({p2, p3}), seg.push_back({p3, p1});
  }
  for (int i = 0; i < seg.size(); i++) {
    vector<array<point2d, 2>> s;
    s.push_back(seg[i]);
    for (int j = 0; j < seg.size(); j++) {
      vector<array<point2d, 2>> ns;
      for (int k = 0; k < s.size(); k++) {
        auto z =
            intersection_pt_of_segments(seg[j][0], seg[j][1], s[k][0], s[k][1]);
        if (z.first) {
          ns.push_back({s[k][0], z.second});
          ns.push_back({z.second, s[k][1]});
        } else {
          ns.push_back({s[k][0], s[k][1]});
        }
      }
      s = ns;
    }
    for (auto elm : s) {
      v.push_back(elm);
    }
  }
  for (auto elm : v) {
    bool b = 1;
    point2d p = (elm[0] + elm[1]) / 2;
    for (int i = 0; i < triangle.size(); i++) {
      if (point_inside_traingle(triangle[i][0], triangle[i][1], triangle[i][2],
                                p)) {
        b = 0;
        break;
      }
    }
    if (b) ans += abs(elm[1] - elm[0]);
  }
  cout << setprecision(10) << fixed;
  cout << ans << '\n';
  return 0;
}
