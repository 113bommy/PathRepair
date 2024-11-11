#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double DINF = 1e18;
const long double pi = acos(-1.0);
const long double eps = 1e-9;
bool eq(long double a, long double b) { return abs(a - b) <= eps; }
struct pt {
  long double x, y;
  pt() {}
  pt(long double x, long double y) : x(x), y(y) {}
  bool operator<(const pt p) const {
    if (!eq(x, p.x)) return x < p.x;
    return y < p.y;
  }
  bool operator==(const pt p) const { return eq(x, p.x) and eq(y, p.y); }
  pt operator+(const pt p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt p) const { return pt(x - p.x, y - p.y); }
  pt operator*(const long double c) const { return pt(x * c, y * c); }
  pt operator/(const long double c) const { return pt(x / c, y / c); }
};
struct line {
  pt p, q;
  line() {}
  line(pt p, pt q) : p(p), q(q) {}
};
long double dist(pt p, pt q) {
  return sqrt(((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y)));
}
long double dist2(pt p, pt q) {
  return ((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y));
}
long double norm(pt v) { return dist(pt(0, 0), v); }
pt normalize(pt v) {
  if (!norm(v)) return v;
  v = v / norm(v);
  return v;
}
long double dot(pt u, pt v) { return u.x * v.x + u.y * v.y; }
long double cross(pt u, pt v) { return u.x * v.y - u.y * v.x; }
long double sarea(pt p, pt q, pt r) { return cross(q - p, r - q) / 2; }
bool col(pt p, pt q, pt r) { return eq(sarea(p, q, r), 0); }
int paral(pt u, pt v) {
  u = normalize(u);
  v = normalize(v);
  if (eq(u.x, v.x) and eq(u.y, v.y)) return 1;
  if (eq(u.x, -v.x) and eq(u.y, -v.y)) return -1;
  return 0;
}
bool ccw(pt p, pt q, pt r) { return sarea(p, q, r) > 0; }
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
pt proj(pt p, line r) {
  if (r.p == r.q) return r.p;
  r.q = r.q - r.p;
  p = p - r.p;
  pt proj = r.q * (dot(p, r.q) / dot(r.q, r.q));
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
  if (paraline(r, second)) {
    return isinseg(r.p, second) or isinseg(r.q, second) or
           isinseg(second.p, r) or isinseg(second.q, r);
  }
  pt i = inter(r, second);
  return isinseg(i, r) and isinseg(i, second);
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
long double polper(vector<pt> v) {
  long double ret = 0;
  for (int i = 0; i < (int)((v).size()); i++)
    ret += dist(v[i], v[(i + 1) % (int)((v).size())]);
  return ret;
}
long double polarea(vector<pt> v) {
  long double ret = 0;
  for (int i = 0; i < (int)((v).size()); i++)
    ret += sarea(pt(0, 0), v[i], v[(i + 1) % (int)((v).size())]);
  return abs(ret);
}
bool onpol(pt p, vector<pt> v) {
  for (int i = 0; i < (int)((v).size()); i++)
    if (isinseg(p, line(v[i], v[(i + 1) % (int)((v).size())]))) return 1;
  return 0;
}
bool inpol(pt p, vector<pt> v) {
  if (onpol(p, v)) return 1;
  int c = 0;
  line r = line(p, pt(DINF, pi * DINF));
  for (int i = 0; i < (int)((v).size()); i++) {
    line second = line(v[i], v[(i + 1) % (int)((v).size())]);
    if (interseg(r, second)) c++;
  }
  return c & 1;
}
bool interpol(vector<pt> v1, vector<pt> v2) {
  for (int i = 0; i < (int)((v1).size()); i++)
    if (inpol(v1[i], v2)) return 1;
  for (int i = 0; i < (int)((v2).size()); i++)
    if (inpol(v2[i], v1)) return 1;
  return 0;
}
long double distpol(vector<pt> v1, vector<pt> v2) {
  if (interpol(v1, v2)) return 0;
  long double ret = DINF;
  for (int i = 0; i < (int)((v1).size()); i++)
    for (int j = 0; j < (int)((v2).size()); j++)
      ret = min(ret, distseg(line(v1[i], v1[(i + 1) % (int)((v1).size())]),
                             line(v2[j], v2[(j + 1) % (int)((v2).size())])));
  return ret;
}
vector<pt> convexhull(vector<pt> v) {
  vector<pt> l, u;
  sort(v.begin(), v.end());
  for (int i = 0; i < (int)((v).size()); i++) {
    while ((int)((l).size()) > 1 and
           !ccw(v[i], l[(int)((l).size()) - 1], l[(int)((l).size()) - 2]))
      l.pop_back();
    l.push_back(v[i]);
  }
  for (int i = (int)((v).size()) - 1; i >= 0; i--) {
    while ((int)((u).size()) > 1 and
           !ccw(v[i], u[(int)((u).size()) - 1], u[(int)((u).size()) - 2]))
      u.pop_back();
    u.push_back(v[i]);
  }
  l.pop_back();
  u.pop_back();
  for (int i = 0; i < (int)((u).size()); i++) l.push_back(u[i]);
  return l;
}
pt getcenter(pt a, pt b, pt c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return inter(line(b, b + rotate90(a - b)), line(c, c + rotate90(a - c)));
}
long double angle(pt a, pt b, pt c) {
  pt x = b - a, y = c - b;
  long double C = dot(x, y) / (norm(x) * norm(y));
  long double A = cross(x, y);
  if (A < 0) C = pi - C;
  return acos(C);
}
void le(pt& a) { scanf("%Lf %Lf", &a.x, &a.y); }
int main() {
  pt a, b, c;
  le(a), le(b), le(c);
  if (eq(dist(a, b), dist(b, c)) and !col(a, b, c))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
