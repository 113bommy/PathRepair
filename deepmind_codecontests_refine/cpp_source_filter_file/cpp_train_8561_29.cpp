#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long double DINF = 1e18;
const long double pi = acos(-1.0);
const long double eps = 1e-9;
bool eq(long double a, long double b) { return abs(a - b) <= eps; }
struct pt {
  long double x, y;
  pt() {}
  pt(long double x_, long double y_) : x(x_), y(y_) {}
  bool operator<(const pt p) const {
    if (!eq(x, p.x)) return x < p.x;
    if (!eq(y, p.y)) return y < p.y;
    return 0;
  }
  bool operator==(const pt p) const { return eq(x, p.x) and eq(y, p.y); }
  pt operator+(const pt p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt p) const { return pt(x - p.x, y - p.y); }
  pt operator*(const long double c) const { return pt(x * c, y * c); }
  pt operator/(const long double c) const { return pt(x / c, y / c); }
  long double operator*(const pt p) const { return x * p.x + y * p.y; }
  long double operator^(const pt p) const { return x * p.y - y * p.x; }
  friend istream& operator>>(istream& in, pt& p) { return in >> p.x >> p.y; }
};
struct line {
  pt p, q;
  line() {}
  line(pt p_, pt q_) : p(p_), q(q_) {}
  friend istream& operator>>(istream& in, line& r) { return in >> r.p >> r.q; }
};
long double dist(pt p, pt q) { return hypot(p.y - q.y, p.x - q.x); }
long double dist2(pt p, pt q) {
  return ((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y));
}
long double norm(pt v) { return dist(pt(0, 0), v); }
long double angle(pt v) {
  long double ang = atan2(v.y, v.x);
  if (ang < 0) ang += 2 * pi;
  return ang;
}
long double sarea(pt p, pt q, pt r) { return ((q - p) ^ (r - q)) / 2; }
bool col(pt p, pt q, pt r) { return eq(sarea(p, q, r), 0); }
int paral(pt u, pt v) {
  if (!eq(u ^ v, 0)) return 0;
  if ((u.x > eps) == (v.x > eps) and (u.y > eps) == (v.y > eps)) return 1;
  return -1;
}
bool ccw(pt p, pt q, pt r) { return sarea(p, q, r) > eps; }
pt rotate(pt p, long double th) {
  return pt(p.x * cos(th) - p.y * sin(th), p.x * sin(th) + p.y * cos(th));
}
pt rotate90(pt p) { return pt(-p.y, p.x); }
bool isvert(line r) { return eq(r.p.x, r.q.x); }
long double getm(line r) {
  if (isvert(r)) return DINF;
  return (r.p.y - r.q.y) / (r.p.x - r.q.x);
}
long double getn(line r) {
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
long double get_t(pt v, line r) { return (r.p ^ r.q) / ((r.p - r.q) ^ v); }
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
  long double x = (getn(second) - getn(r)) / (getm(r) - getm(second));
  return pt(x, getm(r) * x + getn(r));
}
bool interseg(line r, line second) {
  if (isinseg(r.p, second) or isinseg(r.q, second) or isinseg(second.p, r) or
      isinseg(second.q, r))
    return 1;
  return ccw(r.p, r.q, second.p) != ccw(r.p, r.q, second.q) and
         ccw(second.p, second.q, r.p) != ccw(second.p, second.q, r.q);
}
long double disttoline(pt p, line r) { return dist(p, proj(p, r)); }
long double disttoseg(pt p, line r) {
  if (isinseg(proj(p, r), r)) return disttoline(p, r);
  return min(dist(p, r.p), dist(p, r.q));
}
long double distseg(line a, line b) {
  if (interseg(a, b)) return 0;
  long double ret = DINF;
  ret = min(ret, disttoseg(a.p, b));
  ret = min(ret, disttoseg(a.q, b));
  ret = min(ret, disttoseg(b.p, a));
  ret = min(ret, disttoseg(b.q, a));
  return ret;
}
bool operator<(const line& a, const line& b) {
  if (a.p == b.p) return ccw(a.p, a.q, b.q);
  if (!eq(a.p.x, a.q.x) and (eq(b.p.x, b.q.x) or a.p.x + eps < b.p.x))
    return ccw(a.p, a.q, b.p);
  return ccw(a.p, b.q, b.p);
}
bool has_intersection(vector<line> v) {
  auto intersects = [&](pair<line, int> a, pair<line, int> b) {
    return interseg(a.first, b.first);
  };
  vector<pair<pt, pair<int, int>>> w;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].q < v[i].p) swap(v[i].p, v[i].q);
    w.push_back({v[i].p, {0, i}});
    w.push_back({v[i].q, {1, i}});
  }
  sort(w.begin(), w.end());
  set<pair<line, int>> se;
  for (auto i : w) {
    line at = v[i.second.second];
    if (i.second.first == 0) {
      auto nxt = se.lower_bound({at, i.second.second});
      if (nxt != se.end() and intersects(*nxt, {at, i.second.second})) return 1;
      if (nxt != se.begin() and intersects(*(--nxt), {at, i.second.second}))
        return 1;
      se.insert({at, i.second.second});
    } else {
      auto nxt = se.upper_bound({at, i.second.second}), cur = nxt, prev = --cur;
      if (nxt != se.end() and prev != se.begin() and
          intersects(*nxt, *(--prev)))
        return 1;
      se.erase(cur);
    }
  }
  return 0;
}
int n;
vector<pair<pt, pt>> pts;
vector<int> S;
long double com = 0.218750000;
bool has = false;
bool show(long double m) {
  bool ret = false;
  vector<line> v;
  for (int i = 0; i < n; i++) {
    pt p = pts[i].first;
    pt q = pts[i].second;
    long double mul = m * S[i] / norm(q);
    q = q * mul;
    q = q + p;
    v.push_back(line(p, q));
  }
  ret = has_intersection(v);
  has |= ret;
  return ret;
}
long double bb(long double l, long double r) {
  if (eq(l, r)) return l;
  long double m = (l + r) / 2.0;
  if (show(m))
    r = m;
  else
    l = m;
  return bb(l, r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    pt a, b;
    cin >> a >> b;
    int second;
    cin >> second;
    S.push_back(second);
    pts.push_back({a, b});
  }
  cout << setprecision(9) << fixed;
  long double ans = bb((long double)0, (long double)1e9);
  if (!has)
    cout << "No show :(" << '\n';
  else
    cout << ans << '\n';
  exit(0);
}
