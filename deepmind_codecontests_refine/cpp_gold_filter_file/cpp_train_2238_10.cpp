#include <bits/stdc++.h>
using namespace std;
const long long EPS = 1e-13;
const long long INF = 1e18;
struct PT {
  long long x, y;
  PT() {}
  PT(long long x, long long y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(long long c) const { return PT(x * c, y * c); }
  PT operator/(long long c) const { return PT(x / c, y / c); }
  bool operator==(const PT &rhs) const {
    return make_pair(y, x) == make_pair(rhs.y, rhs.x);
  }
  friend bool operator<(const PT &lhs, const PT &rhs);
};
struct cmp_x {
  bool operator()(const PT &a, const PT &b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
  }
};
struct cmp_y {
  bool operator()(const PT a, const PT b) {
    return a.y < b.y || a.y == b.y && a.x < b.x;
  }
};
bool operator<(const PT &lhs, const PT &rhs) {
  bool x = cmp_y()(lhs, rhs);
  return x;
}
long long dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
long long dist2(PT p, PT q) { return dot(p - q, p - q); }
long long cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
long long area2(PT a, PT b, PT c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}
PT RotateCCW90(PT p) { return PT(-p.y, p.x); }
PT RotateCW90(PT p) { return PT(p.y, -p.x); }
PT RotateCCW(PT p, long long t) {
  return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
  long long r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
long long DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
long long DistancePointPlane(long long x, long long y, long long z, long long a,
                             long long b, long long c, long long d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
int SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return 2;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return 0;
    return 2;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
  return 1;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b = b - a;
  d = c - d;
  c = c - a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b * cross(c, d) / cross(b, d);
}
PT ComputeCircleCenter(PT a, PT b, PT c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return ComputeLineIntersection(b, b + RotateCW90(a - b), c,
                                 c + RotateCW90(a - c));
}
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
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
vector<PT> CircleLineIntersection(PT a, PT b, PT c, long long r) {
  vector<PT> ret;
  b = b - a;
  a = a - c;
  long long A = dot(b, b);
  long long B = dot(a, b);
  long long C = dot(a, a) - r * r;
  long long D = B * B - A * C;
  if (D < -EPS) return ret;
  ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
  if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
  return ret;
}
vector<PT> CircleCircleIntersection(PT a, PT b, long long r, long long R) {
  vector<PT> ret;
  long long d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  long long x = (d * d - R * R + r * r) / (2 * d);
  long long y = sqrt(r * r - x * x);
  PT v = (b - a) / d;
  ret.push_back(a + v * x + RotateCCW90(v) * y);
  if (y > 0) ret.push_back(a + v * x - RotateCCW90(v) * y);
  return ret;
}
long long ComputeSignedArea(const vector<PT> &p) {
  long long area = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}
long long ComputeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT> &p) {
  PT c(0, 0);
  long long scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  return c / scale;
}
bool IsSimple(const vector<PT> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i + 1; k < p.size(); k++) {
      int j = (i + 1) % p.size();
      int l = (k + 1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
    }
  }
  return true;
}
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 &&
          (a.y - b.y) * (c.y - b.y) <= 0);
}
void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0)
      up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0)
      dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int)up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
}
long long ClosestPoints(vector<PT> &pts, PT &ans1, PT &ans2) {
  sort(pts.begin(), pts.end(), cmp_x());
  set<PT, cmp_y> w;
  long long d = INF;
  int j = 0;
  for (int i = 0; i < pts.size(); i++) {
    long long ds = sqrt(d) + 1;
    while (j < i && pts[i].x - pts[j].x > ds) w.erase(w.find(pts[j++]));
    auto it = w.lower_bound(PT(-1e9, pts[i].y - ds));
    auto eit = w.upper_bound(PT(-1e9, pts[i].y + ds));
    for (; it != eit; it++) {
      long long temp = min(d, dist2(pts[i], *it));
      if (temp < d) {
        d = temp;
        ans1 = pts[i];
        ans2 = *it;
      }
    }
    w.insert(pts[i]);
  }
  return d;
}
struct segintersect_event {
  PT p;
  int type;
  int seg1, seg2;
  static const int START = -1;
  static const int EXIT = 1;
  static const int CROSS = 0;
  bool operator<(const segintersect_event &rhs) const {
    return cmp_x()(p, rhs.p) || p == rhs.p && type < rhs.type ||
           p == rhs.p && type == rhs.type && seg1 < rhs.seg1 ||
           p == rhs.p && type == rhs.type && seg1 == rhs.seg1 &&
               seg2 < rhs.seg2;
  }
};
vector<PT> SegmentsIntersection(vector<pair<PT, PT>> segments) {
  set<segintersect_event> events;
  for (int i = 0; i < segments.size(); i++) {
    segintersect_event e;
    if (!cmp_x()(segments[i].first, segments[i].second))
      swap(segments[i].first, segments[i].second);
    e.p = segments[i].first;
    e.type = segintersect_event::START;
    e.seg1 = i;
    e.seg2 = -1;
    events.insert(e);
    e.p = segments[i].second;
    e.type = segintersect_event::EXIT;
    events.insert(e);
  }
  set<pair<PT, int>> active_set;
  vector<PT> ans;
  while (!events.empty()) {
    auto e = events.begin();
    switch (e->type) {
      case segintersect_event::START:
        break;
      case segintersect_event::EXIT:
        break;
      case segintersect_event::CROSS:
        break;
    }
  }
}
class dsu {
 public:
  vector<int> sets;
  void init(int n) {
    sets.resize(n);
    for (int i = 0; i < n; i++) {
      sets[i] = -1;
    }
  }
  int find_set(int x) {
    if (sets[x] < 0) return x;
    return sets[x] = find_set(sets[x]);
  }
  int union_sets(int x, int y) {
    int r[] = {find_set(x), find_set(y)};
    if (r[0] == r[1]) return -1;
    int l = (sets[r[0]] < sets[r[1]]) ? 0 : 1;
    sets[r[l]] += sets[r[l ^ 1]];
    sets[r[l ^ 1]] = r[l];
    return -sets[r[l]];
  }
};
bool is_right(PT a, PT b, PT c) {
  if (a == b || a == c || b == c) return false;
  return dot(b - a, c - a) == 0 || dot(a - b, c - b) == 0 ||
         dot(a - c, b - c) == 0;
}
const int bin_cnt = 1001;
vector<pair<PT, int>> p[bin_cnt + 10];
int main() {
  int n, x, y, idx;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    idx = x / 1000;
    p[idx].push_back(make_pair(PT(x, y), i + 1));
  }
  for (int i = 0; i < bin_cnt; i++) {
    sort(p[i].begin(), p[i].end());
  }
  bool dir = false;
  for (int i = 0; i < bin_cnt; i++) {
    if (p[i].empty()) continue;
    if (!dir) {
      reverse(p[i].begin(), p[i].end());
    }
    dir = !dir;
  }
  for (int i = 0; i < bin_cnt; i++) {
    for (auto x : p[i]) printf("%d ", x.second);
  }
  return 0;
}
