#include <bits/stdc++.h>
using namespace std;
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
  friend istream& operator>>(istream& in, pt& p) {
    in >> p.x >> p.y;
    return in;
  }
};
struct line {
  pt p, q;
  line() {}
  line(pt p_, pt q_) : p(p_), q(q_) {}
  friend istream& operator>>(istream& in, line& r) {
    in >> r.p >> r.q;
    return in;
  }
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
pt normalize(pt v) {
  if (!norm(v)) return v;
  v = v / norm(v);
  return v;
}
double sarea(pt p, pt q, pt r) { return ((q - p) ^ (r - q)) / 2; }
bool col(pt p, pt q, pt r) { return eq(sarea(p, q, r), 0); }
int paral(pt u, pt v) {
  if (!eq(u ^ v, 0)) return 0;
  if ((u.x > eps) == (v.x > eps) and (u.y > eps) == (v.y > eps)) return 1;
  return -1;
}
bool ccw(pt p, pt q, pt r) { return sarea(p, q, r) > 0; }
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
bool lineeq(line r, line second) {
  return col(r.p, r.q, second.p) and col(r.p, r.q, second.q);
}
bool paraline(line r, line second) {
  if (isvert(r) and isvert(second)) return 1;
  if (isvert(r) or isvert(second)) return 0;
  return eq(getm(r), getm(second));
}
bool isinline(pt p, line r) { return col(p, r.p, r.q); }
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
  if (paraline(r, second)) {
    return isinseg(r.p, second) or isinseg(r.q, second) or
           isinseg(second.p, r) or isinseg(second.q, r);
  }
  pt i = inter(r, second);
  return isinseg(i, r) and isinseg(i, second);
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
double polper(vector<pt> v) {
  double ret = 0;
  for (int i = 0; i < v.size(); i++) ret += dist(v[i], v[(i + 1) % v.size()]);
  return ret;
}
double polarea(vector<pt> v) {
  double ret = 0;
  for (int i = 0; i < v.size(); i++)
    ret += sarea(pt(0, 0), v[i], v[(i + 1) % v.size()]);
  return abs(ret);
}
bool onpol(pt p, vector<pt> v) {
  for (int i = 0; i < v.size(); i++)
    if (isinseg(p, line(v[i], v[(i + 1) % v.size()]))) return 1;
  return 0;
}
bool inpol(pt p, vector<pt> v) {
  if (onpol(p, v)) return 1;
  int c = 0;
  line r = line(p, pt(DINF, pi * DINF));
  for (int i = 0; i < v.size(); i++) {
    line second = line(v[i], v[(i + 1) % v.size()]);
    if (interseg(r, second)) c++;
  }
  return c & 1;
}
bool interpol(vector<pt> v1, vector<pt> v2) {
  for (int i = 0; i < v1.size(); i++)
    if (inpol(v1[i], v2)) return 1;
  for (int i = 0; i < v2.size(); i++)
    if (inpol(v2[i], v1)) return 1;
  return 0;
}
double distpol(vector<pt> v1, vector<pt> v2) {
  if (interpol(v1, v2)) return 0;
  double ret = DINF;
  for (int i = 0; i < v1.size(); i++)
    for (int j = 0; j < v2.size(); j++)
      ret = min(ret, distseg(line(v1[i], v1[(i + 1) % v1.size()]),
                             line(v2[j], v2[(j + 1) % v2.size()])));
  return ret;
}
vector<pt> convex_hull(vector<pt> v) {
  vector<pt> l, u;
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    while (l.size() > 1 and !ccw(l[l.size() - 2], l.back(), v[i])) l.pop_back();
    l.push_back(v[i]);
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    while (u.size() > 1 and !ccw(u[u.size() - 2], u.back(), v[i])) u.pop_back();
    u.push_back(v[i]);
  }
  l.pop_back();
  u.pop_back();
  for (pt i : u) l.push_back(i);
  return l;
}
struct convex_pol {
  vector<pt> pol;
  convex_pol(vector<pt> v) : pol(convex_hull(v)) {}
  bool is_inside(pt p) {
    if (pol.size() == 1) return p == pol[0];
    int l = 1, r = pol.size();
    while (l < r) {
      int m = (l + r) / 2;
      if (ccw(p, pol[0], pol[m]))
        l = m + 1;
      else
        r = m;
    }
    if (l == 1) return isinseg(p, line(pol[0], pol[1]));
    if (l == pol.size()) return false;
    return (pol[l - 1] ^ pol[l]) + eps > ((pol[l - 1] - pol[l]) ^ p);
  }
};
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
pt c1, c2, c3;
int r1, r2, r3;
bool con(int i, int j) {
  pt p, q;
  int r, second;
  if (i == 1)
    p = c1, r = r1;
  else
    p = c2, r = r2;
  if (j == 2)
    q = c2, second = r2;
  else
    q = c3, second = r3;
  bool ret = dist2(q, p) < ((r + second) * (r + second));
  if (ret) {
    return sqrt(dist2(q, p)) + double(min(r, second)) >
           (double)max(r, second) + 1e-9;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 2 << "\n";
    exit(0);
  }
  if (n == 2) {
    cin >> c1 >> r1;
    cin >> c2 >> r2;
    if (con(1, 2))
      cout << 4 << "\n";
    else
      cout << 3 << "\n";
  } else {
    cin >> c1 >> r1;
    cin >> c2 >> r2;
    cin >> c3 >> r3;
    int ans = 4;
    vector<pt> v1, v2, v3;
    v1 = circ_inter(c1, c2, r1, r2);
    v2 = circ_inter(c1, c3, r1, r3);
    v3 = circ_inter(c2, c3, r2, r3);
    set<pt> st;
    for (auto p : v1) st.insert(p);
    for (auto p : v2) st.insert(p);
    for (auto p : v3) st.insert(p);
    int sz = st.size();
    int doi = 0;
    doi += v1.size() > 1;
    doi += v2.size() > 1;
    doi += v3.size() > 1;
    if (sz == 6) ans += 4;
    if (sz == 5) ans += 3;
    if (sz == 4) {
      ans += 2;
      if (doi > 2) ans++;
    }
    if (sz == 3) {
      ans++;
      if (doi > 1) ans++;
    }
    if (sz == 2) {
      if (doi >= 1) ans++;
      if (doi > 2) ans++;
    }
    cout << ans << "\n";
  }
  exit(0);
}
