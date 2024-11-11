#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = 1e18;
const double pi = acos(-1.0);
const double eps = 1e-9;
bool eq(double a, double b) { return abs(a - b) <= eps; }
struct pt {
  double x, y;
  pt() {}
  pt(double x_, double y_) : x(x_), y(y_) {}
  bool operator<(const pt p) const {
    if (!eq(x, p.x)) return x < p.x;
    if (!eq(y, p.y)) return y < p.y;
    return 0;
  }
  bool operator==(const pt p) const { return eq(x, p.x) and eq(y, p.y); }
  pt operator+(const pt p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt p) const { return pt(x - p.x, y - p.y); }
  pt operator*(const double c) const { return pt(x * c, y * c); }
  pt operator/(const double c) const { return pt(x / c, y / c); }
  double operator*(const pt p) const { return x * p.x + y * p.y; }
  double operator^(const pt p) const { return x * p.y - y * p.x; }
  friend istream& operator>>(istream& in, pt& p) { return in >> p.x >> p.y; }
};
struct line {
  pt p, q;
  line() {}
  line(pt p_, pt q_) : p(p_), q(q_) {}
  friend istream& operator>>(istream& in, line& r) { return in >> r.p >> r.q; }
};
double dist(pt p, pt q) { return hypot(p.y - q.y, p.x - q.x); }
double dist2(pt p, pt q) {
  return ((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y));
}
double norm(pt v) { return dist(pt(0, 0), v); }
double angle(pt v) {
  double ang = atan2(v.y, v.x);
  if (ang < 0) ang += 2 * pi;
  return ang;
}
double sarea(pt p, pt q, pt r) { return ((q - p) ^ (r - q)) / 2; }
bool col(pt p, pt q, pt r) { return eq(sarea(p, q, r), 0); }
int paral(pt u, pt v) {
  if (!eq(u ^ v, 0)) return 0;
  if ((u.x > eps) == (v.x > eps) and (u.y > eps) == (v.y > eps)) return 1;
  return -1;
}
bool ccw(pt p, pt q, pt r) { return sarea(p, q, r) > eps; }
pt rotate(pt p, double th) {
  return pt(p.x * cos(th) - p.y * sin(th), p.x * sin(th) + p.y * cos(th));
}
pt rotate90(pt p) { return pt(-p.y, p.x); }
bool isvert(line r) { return eq(r.p.x, r.q.x); }
double getm(line r) {
  if (isvert(r)) return DINF;
  return (r.p.y - r.q.y) / (r.p.x - r.q.x);
}
double getn(line r) {
  if (isvert(r)) return DINF;
  return r.p.y - getm(r) * r.p.x;
}
bool paraline(line r, line second) {
  return paral(r.p - r.q, second.p - second.q);
}
bool isinseg(pt p, line r) {
  if (p == r.p or p == r.q) return 1;
  return paral(p - r.p, p - r.q) == -1;
}
double get_t(pt v, line r) { return (r.p ^ r.q) / ((r.p - r.q) ^ v); }
pt proj(pt p, line r) {
  if (r.p == r.q) return r.p;
  r.q = r.q - r.p;
  p = p - r.p;
  pt proj = r.q * ((p * r.q) / (r.q * r.q));
  return proj + r.p;
}
pt inter(line r, line second) {
  if (paraline(r, second)) return pt(DINF, DINF);
  if (isvert(r)) return pt(r.p.x, getm(second) * r.p.x + getn(second));
  if (isvert(second)) return pt(second.p.x, getm(r) * second.p.x + getn(r));
  double x = (getn(second) - getn(r)) / (getm(r) - getm(second));
  return pt(x, getm(r) * x + getn(r));
}
bool interseg(line r, line second) {
  if (isinseg(r.p, second) or isinseg(r.q, second) or isinseg(second.p, r) or
      isinseg(second.q, r))
    return 1;
  return ccw(r.p, r.q, second.p) != ccw(r.p, r.q, second.q) and
         ccw(second.p, second.q, r.p) != ccw(second.p, second.q, r.q);
}
double disttoline(pt p, line r) { return dist(p, proj(p, r)); }
double disttoseg(pt p, line r) {
  if (isinseg(proj(p, r), r)) return disttoline(p, r);
  return min(dist(p, r.p), dist(p, r.q));
}
double distseg(line a, line b) {
  if (interseg(a, b)) return 0;
  double ret = DINF;
  ret = min(ret, disttoseg(a.p, b));
  ret = min(ret, disttoseg(a.q, b));
  ret = min(ret, disttoseg(b.p, a));
  ret = min(ret, disttoseg(b.q, a));
  return ret;
}
pt getcenter(pt a, pt b, pt c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return inter(line(b, b + rotate90(a - b)), line(c, c + rotate90(a - c)));
}
vector<pt> circ_line_inter(pt a, pt b, pt c, double r) {
  vector<pt> ret;
  b = b - a, a = a - c;
  double A = b * b;
  double B = a * b;
  double C = a * a - r * r;
  double D = B * B - A * C;
  if (D < -eps) return ret;
  ret.push_back(c + a + b * (-B + sqrt(D + eps)) / A);
  if (D > eps) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
  return ret;
}
vector<pt> circ_inter(pt a, pt b, double r, double R) {
  vector<pt> ret;
  double d = dist(a, b);
  if (d > r + R or d + min(r, R) < max(r, R)) return ret;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrt(r * r - x * x);
  pt v = (b - a) / d;
  ret.push_back(a + v * x + rotate90(v) * y);
  if (y > 0) ret.push_back(a + v * x - rotate90(v) * y);
  return ret;
}
double ang;
struct cmp {
  bool operator()(const line& a, const line& b) const {
    line r = line(pt(0, 0), rotate(pt(1, 0), ang));
    return norm(inter(r, a)) < norm(inter(r, b));
  }
};
vector<pt> points;
vector<double> rad;
int n;
int first(int a, int b) {
  return int((circ_inter(points[a], points[b], rad[a], rad[b])).size());
}
int g(int a, int b, int c) {
  set<pt> second;
  vector<pt> vaux;
  vaux = circ_inter(points[a], points[b], rad[a], rad[b]);
  for (auto u : vaux) second.insert(u);
  vaux = circ_inter(points[a], points[c], rad[a], rad[b]);
  for (auto u : vaux) second.insert(u);
  return int((second).size());
}
int h() {
  set<pt> second;
  vector<pt> vaux;
  vaux = circ_inter(points[0], points[1], rad[0], rad[1]);
  for (auto u : vaux) second.insert(u);
  vaux = circ_inter(points[0], points[2], rad[0], rad[2]);
  for (auto u : vaux) second.insert(u);
  vaux = circ_inter(points[1], points[2], rad[1], rad[2]);
  for (auto u : vaux) second.insert(u);
  return int((second).size());
}
int par[3], sz[3];
void build() {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
}
int find(int v) {
  if (par[v] == v)
    return v;
  else
    return par[v] = find(par[v]);
}
void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  double x, y, r, ans;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> r;
    points.push_back(pt(x, y));
    rad.push_back(r);
  }
  if (n == 1)
    ans = 2;
  else if (n == 2) {
    ans = 3 + max(0, first(0, 1) - 1);
  } else {
    int v, e = 0, comp;
    e += g(0, 1, 2);
    e += g(1, 0, 2);
    e += g(2, 0, 1);
    v = h();
    vector<vector<int>> g(3);
    build();
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (first(i, j)) unite(i, j);
      }
    }
    set<int> second;
    for (int i = 0; i < 3; i++) second.insert(find(i));
    comp = int((second).size());
    ans = e - v + comp + 1;
  }
  cout << ans << '\n';
  exit(0);
}
