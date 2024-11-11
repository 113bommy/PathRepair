#include <bits/stdc++.h>
using namespace std;
double INF = 1e100;
double EPS = 1e-12;
struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(double c) const { return PT(x * c, y * c); }
  PT operator/(double c) const { return PT(x / c, y / c); }
};
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
PT RotateCCW90(PT p) { return PT(-p.y, p.x); }
PT RotateCW90(PT p) { return PT(p.y, -p.x); }
PT RotateCCW(PT p, double t) {
  return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return true;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return false;
    return true;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
  return true;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b = b - a;
  d = c - d;
  c = c - a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b * cross(c, d) / cross(b, d);
}
bool OnSameSide(PT a, PT b, PT c, PT d) {
  return cross(c - a, c - b) * cross(d - a, d - b) > 0;
}
PT ComputeCircleCenter(PT a, PT b, PT c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return ComputeLineIntersection(b, b + RotateCW90(a - b), c,
                                 c + RotateCW90(a - c));
}
bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
}
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
  vector<PT> ret;
  b = b - a;
  a = a - c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r * r;
  double D = B * B - A * C;
  if (D < -EPS) return ret;
  ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
  if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
  return ret;
}
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrt(r * r - x * x);
  PT v = (b - a) / d;
  ret.push_back(a + v * x + RotateCCW90(v) * y);
  if (y > 0) ret.push_back(a + v * x - RotateCCW90(v) * y);
  return ret;
}
double ComputeSignedArea(const vector<PT> &p) {
  double area = 0.;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}
double ComputeArea(const vector<PT> &p) { return fabs(ComputeSignedArea(p)); }
const int N = 100005;
int n;
PT pt[N];
int vx[N], vy[N];
PT a, b, c, d;
int main() {
  scanf("%d", &n);
  scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
  c.x = a.x, d.x = b.x;
  c.y = b.y, d.y = a.y;
  vector<PT> rect = {a, c, b, d};
  if (a.x == b.x || a.y == b.y) {
    printf("-1\n");
    return 0;
  }
  double low = 0, high = 1e100;
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf%d%d", &pt[i].x, &pt[i].y, vx + i, vy + i);
    if ((vx[i] == 0 && (pt[i].x == a.x || pt[i].x == b.x)) ||
        (vy[i] == 0 && (pt[i].y == a.y || pt[i].y == b.y))) {
      puts("-1");
      return 0;
    }
    bool inside = PointInPolygon(rect, pt[i]);
    PT nxt(pt[i].x + vx[i] * 2.0 * N, pt[i].y + vy[i] * 2.0 * N);
    vector<PT> inter1, inter;
    for (int j = 0; j < 4; j++) {
      if (!LinesCollinear(pt[i], nxt, rect[j], rect[(j + 1) % 4]) &&
          SegmentsIntersect(pt[i], nxt, rect[j], rect[(j + 1) % 4])) {
        PT it = ComputeLineIntersection(pt[i], nxt, rect[j], rect[(j + 1) % 4]);
        inter1.push_back(it);
      }
    }
    for (int i = 0; i < inter1.size(); i++) {
      bool pos = true;
      for (int j = i + 1; j < inter1.size(); j++) {
        if (dist2(inter1[i], inter1[j]) < EPS) pos = false;
      }
      if (pos) inter.push_back(inter1[i]);
    }
    if (vx[i] == 0 && vy[i] == 0) {
      if (!inside) {
        puts("-1");
        return 0;
      }
      continue;
    }
    if (inside) {
      if (PointOnPolygon(rect, pt[i])) {
        if (inter.size() == 1) {
          puts("-1");
          return 0;
        }
        for (auto p : inter) {
          if (sqrt(dist2(pt[i], p)) > 1e-4)
            high =
                min(high, sqrt(dist2(pt[i], p) / ((1.0 * (vx[i]) * (vx[i])) +
                                                  (1.0 * (vy[i]) * (vy[i])))));
        }
      } else {
        assert(inter.size() == 1);
        high = min(high,
                   sqrt(dist2(inter[0], pt[i]) / ((1.0 * (vx[i]) * (vx[i])) +
                                                  (1.0 * (vy[i]) * (vy[i])))));
      }
    } else {
      if (inter.size() > 1) {
        assert(inter.size() == 2);
        double t1 = sqrt(dist2(inter[0], pt[i]) / ((1.0 * (vx[i]) * (vx[i])) +
                                                   (1.0 * (vy[i]) * (vy[i]))));
        double t2 = sqrt(dist2(inter[1], pt[i]) / ((1.0 * (vx[i]) * (vx[i])) +
                                                   (1.0 * (vy[i]) * (vy[i]))));
        if (t1 > t2) swap(t1, t2);
        low = max(low, t1);
        high = min(high, t2);
      } else {
        puts("-1");
        return 0;
      }
    }
  }
  if (low < high) {
    printf("%.20lf\n", low);
  } else {
    printf("-1\n");
  }
}
