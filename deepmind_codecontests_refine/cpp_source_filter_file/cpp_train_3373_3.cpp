#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-15;
bool eq(long double a, long double b) { return abs(a - b) <= eps; }
bool lt(long double a, long double b) { return b - a > eps; }
bool leq(long double a, long double b) { return lt(a, b) || eq(a, b); }
bool gt(long double a, long double b) { return a - b > eps; }
bool geq(long double a, long double b) { return gt(a, b) || eq(a, b); }
struct pt {
  long double x, y;
  pt() {}
  pt(long double x, long double y) : x(x), y(y) {}
  pt operator-(const pt& other) const { return {x - other.x, y - other.y}; }
  pt operator+(const pt& other) const { return {x + other.x, y + other.y}; }
  pt operator*(long double k) const { return {x * k, y * k}; }
};
long double cross(const pt& p, const pt& q) { return p.x * q.y - p.y * q.x; }
long double dot(const pt& p, const pt& q) { return p.x * q.x + p.y * q.y; }
struct line {
  long double a, b, c;
  line(const pt& p, const pt& q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = cross(p, q);
    long double tmp = sqrt(a * a + b * b);
    a /= tmp, b /= tmp, c /= tmp;
  }
};
vector<pt> intersect(const line& l, const line& m) {
  long double a1 = l.a, b1 = l.b, c1 = -l.c;
  long double a2 = m.a, b2 = m.b, c2 = -m.c;
  long double det = a1 * b2 - a2 * b1;
  if (eq(det, 0)) {
    return {};
  }
  long double det1 = c1 * b2 - c2 * b1;
  long double det2 = a1 * c2 - a2 * c1;
  return {{det1 / det, det2 / det}};
}
bool on_seg(const pt& p, const pt& a, const pt& b) {
  return eq(cross(a - p, b - p), 0) && leq(dot(a - p, b - p), 0);
}
vector<pt> intersect(const pt& a, const pt& b, const pt& c, const pt& d) {
  line l(a, b), m(c, d);
  vector<pt> v = intersect(l, m);
  vector<pt> ans;
  for (pt& p : v) {
    if (on_seg(p, a, b) && on_seg(p, c, d)) {
      ans.push_back(p);
    }
  }
  if (on_seg(a, c, d)) {
    ans.push_back(a);
  }
  if (on_seg(b, c, d)) {
    ans.push_back(b);
  }
  if (on_seg(c, a, b)) {
    ans.push_back(c);
  }
  if (on_seg(d, a, b)) {
    ans.push_back(d);
  }
  return ans;
}
int halfplane(const pt& p, const line& l) {
  long double val = l.a * p.x + l.b * p.y + l.c;
  if (eq(val, 0)) {
    return 0;
  }
  if (gt(val, 0)) {
    return 1;
  }
  return -1;
}
pt ortho(const pt& p, const line& l) {
  long double alpha = -(l.a * p.x + l.b * p.y + l.c);
  pt n = {l.a, l.b};
  return p + n * alpha;
}
int main() {
  pt a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  pt w1, w2;
  cin >> w1.x >> w1.y >> w2.x >> w2.y;
  pt m1, m2;
  cin >> m1.x >> m1.y >> m2.x >> m2.y;
  line l(m1, m2);
  if (intersect(a, b, w1, w2).empty()) {
    if (!intersect(a, b, m1, m2).empty()) {
      if (halfplane(a, l) != halfplane(b, l)) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    return 0;
  }
  if (halfplane(a, l) != halfplane(b, l)) {
    cout << "NO\n";
    return 0;
  }
  if (halfplane(a, l) == 0) {
    cout << "NO\n";
    return 0;
  }
  pt h = ortho(b, l);
  pt c = b + (h - b) * 2;
  if (intersect(a, c, m1, m2).empty()) {
    cout << "NO\n";
    return 0;
  }
  pt p = intersect(a, c, m1, m2)[0];
  if (intersect(a, p, w1, w2).empty() && intersect(p, b, w1, w2).empty()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
