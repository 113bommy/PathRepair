#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &out, const vector<T> &data) {
  out << "[";
  for (int i = 0; i < data.size(); ++i)
    out << data[i] << (i == data.size() - 1 ? "" : ",");
  out << "]";
  return out;
}
template <class T>
ostream &operator<<(ostream &out, const set<T> &s) {
  out << "{";
  for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
    out << *itr << " ";
  out << "}";
  return out;
}
template <class T>
ostream &operator<<(ostream &out, const multiset<T> &s) {
  out << "{";
  for (typename multiset<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
    out << *itr << " ";
  out << "}";
  return out;
}
template <class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "(" << p.first << "," << p.second << ")";
  return out;
}
template <class T1, class T2>
ostream &operator<<(ostream &out, const map<T1, T2> &m) {
  for (typename map<T1, T2>::const_iterator itr = m.begin(); itr != m.end();
       ++itr)
    out << itr->first << "->" << itr->second << " ";
  return out;
}
const double eps = 1e-8;
const double pi = acos(-1.0);
const double INF = 1e20;
inline int sign(double d) { return d < -eps ? -1 : d > eps; }
inline double sqr(double x) { return x * x; }
struct Point {
  int id;
  double x, y;
  Point() {
    x = 0.0;
    y = 0.0;
  }
  Point(double nx, double ny) : x(nx), y(ny) {}
  Point turnLeft() const { return Point(-y, x); }
  Point turnRight() const { return Point(y, -x); }
  Point rotate(double ang) const {
    return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
  }
  inline double length() { return sqrt(x * x + y * y); }
  void normalize() {
    double r = length();
    if (sign(r) != 0) x /= r, y /= r;
  }
  inline bool equal(const Point &other) const {
    return sign(x - other.x) == 0 && sign(y - other.y) == 0;
  }
  friend ostream &operator<<(ostream &out, const Point &point) {
    out << "(" << point.x << "," << point.y << ")";
    return out;
  }
  friend istream &operator>>(istream &in, Point &point) {
    in >> point.x >> point.y;
    return in;
  }
};
bool comPointByX(const Point &a, const Point &b) { return a.x < b.x; }
bool comPointEqual(const Point &a, const Point &b) { return a.equal(b); }
inline Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
inline Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
inline Point operator*(const Point &a, double d) {
  return Point(a.x * d, a.y * d);
}
inline Point operator/(const Point &a, double d) {
  if (sign(d) == 0) return Point();
  return Point(a.x / d, a.y / d);
}
inline bool operator==(const Point &a, const Point &b) {
  return a.x == b.x && a.y == b.y;
}
inline bool operator!=(const Point &a, const Point &b) {
  return a.x != b.x || a.y != b.y;
}
inline double dist(const Point &a, const Point &b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
inline double sqrdist(const Point &a, const Point &b) {
  return sqr(a.x - b.x) + sqr(a.y - b.y);
}
inline double operator^(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
inline double cross(const Point &p, const Point &a, const Point &b) {
  return (a - p) ^ (b - p);
}
inline double operator*(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
inline double dot(const Point &p, const Point &a, const Point &b) {
  return (a - p) * (b - p);
}
inline double segDegree(const Point &p, const Point &a, const Point &b) {
  double d = dot(p, a, b);
  double cosd = d / dist(a, p) / dist(b, p);
  if (cosd > 1.0) cosd = 1.0;
  if (cosd < -1.0) cosd = -1.0;
  return acos(cosd);
}
inline double segDegree(double a, double b, double c) {
  double ret = a * a + b * b - c * c;
  ret = ret / a / b / 2;
  if (ret > 1.0) ret = 1.0;
  if (ret < -1.0) ret = -1.0;
  return acos(ret);
}
inline double triangleArea(double a, double b, double c) {
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
inline bool onSeg(const Point &p, const Point &a, const Point &b) {
  return (sign(cross(p, a, b)) == 0 && sign(dot(p, a, b)) <= 0);
}
inline bool onRay(const Point &p, const Point &a, const Point &b) {
  return (sign(cross(p, a, b)) == 0 && sign(dot(a, p, b)) >= 0);
}
inline bool onLine(const Point &p, const Point &a, const Point &b) {
  return sign(cross(p, a, b)) == 0;
}
pair<Point, Point> onLine(double A, double B, double C) {
  if (sign(A) == 0) return make_pair(Point(0, -C / B), Point(1, -C / B));
  if (sign(B) == 0) return make_pair(Point(-C / A, 0), Point(-C / A, 1));
  if (fabs(A + B + C) < eps)
    return make_pair(Point(-(C + B) / A, 1), Point(2, -(C + A * 2) / B));
  return make_pair(Point(-(C + B) / A, 1), Point(1, -(C + A) / B));
}
vector<Point> interLine(const Point &a, const Point &b, const Point &c,
                        const Point &d) {
  vector<Point> inters;
  double u = cross(a, c, b), v = cross(a, b, d);
  if (sign(u + v) == 0) return inters;
  Point p = (c * v + d * u) / (u + v);
  inters.push_back(p);
  return inters;
}
vector<Point> interSeg(const Point &a, const Point &b, const Point &c,
                       const Point &d) {
  vector<Point> inters = interLine(a, b, c, d);
  if (inters.size() == 0) return inters;
  const Point &p = inters[0];
  if (onSeg(p, a, b) && onSeg(p, c, d))
    return inters;
  else {
    inters.clear();
    return inters;
  }
}
pair<Point, Point> getVerticalEquallySegment(const Point &a, const Point &b) {
  Point mid = (a + b) / 2;
  Point dir = mid - a;
  dir = dir.turnLeft();
  Point begin = mid - dir;
  Point end = mid + dir;
  return make_pair(begin, end);
}
Point getMinimumDistPointOnLine(const Point &a, const Point &b,
                                const Point &p) {
  if (onLine(p, a, b)) return p;
  pair<Point, Point> vertical = getVerticalEquallySegment(a, b);
  const Point &q = p + (vertical.second - vertical.first);
  vector<Point> inter = interLine(a, b, p, q);
  return inter[0];
}
Point getMinimumDistPointOnSeg(const Point &a, const Point &b, const Point &p) {
  Point q = getMinimumDistPointOnLine(a, b, p);
  if (onSeg(q, a, b)) return q;
  if (dist(a, p) < dist(b, p))
    return a;
  else
    return b;
}
Point getMinimumDistPointOnRay(const Point &a, const Point &b, const Point &p) {
  Point q = getMinimumDistPointOnLine(a, b, p);
  if (onRay(q, a, b)) return q;
  if (dist(a, p) < dist(b, p))
    return a;
  else
    return b;
}
Point getReflectionPointByLine(const Point &a, const Point &b, const Point &p) {
  Point q = getMinimumDistPointOnLine(a, b, p);
  return q * 2 - p;
}
vector<Point> interCir(const Point &a, const Point &b, double r1, double r2) {
  vector<Point> ret;
  double d = dist(a, b), d1 = ((sqr(r1) - sqr(r2)) / d + d) / 2;
  if (sign(r1 + r2 - d) < 0 || sign(abs(r1 - r2) - d) > 0) return ret;
  Point mid = a + ((b - a) / d) * d1;
  if (sign(r1 + r2 - d) == 0) {
    ret.push_back(mid);
    return ret;
  }
  Point incr = (b - a).turnLeft() / d * sqrt(sqr(r1) - sqr(d1));
  ret.push_back(mid - incr);
  ret.push_back(mid + incr);
  return ret;
}
double interCirArea(Point a, Point b, double ra, double rb) {
  double d, dA, dB;
  d = dist(a, b);
  if ((d < eps) || (d + ra <= rb) || (d + rb <= ra))
    return sqr((rb < ra) ? rb : ra) * pi;
  if (d >= ra + rb) return 0;
  dA = (sqr(d) + sqr(ra) - sqr(rb)) / d / 2;
  dB = d - dA;
  return sqr(ra) * acos(dA / ra) - dA * sqrt(sqr(ra) - sqr(dA)) +
         sqr(rb) * acos(dB / rb) - dB * sqrt(sqr(rb) - sqr(dB));
}
vector<Point> interLineCir(const Point &o, double r, const Point &a,
                           const Point &b) {
  vector<Point> ret;
  double d = dist(a, b), h = fabs(cross(a, b, o)) / d;
  if (sign(r - h) < 0) return ret;
  double d1 = ((sqr(dist(o, a)) - sqr(dist(o, b))) / d + d) / 2;
  Point mid = a + (b - a) / d * d1;
  if (sign(r - h) == 0) {
    ret.push_back(mid);
    return ret;
  }
  Point incr = (b - a) / d * sqrt(sqr(r) - sqr(h));
  ret.push_back(mid - incr);
  ret.push_back(mid + incr);
  return ret;
}
vector<Point> interSegCir(const Point &o, double r, const Point &a,
                          const Point &b) {
  vector<Point> temp = interLineCir(o, r, a, b);
  vector<Point> ret;
  for (int i = 0; i < temp.size(); ++i)
    if (onSeg(temp[i], a, b)) ret.push_back(temp[i]);
  return ret;
}
vector<Point> tangentCirPoint(const Point &o, double r, const Point &a) {
  vector<Point> ret;
  double d = dist(a, o);
  if (sign(d - r) < 0) return ret;
  if (sign(r - d) == 0) {
    ret.push_back(a);
    return ret;
  }
  return interCir(o, a, r, sqrt(sqr(d) - sqr(r)));
}
inline bool inCircle(const Point &p, const pair<Point, double> &circle) {
  double dis = dist(p, circle.first);
  return sign(dis - circle.second) <= 0;
}
double distOnCircle(const Point &a, const Point &b, const Point &o, double r) {
  double costheta = (a - o) * (b - o) / r / r;
  double theta = acos(costheta);
  return r * theta;
}
pair<Point, double> minCoverCircle(const Point &a, const Point &b,
                                   const Point &c) {
  if (a.equal(b)) return make_pair((b + c) / 2, dist(b, c) / 2);
  if (b.equal(c)) return make_pair((c + a) / 2, dist(c, a) / 2);
  if (c.equal(a)) return make_pair((a + b) / 2, dist(a, b) / 2);
  if (onLine(a, b, c)) {
    if (onSeg(a, b, c)) return make_pair((b + c) / 2, dist(b, c) / 2);
    if (onSeg(b, a, c)) return make_pair((a + c) / 2, dist(a, c) / 2);
    return make_pair((a + b) / 2, dist(a, b) / 2);
  }
  pair<Point, double> minCircle;
  minCircle.second = INF;
  pair<Point, double> cir1 = make_pair((a + b) / 2, dist(a, b) / 2);
  pair<Point, double> cir2 = make_pair((b + c) / 2, dist(b, c) / 2);
  pair<Point, double> cir3 = make_pair((a + c) / 2, dist(a, c) / 2);
  if (inCircle(c, cir1) && cir1.second < minCircle.second) minCircle = cir1;
  if (inCircle(a, cir2) && cir2.second < minCircle.second) minCircle = cir2;
  if (inCircle(b, cir3) && cir3.second < minCircle.second) minCircle = cir3;
  Point mid1 = (a + b) / 2;
  Point mid2 = (b + c) / 2;
  Point turn1 = (b - a).turnLeft();
  Point turn2 = (c - b).turnLeft();
  turn1 = mid1 + turn1;
  turn2 = mid2 + turn2;
  vector<Point> inters = interLine(mid1, turn1, mid2, turn2);
  pair<Point, double> cir4 = make_pair(inters[0], dist(inters[0], a));
  if (cir4.second < minCircle.second) minCircle = cir4;
  return minCircle;
}
double getCircleTriangleInterArea(const Point &o, double r, const Point &a,
                                  const Point &b) {
  vector<Point> abcir = interSegCir(o, r, a, b);
  if (abcir.size() == 2 && dist(a, abcir[0]) > dist(a, abcir[1]))
    swap(abcir[0], abcir[1]);
  abcir.insert(abcir.begin(), a);
  abcir.push_back(b);
  double ret = 0;
  for (int i = 0; i < abcir.size() - 1; ++i) {
    Point &t1 = abcir[i];
    Point &t2 = abcir[i + 1];
    if (inCircle((t1 + t2) / 2, make_pair(o, r)))
      ret += fabs(cross(o, t1, t2) / 2);
    else
      ret += segDegree(o, t1, t2) * r * r * 0.5;
  }
  return ret;
}
class Polygon {
 public:
  vector<Point> pt;
  inline void clear() { pt.clear(); }
  inline int size() const { return (int)pt.size(); }
  inline void addPoint(Point a) { pt.push_back(a); }
  inline void removePoint() { pt.pop_back(); }
  inline Point &operator[](int offset) { return pt[offset]; }
  inline void getSeg(int offset, Point &a, Point &b) {
    a = pt[offset];
    b = pt[(offset + 1) % pt.size()];
  }
  int inside(const Point &p) {
    int N = (int)pt.size();
    bool positiveSign = false;
    bool negativeSign = false;
    for (int i = 0; i < N; ++i) {
      Point &now = pt[i];
      Point &next = pt[(i + 1) % N];
      Point t1 = next - now;
      Point t2 = p - next;
      int s = sign(t1 ^ t2);
      if (s == 0) {
        if (onSeg(p, now, next))
          return 0;
        else
          return -1;
      }
      if (s > 0) positiveSign = true;
      if (s < 0) negativeSign = true;
    }
    if (positiveSign && negativeSign)
      return -1;
    else
      return 1;
  }
  double interCirArea(const Point &o, double r) {
    int N = (int)pt.size();
    double ret = 0;
    for (int i = 0; i < N; ++i) {
      Point &now = pt[i];
      Point &next = pt[(i + 1) % N];
      double area = getCircleTriangleInterArea(o, r, now, next);
      if (cross(now, next, o) >= 0)
        ret += area;
      else
        ret -= area;
    }
    return ret;
  }
  int interCircle(const Point &o, double r, vector<Point> &inters) {
    inters.clear();
    bool ok = true;
    for (int i = 0; i < pt.size(); ++i)
      if (!inCircle(pt[i], make_pair(o, r))) ok = false;
    if (ok) return 1;
    if (inside(o) == 1) {
      double mindis = 1e20;
      for (int i = 0; i < pt.size(); ++i) {
        Point a = pt[i];
        Point b = pt[(i + 1) % pt.size()];
        Point p = getMinimumDistPointOnSeg(a, b, o);
        mindis = min(mindis, dist(p, o));
      }
      if (mindis >= r) return 2;
    }
    for (int i = 0; i < pt.size(); ++i) {
      Point a = pt[i];
      Point b = pt[(i + 1) % pt.size()];
      vector<Point> ps = interSegCir(o, r, a, b);
      inters.insert(inters.end(), ps.begin(), ps.end());
    }
    return inters.size() > 0 ? 3 : 4;
  }
  Point getMinDistPointInPolygon(const Point &p) {
    if (inside(p) >= 0) return p;
    int N = (int)pt.size();
    double minDis = INF;
    Point ret;
    for (int i = 0; i < N; ++i) {
      Point &a = pt[i];
      Point &b = pt[(i + 1) % N];
      Point nowMin = getMinimumDistPointOnSeg(a, b, p);
      double nowDis = dist(nowMin, p);
      if (nowDis < minDis) minDis = nowDis, ret = nowMin;
    }
    return ret;
  }
  Polygon cut(const Point &a, const Point &b) {
    Polygon newPoly;
    Point temp;
    for (unsigned int i = 0; i < pt.size(); i++) {
      Point &nowP = pt[i];
      Point &nextP = pt[(i + 1) % pt.size()];
      if (sign(cross(a, b, nowP)) <= 0) newPoly.addPoint(nowP);
      if (sign(cross(a, b, nowP)) * sign(cross(a, b, nextP)) < 0) {
        vector<Point> inters = interLine(nowP, nextP, a, b);
        if (inters.size() > 0) newPoly.addPoint(inters[0]);
      }
    }
    return newPoly;
  }
  vector<Point> polyInterLine(const Point &a, const Point &b) {
    int N = (int)pt.size();
    vector<Point> ret;
    Point temp;
    for (int i = 0; i < N; ++i) {
      Point &now = pt[i];
      Point &next = pt[(i + 1) % N];
      if (sign(cross(a, b, now)) * sign(cross(a, b, next)) <= 0) {
        vector<Point> inters = interLine(a, b, now, next);
        if (inters.size() > 0) ret.push_back(inters[0]);
      }
    }
    return ret;
  }
  double area() {
    int size = this->size();
    if (size <= 2) return 0.0;
    addPoint(this->pt[0]);
    double ans = 0;
    for (int i = 0; i < size; ++i) ans += (pt[i] ^ pt[i + 1]);
    removePoint();
    return fabs(ans / 2);
  }
  double length() {
    int size = this->size();
    addPoint(pt[0]);
    double ans = 0;
    for (int i = 0; i < size; ++i) ans += dist(pt[i], pt[i + 1]);
    removePoint();
    return ans;
  }
  pair<Point, Point> getDiameter() {
    if (this->size() == 0) return make_pair(Point(0, 0), Point(0, 0));
    if (this->size() == 1) return make_pair(pt[0], pt[0]);
    if (this->size() == 2) return make_pair(pt[0], pt[1]);
    pair<Point, Point> answer;
    double diameter = 0.0;
    for (unsigned int i = 0; i < pt.size(); ++i)
      for (unsigned int j = i + 1; j < pt.size(); ++j) {
        double now = sqrdist(pt[i], pt[j]);
        if (now > diameter) {
          diameter = now;
          answer = make_pair(pt[i], pt[j]);
        }
      }
    return answer;
  }
  pair<Point, double> getMinCoverCircle() {
    vector<Point> &points = pt;
    if (points.size() == 0) return make_pair(Point(0, 0), 0);
    if (points.size() == 1) return make_pair(points[0], 0);
    if (points.size() == 2)
      return make_pair((points[0] + points[1]) / 2,
                       dist(points[0], points[1]) / 2);
    Point a = points[0];
    Point b = points[1];
    Point c = points[2];
    pair<Point, double> nowCircle = minCoverCircle(a, b, c);
    while (true) {
      bool found = false;
      double maxDis = nowCircle.second;
      Point maxDisPoint;
      for (unsigned int i = 0; i < points.size(); ++i) {
        double dis = dist(points[i], nowCircle.first);
        if (sign(dis - maxDis) > 0) {
          maxDis = dis;
          maxDisPoint = points[i];
          found = true;
        }
      }
      if (!found) break;
      Point d = maxDisPoint;
      Point newa, newb, newc;
      pair<Point, double> cir1 = minCoverCircle(a, b, d);
      pair<Point, double> cir2 = minCoverCircle(a, c, d);
      pair<Point, double> cir3 = minCoverCircle(b, c, d);
      pair<Point, double> minCircle;
      minCircle.second = INF;
      if (inCircle(c, cir1) && cir1.second < minCircle.second) {
        minCircle = cir1;
        c = d;
      } else {
        if (inCircle(b, cir2) && cir2.second < minCircle.second) {
          minCircle = cir2;
          b = d;
        } else {
          if (inCircle(a, cir3) && cir3.second < minCircle.second) {
            minCircle = cir3;
            a = d;
          }
        }
      }
      nowCircle = minCircle;
    }
    return nowCircle;
  }
  friend ostream &operator<<(ostream &out, const Polygon &poly) {
    int size = poly.size();
    for (int i = 0; i < size; ++i) out << poly.pt[i] << "\t";
    return out;
  }
};
bool comSegs(const pair<pair<double, double>, int> &a,
             const pair<pair<double, double>, int> &b) {
  if (a.first.first < b.first.first - eps) return true;
  if (a.first.first > b.first.first + eps) return false;
  if (a.first.second < b.first.second - eps) return true;
  if (a.first.second > b.first.second + eps) return false;
  return a.second > b.second;
}
bool comPs(const pair<Point, int> &a, const pair<Point, int> &b) {
  int s = sign(a.first.x - b.first.x);
  if (s < 0) return true;
  if (s > 0) return false;
  return a.second < b.second;
}
double unionArea(vector<Polygon> &polys, int nowdir) {
  double ans = 0;
  int N = (int)polys.size();
  if (N == 0) return ans;
  vector<pair<double, double> > lines;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < polys[i].size(); ++j) {
      Point a, b;
      polys[i].getSeg(j, a, b);
      if (fabs(a.x - b.x) < eps) continue;
      if (nowdir == 1 && a.x > b.x) continue;
      if (nowdir == -1 && a.x < b.x) continue;
      double kk = (b.y - a.y) / (b.x - a.x);
      double bb = a.y - kk * a.x;
      bool close = false;
      for (int k = 0; k < lines.size(); ++k)
        if (fabs(lines[k].first - kk) < eps && fabs(lines[k].second - bb) < eps)
          close = true;
      if (close) continue;
      lines.push_back(make_pair(kk, bb));
      vector<pair<Point, int> > ps;
      for (int k = 0; k < N; ++k) {
        bool touch = false;
        for (int l = 0; l < polys[k].size(); ++l) {
          Point c, d;
          polys[k].getSeg(l, c, d);
          if (onLine(c, a, b) && onLine(d, a, b)) touch = true;
        }
        if (touch) continue;
        vector<Point> inters;
        for (int l = 0; l < polys[k].size(); ++l) {
          Point c, d;
          polys[k].getSeg(l, c, d);
          vector<Point> t = interLine(a, b, c, d);
          for (int z = 0; z < t.size(); ++z)
            if (onSeg(t[z], c, d)) inters.push_back(t[z]);
        }
        sort(inters.begin(), inters.end(), comPointByX);
        inters.resize(unique(inters.begin(), inters.end(), comPointEqual) -
                      inters.begin());
        if (inters.size() == 2) {
          ps.push_back(make_pair(inters.front(), 0));
          ps.push_back(make_pair(inters.back(), 1));
        }
      }
      for (int k = 0; k < N; ++k) {
        for (int l = 0; l < polys[k].size(); ++l) {
          Point c, d;
          polys[k].getSeg(l, c, d);
          if (fabs(c.x - d.x) < eps) continue;
          int dir = (c.x < d.x) ? 1 : -1;
          if (dir != nowdir) continue;
          if (c.x > d.x) swap(c, d);
          if (onLine(c, a, b) && onLine(d, a, b)) {
            ps.push_back(make_pair(c, 2));
            ps.push_back(make_pair(d, 3));
          }
        }
      }
      sort(ps.begin(), ps.end(), comPs);
      int cntPosi = 0, cntNega = 0;
      int cntIn = 0;
      for (int k = 0; k < ps.size(); ++k) {
        double x2 = ps[k].first.x;
        double y2 = ps[k].first.y;
        double x1 = 0, y1 = 0;
        if (k > 0) {
          x1 = ps[k - 1].first.x;
          y1 = ps[k - 1].first.y;
        }
        double area = (x2 - x1) * (y2 + y1) / 2;
        if (cntPosi > 0 && cntNega == 0 && x2 - x1 > eps && cntIn == 0)
          ans += area;
        int id = ps[k].second;
        if (id == 2) cntPosi++;
        if (id == 0) cntIn++;
        if (id == 3) cntPosi--;
        if (id == 1) cntIn--;
      }
    }
  return ans;
}
struct ConvexHull {
  static inline bool cmp(const Point &a, const Point &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
  }
  static Polygon convexHull(const vector<Point> &points,
                            bool needInnerEdgePoint = false) {
    vector<Point> p(points.begin(), points.end());
    vector<int> stack(p.size() + 1);
    Polygon poly;
    poly.clear();
    if (p.size() == 0) return poly;
    if (p.size() == 1) {
      poly.addPoint(points[0]);
      return poly;
    }
    sort(p.begin(), p.end(), ConvexHull::cmp);
    int threshold = 0;
    if (needInnerEdgePoint) threshold = 1;
    int N = (int)p.size();
    int top = -1;
    stack[++top] = 0;
    stack[++top] = 1;
    for (int i = 2; i < N; i++) {
      while (top >= 1 &&
             sign(cross(p[stack[top - 1]], p[i], p[stack[top]])) >= threshold)
        top--;
      stack[++top] = i;
    }
    int temp_top = top;
    stack[++top] = N - 2;
    for (int i = N - 3; i >= 0; i--) {
      while (top >= temp_top + 1 &&
             sign(cross(p[stack[top - 1]], p[i], p[stack[top]])) >= threshold)
        top--;
      stack[++top] = i;
    }
    for (int i = 0; i < top; ++i) poly.addPoint(p[stack[i]]);
    return poly;
  }
};
class HalfPlanes {
 public:
  Polygon poly;
  HalfPlanes(double maxRange) {
    poly.addPoint(Point(-maxRange, -maxRange));
    poly.addPoint(Point(maxRange, -maxRange));
    poly.addPoint(Point(maxRange, maxRange));
    poly.addPoint(Point(-maxRange, maxRange));
  }
  void intersect(const Point &a, const Point &b) { poly = poly.cut(a, b); }
  void intersect(double A, double B, double C) {
    pair<Point, Point> ab = onLine(A, B, C);
    pair<Point, Point> cd = getVerticalEquallySegment(ab.first, ab.second);
    Point a = ab.first, b = ab.second, c = cd.first, d = cd.second;
    double vc = A * c.x + B * c.y + C;
    if (vc > 0) {
      if (sign(cross(a, b, c)) > 0) swap(a, b);
    } else {
      if (sign(cross(a, b, d)) > 0) swap(a, b);
    }
    poly = poly.cut(a, b);
  }
  void intersect(const Point &a, const Point &b, const Point &c) {
    if (sign(cross(a, b, c)) <= 0)
      poly = poly.cut(a, b);
    else
      poly = poly.cut(b, a);
  }
};
class Voronoy {
 public:
  vector<Point> ps;
  vector<HalfPlanes> planes;
  Voronoy(vector<Point> &points, double maxRange) {
    int N = (int)points.size();
    ps = points;
    planes.resize(N, HalfPlanes(maxRange));
    for (int i = 0; i < N; ++i)
      for (int j = i + 1; j < N; ++j) {
        pair<Point, Point> v = getVerticalEquallySegment(ps[i], ps[j]);
        planes[i].intersect(v.first, v.second, ps[i]);
        planes[j].intersect(v.first, v.second, ps[j]);
      }
  }
};
struct Point3D {
  double x, y, z;
  Point3D() {}
  Point3D(double xx, double yy, double zz) {
    x = xx;
    y = yy;
    z = zz;
  }
  double len() { return sqrt(x * x + y * y + z * z); }
};
Point3D operator+(const Point3D &a, const Point3D &b) {
  return Point3D(a.x + b.x, a.y + b.y, a.z + b.z);
}
Point3D operator-(const Point3D &a, const Point3D &b) {
  return Point3D(a.x - b.x, a.y - b.y, a.z - b.z);
}
double dist(const Point3D &a, const Point3D &b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}
double dot(const Point3D &a, const Point3D &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
Point3D cross(const Point3D &u, const Point3D &v) {
  Point3D ret;
  ret.x = u.y * v.z - v.y * u.z;
  ret.y = u.z * v.x - u.x * v.z;
  ret.z = u.x * v.y - u.y * v.x;
  return ret;
}
Point3D planeVector(const Point3D &a, const Point3D &b, const Point3D &c) {
  return cross(a - b, b - c);
}
double distToPlane(const Point3D &p, const Point3D &s1, const Point3D &s2,
                   const Point3D &s3) {
  Point3D plane = planeVector(s1, s2, s3);
  return dot(plane, p - s1) / plane.len();
}
Point ps[4];
Point a, b, c, d;
class State {
 public:
  double x, y, z;
  State operator+(const State &other) {
    State ret;
    ret.x = x + other.x;
    ret.y = y + other.y;
    ret.z = z + other.z;
    return ret;
  }
  State operator-(const State &other) {
    State ret;
    ret.x = x - other.x;
    ret.y = y - other.y;
    ret.z = z - other.z;
    return ret;
  }
  State operator*(double k) {
    State ret;
    ret.x = x * k;
    ret.y = y * k;
    ret.z = z * k;
    return ret;
  }
  friend ostream &operator<<(ostream &out, const State &state) {
    out << state.x << " " << state.y << " " << state.z;
    return out;
  }
};
double func(const State &s) {
  Point p(s.x, s.y);
  double ret = dist(Point(0, 0), p);
  ret += dist(getMinimumDistPointOnLine(c, d, p), p);
  return ret;
}
class GoldSplitSearch {
 public:
  static State findMinimum(State &begin, State &end,
                           double (*func)(const State &s)) {
    const double tou = (sqrt(5.0) - 1) / 2;
    State a = begin;
    State b = end;
    for (int k = 0; k < 200; ++k) {
      State x1 = a + (b - a) * (1 - tou);
      State x2 = a + (b - a) * tou;
      double f1 = func(x1);
      double f2 = func(x2);
      if (f1 > f2)
        a = x1;
      else
        b = x2;
    }
    return a;
  }
};
double getAns(Point aa, Point bb, Point cc, Point dd) {
  c = cc;
  d = dd;
  double scale = 100000 / (bb - aa).length();
  Point na = (aa - bb) * scale + bb;
  Point nb = (bb - aa) * scale + aa;
  State begin;
  begin.x = na.x;
  begin.y = na.y;
  State end;
  end.x = nb.x;
  end.y = nb.y;
  State s = GoldSplitSearch::findMinimum(begin, end, func);
  return func(s);
}
int N;
vector<Polygon> polys;
void init() {
  double ans = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    vector<Point> ps(4);
    for (int j = 0; j < 4; ++j) cin >> ps[j];
    Polygon poly = ConvexHull::convexHull(ps);
    double area = poly.area();
    polys.push_back(poly);
    ans += area;
  }
  ans = ans / (unionArea(polys, -1) - unionArea(polys, 1));
  printf("%.10f\n", ans);
}
void york() {}
int main() {
  init();
  york();
  return 0;
}
