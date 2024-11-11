#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-7;
struct PT {
  long double x, y;
  PT() {}
  PT(long double x, long double y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const {
    return make_pair(y, x) < make_pair(rhs.y, rhs.x);
  }
  bool operator==(const PT &rhs) const {
    return make_pair(y, x) == make_pair(rhs.y, rhs.x);
  }
};
long double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
long double area2(PT a, PT b, PT c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 &&
          (a.y - b.y) * (c.y - b.y) <= 0);
}
void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < (int)pts.size(); i++) {
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
  for (int i = 2; i < (int)pts.size(); i++) {
    if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
}
struct line {
  double a, b, c;
  line() {}
  line(double _a, double _b, double _c) : a(_a), b(_b), c(_c){};
};
void pointsToLine(PT p1, PT p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0, l.b = 0.0, l.c = -p1.x;
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - p1.y;
  }
}
bool areParallel(line l1, line l2) {
  return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}
bool areIntersect(line l1, line l2, PT &p) {
  if (areParallel(l1, l2)) return false;
  p.x = (l1.c * l2.b - l2.c * l1.b) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS)
    p.y = -(l1.a * p.x + l1.c);
  else
    p.y = -(l2.a * p.x + l2.c);
  return true;
}
const int MAX = 100009;
int n;
vector<PT> P;
long double A, B;
int main() {
  cin >> n >> A >> B;
  P.resize(n);
  long double X = 0, Y = 0;
  for (int i = 0; i < n; i++) {
    cin >> P[i].x >> P[i].y;
    X = max(X, P[i].x);
    Y = max(Y, P[i].y);
  }
  P.push_back(PT(X, 0));
  P.push_back(PT(0, Y));
  ConvexHull(P);
  vector<PT> CUT;
  long double ans = 1e9;
  for (int i = 0; i < (int)P.size(); i++) {
    int j = (i + 1) % P.size();
    line a, b;
    pointsToLine(P[i], P[j], a);
    pointsToLine(PT(A, B), PT(0, 0), b);
    PT I;
    if (areIntersect(a, b, I)) {
      if (I.x >= min(P[i].x, P[j].x) && I.x <= max(P[i].x, P[j].x) &&
          I.y >= min(P[i].y, P[j].y) && I.y <= max(P[i].y, P[j].y)) {
        CUT.push_back(I);
        ans = min(ans, A / I.x);
      }
    }
  }
  cout << fixed << setprecision(11) << ans << endl;
  return 0;
}
