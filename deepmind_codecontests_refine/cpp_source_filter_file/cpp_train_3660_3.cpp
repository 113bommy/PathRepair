#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-15;
const long double LOL = 103213.0;
struct Point {
  long double x, y;
  Point() {}
  Point(long double x, long double y) : x(x), y(y) {}
};
struct Polygon {
  vector<Point> p;
};
struct Segment {
  Point p, p1;
};
struct Ray {
  Point p, p1;
};
struct Circle {
  long double x, y, r;
};
struct Vector {
  long double x, y;
  Vector() {}
  Vector(long double x, long double y) : x(x), y(y) {}
  Vector(Point p1, Point p2) {
    x = p2.x - p1.x;
    y = p2.y - p1.y;
  }
  Vector operator*(long double b) { return Vector(x * b, y * b); }
  Vector operator+(Vector v2) { return Vector(x + v2.x, y + v2.y); }
  Vector(Vector v1, Vector v2) {
    x = v1.x + v2.x;
    y = v1.y + v2.y;
  }
};
struct Line {
  long double a, b, c;
  Line() {}
  Line(long double a, long double b, long double c) : a(a), b(b), c(c) {}
  Line(Point p, Point p1) {
    a = p1.y - p.y;
    b = p.x - p1.x;
    c = -a * p.x - b * p.y;
  }
};
bool comp(pair<Point, long long> p, pair<Point, long long> p1) {
  if (p.first.y < p1.first.y ||
      p.first.y == p1.first.y && p.first.x < p1.first.x)
    return true;
  return false;
}
long long nod(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return nod(b, a % b);
}
long double vec_proiz(Vector vec1, Vector vec2) {
  return vec1.x * vec2.y - vec2.x * vec1.y;
}
long double vectorlength(Vector vec) {
  return sqrt(vec.x * vec.x + vec.y * vec.y);
}
long double scalar(Vector vec1, Vector vec2) {
  return (vec1.x * vec2.x + vec1.y * vec2.y);
}
long double distance(Point a, Point a1) {
  return sqrt((a1.x - a.x) * (a1.x - a.x) + (a.y - a1.y) * (a.y - a1.y));
}
long double angle(Point a, Point a1, Vector vec1) {
  Vector vec(a, a1);
  return acos(scalar(vec, vec1) / vectorlength(vec) / vectorlength(vec1));
}
long double angle1(Vector vec, Vector vec1) {
  return acos(scalar(vec, vec1) / vectorlength(vec) / vectorlength(vec1));
}
long double distance_from_point_to_line(Point a1, Line a) {
  return abs(a1.x * a.a + a1.y * a.b + a.c) / sqrt(a.a * a.a + a.b * a.b);
}
long double get_square_triangle(Vector vec, Vector vec1) {
  return abs(vec_proiz(vec, vec1) / 2.0);
}
long double get_square_polygon(vector<Point> polygon, Point p) {
  long double s = 0.0;
  for (long long i = 0; i < polygon.size(); ++i) {
    Vector vec(p, polygon[i]);
    Vector vec1(p, polygon[(i + 1) % polygon.size()]);
    s += get_square_triangle(vec, vec1);
  }
  return abs(s);
}
Point intersection_of_lines(Line l, Line l1) {
  Point p;
  if (l.a * l1.b - l.b * l1.a == 0.0 && l1.c * l.b - l.c * l1.b == 0.0 &&
      l1.a * l.c - l.a * l1.c == 0.0) {
    p.x = LOL;
    p.y = LOL;
    return p;
  }
  if (l.a * l1.b - l.b * l1.a == 0.0) {
    p.x = -LOL;
    p.y = -LOL;
    return p;
  }
  p.x = (l1.c * l.b - l.c * l1.b) / (l.a * l1.b - l.b * l1.a);
  p.y = (l1.a * l.c - l.a * l1.c) / (l.a * l1.b - l.b * l1.a);
  return p;
}
long long get_integer_points(Vector vec) {
  return 1 + nod(abs(vec.x), abs(vec.y));
}
long double polar_angle(Point p) { return atan2(p.y, p.x); }
long double distance_from_point_to_segment(Point p, Segment seg) {
  Vector vec1(seg.p, p);
  Vector vec2(seg.p, seg.p1);
  Vector vec3(seg.p1, p);
  Vector vec4(seg.p1, seg.p);
  Line l(seg.p, seg.p1);
  if ((scalar(vec1, vec2) > 0.0) && (scalar(vec3, vec4) > 0.0))
    return distance_from_point_to_line(p, l);
  else if (scalar(vec1, vec2) > 0.0)
    return distance(p, seg.p1);
  else
    return distance(p, seg.p);
}
long double distance_from_point_to_ray(Point p, Ray r) {
  Line l(r.p, r.p1);
  Vector vec(r.p, p), vec1(r.p, r.p1);
  if (scalar(vec, vec1) > 0.0) {
    return distance_from_point_to_line(p, l);
  } else {
    return distance(p, r.p);
  }
}
long double distance_from_segment_to_segment(Segment seg, Segment seg1) {
  Line l(seg.p, seg.p1);
  Line l1(seg1.p, seg1.p1);
  Point inter = intersection_of_lines(l, l1);
  if (inter.x == LOL && inter.y == LOL &&
      max(seg.p.y, seg.p1.y) >= min(seg1.p1.y, seg1.p.y) &&
      max(seg1.p.y, seg1.p1.y) >= min(seg.p1.y, seg.p.y) &&
      max(seg.p.x, seg.p1.x) >= min(seg1.p1.x, seg1.p.x) &&
      max(seg1.p.x, seg1.p1.x) >= min(seg.p1.x, seg.p.x))
    return 0.0;
  if (inter.x == LOL && inter.y == LOL || inter.x == -LOL && inter.y == -LOL)
    return min(distance_from_point_to_segment(seg.p, seg1),
               min(distance_from_point_to_segment(seg.p1, seg1),
                   min(distance_from_point_to_segment(seg1.p, seg),
                       distance_from_point_to_segment(seg1.p1, seg))));
  Vector vec(seg.p, inter);
  Vector vec1(seg.p, seg.p1);
  Vector vec2(seg.p1, inter);
  Vector vec3(seg.p1, seg.p);
  Vector vec4(seg1.p, inter);
  Vector vec5(seg1.p, seg1.p1);
  Vector vec6(seg1.p1, inter);
  Vector vec7(seg1.p1, seg1.p);
  if (scalar(vec, vec1) > 0.0 && scalar(vec2, vec3) > 0.0 &&
      scalar(vec4, vec5) > 0.0 && scalar(vec6, vec7) > 0.0)
    return 0.0;
  return min(distance_from_point_to_segment(seg.p, seg1),
             min(distance_from_point_to_segment(seg.p1, seg1),
                 min(distance_from_point_to_segment(seg1.p, seg),
                     distance_from_point_to_segment(seg1.p1, seg))));
}
long double distance_from_ray_to_ray(Ray r, Ray r1) {
  Line l(r.p, r.p1);
  Line l1(r1.p, r1.p1);
  Point inter = intersection_of_lines(l, l1);
  if (inter.x == LOL && inter.y == LOL) {
    Vector vec(r.p, r.p1);
    Vector vec1(r.p, r1.p);
    Vector vec2(r1.p, r1.p1);
    Vector vec3(r1.p, r.p);
    if (scalar(vec, vec1) > 0.0 || scalar(vec2, vec3) > 0.0)
      return 0.0;
    else
      return distance(r.p, r1.p);
  }
  if (inter.x != -LOL && inter.y != -LOL) {
    Vector vec(r.p, inter), vec1(r.p, r.p1), vec2(r1.p, inter),
        vec3(r1.p, r1.p1);
    if (scalar(vec, vec1) > 0.0 && scalar(vec2, vec3) > 0.0) return 0.0;
  }
  return min(distance_from_point_to_ray(r.p, r1),
             distance_from_point_to_ray(r1.p, r));
}
long double distance_from_line_to_line(Line l, Line l1) {
  Point inter = intersection_of_lines(l, l1);
  if (inter.x == LOL && inter.y == LOL) return 0.0;
  if (inter.x != -LOL && inter.y != -LOL) {
    return 0.0;
  }
  Point p;
  p.x = -(l1.a * l1.c) / (l1.a * l1.a + l1.b * l1.b);
  p.y = -(l1.b * l1.c) / (l1.a * l1.a + l1.b * l1.b);
  return distance_from_point_to_line(p, l);
}
long double distance_from_segment_to_ray(Segment seg, Ray r) {
  Line l(seg.p, seg.p1);
  Line l1(r.p, r.p1);
  Point inter = intersection_of_lines(l, l1);
  if (inter.x == LOL && inter.y == LOL) {
    Vector vec(r.p, r.p1);
    Vector vec1(r.p, seg.p);
    Vector vec2(r.p, seg.p1);
    if (scalar(vec, vec1) > 0.0 || scalar(vec, vec2) > 0.0)
      return 0.0;
    else
      return min(distance(r.p, seg.p), distance(r.p, seg.p1));
  }
  if (inter.x == -LOL && inter.y == -LOL) {
    Vector vec(r.p, seg.p);
    Vector vec1(r.p, seg.p1);
    Vector vec2(r.p, r.p1);
    if (scalar(vec, vec2) > 0.0 || scalar(vec1, vec2) > 0.0)
      return distance_from_point_to_line(seg.p1, l1);
    return distance_from_point_to_segment(r.p, seg);
  }
  Vector vec(seg.p, inter);
  Vector vec1(seg.p, seg.p1);
  Vector vec2(seg.p1, inter);
  Vector vec3(seg.p1, seg.p);
  if (scalar(vec, vec1) > 0.0 && scalar(vec2, vec3) > 0.0) return 0.0;
  return min(distance_from_point_to_segment(r.p, seg),
             min(distance_from_point_to_ray(seg.p, r),
                 distance_from_point_to_ray(seg.p1, r)));
}
long double distance_from_segment_to_line(Segment seg, Line l) {
  Line l1(seg.p, seg.p1);
  Point inter = intersection_of_lines(l, l1);
  if (inter.x == LOL && inter.y == LOL) {
    return 0.0;
  }
  if (inter.x == -LOL && inter.y == -LOL) {
    return distance_from_point_to_line(seg.p, l);
  }
  Vector vec(seg.p, seg.p1);
  Vector vec1(seg.p, inter);
  Vector vec2(seg.p1, seg.p);
  Vector vec3(seg.p1, inter);
  if (scalar(vec, vec1) > 0.0 && scalar(vec2, vec3) > 0.0) return 0.0;
  return min(distance_from_point_to_line(seg.p, l),
             distance_from_point_to_line(seg.p1, l));
}
long double distance_from_ray_to_line(Ray r, Line l) {
  Line l1(r.p, r.p1);
  Point inter = intersection_of_lines(l, l1);
  if (inter.x == LOL && inter.y == LOL) return 0.0;
  if (inter.x != -LOL && inter.y != -LOL) {
    Vector vec(r.p, r.p1);
    Vector vec1(r.p, inter);
    if (scalar(vec, vec1) > 0.0) return 0.0;
  }
  return distance_from_point_to_line(r.p, l);
}
int main() {
  Line line, new_line;
  Circle circle, circle1;
  Vector vec_r, vec_left, vec_right;
  long long a;
  string s;
  cin >> a;
  vector<pair<Point, long long> > pp;
  for (long long i = 0; i < a; ++i) {
    Point p;
    cin >> p.x >> p.y;
    pp.push_back(make_pair(p, i));
  }
  cin >> s;
  sort(pp.begin(), pp.end(), comp);
  Point p = pp[0].first;
  vector<long long> ot;
  ot.push_back(pp[0].second);
  vector<bool> vis(a, false);
  vis[pp[0].second] = true;
  for (long long i = 0; i < a - 2; ++i) {
    if (s[i] == 'L') {
      long long ot1 = -1;
      long double zn = 10000;
      for (long long j = 0; j < a; ++j) {
        if (vis[pp[j].second]) continue;
        if (ot1 == -1) {
          ot1 = j;
          continue;
        }
        Vector vec1(p, pp[ot1].first);
        Vector vec2(p, pp[j].first);
        if (vec_proiz(vec1, vec2) > 0.0) ot1 = j;
      }
      p = pp[ot1].first;
      ot.push_back(pp[ot1].second);
      vis[pp[ot1].second] = true;
    } else {
      long long ot1 = -1;
      long double zn = 10000;
      for (long long j = 0; j < a; ++j) {
        if (vis[pp[j].second]) continue;
        if (ot1 == -1) {
          ot1 = j;
          continue;
        }
        Vector vec1(p, pp[ot1].first);
        Vector vec2(p, pp[j].first);
        if (-vec_proiz(vec1, vec2) > 0.0) ot1 = j;
      }
      vis[pp[ot1].second] = true;
      p = pp[ot1].first;
      ot.push_back(pp[ot1].second);
    }
  }
  for (long long i = 0; i < a; ++i)
    if (!vis[i]) {
      ot.push_back(i);
      break;
    }
  for (long long i = 0; i < ot.size(); ++i) cout << ot[i] + 1 << " ";
}
