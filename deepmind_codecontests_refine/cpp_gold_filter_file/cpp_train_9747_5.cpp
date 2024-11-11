#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double Pi = acos(-1.0);
const int N = 3e5 + 10;
inline int dcmp(double x) { return (x < -eps) ? -1 : (x > eps ? 1 : 0); }
inline double Abs(double x) { return x * dcmp(x); }
namespace CG {
struct pt {
  double x, y;
  pt(double _x = 0, double _y = 0) {
    x = _x;
    y = _y;
  }
  inline void read() { scanf("%lf%lf", &x, &y); }
};
inline bool cmpx(const pt &a, const pt &b) {
  return (a.x != b.x) ? a.x < b.x : a.y < b.y;
}
inline double Len(const pt &a) { return sqrt(a.x * a.x + a.y * a.y); }
inline double angle(const pt &a) { return atan2(a.y, a.x); }
inline pt operator+(const pt &a, const pt &b) {
  return pt(a.x + b.x, a.y + b.y);
}
inline pt operator-(const pt &a, const pt &b) {
  return pt(a.x - b.x, a.y - b.y);
}
inline pt operator*(const pt &a, double b) { return pt(a.x * b, a.y * b); }
inline pt operator/(const pt &a, double b) { return pt(a.x / b, a.y / b); }
inline double operator*(const pt &a, const pt &b) {
  return a.x * b.x + a.y * b.y;
}
inline double operator^(const pt &a, const pt &b) {
  return a.x * b.y - a.y * b.x;
}
inline pt rotate(pt a, double theta) {
  double x = a.x * cos(theta) - a.y * sin(theta);
  double y = a.x * sin(theta) + a.y * cos(theta);
  return pt(x, y);
}
inline pt rotate_90(pt a) { return pt(a.y, -a.x); }
inline pt rotate_P(pt a, pt b, double theta) {
  return rotate(a - b, theta) + b;
}
struct line {
  pt s, t;
  line(pt _s = pt(0, 0), pt _t = pt(0, 0)) {
    s = _s;
    t = _t;
  }
};
inline double maxx(const line &L) { return max(L.s.x, L.t.x); }
inline double maxy(const line &L) { return max(L.s.y, L.t.y); }
inline double minx(const line &L) { return min(L.s.x, L.t.x); }
inline double miny(const line &L) { return min(L.s.y, L.t.y); }
inline double ang(const line &L) { return angle(L.t - L.s); }
inline bool operator<(const line &a, const line &b) {
  double a1 = angle(a.t - a.s), a2 = angle(b.t - b.s);
  if (dcmp(a2 - a1) != 0) return dcmp(a2 - a1) > 0;
  return dcmp((b.t - a.s) ^ (a.t - a.s)) > 0;
}
inline bool operator==(pt a, pt b) {
  return (!dcmp(a.x - b.x)) && (!dcmp(a.y - b.y));
}
inline double dis_PP(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline bool judge_PL(pt a, line b) { return !dcmp((a - b.s) ^ (b.t - b.s)); }
inline bool judge_PS(pt a, line b) {
  return (!dcmp((a - b.s) ^ (b.t - b.s))) && (dcmp((a - b.s) * (a - b.t)) <= 0);
}
inline pt Footprint(pt a, line b) {
  pt x = a - b.s, y = a - b.t, z = b.t - b.s;
  double s1 = x * z, s2 = -1.0 * (y * z);
  return b.s + z * (s1 / (s1 + s2));
}
inline pt mirror(pt a, line b) { return a + (Footprint(a, b) - a) * 2.0; }
inline double dis_PL(pt a, line b) {
  return Abs((a - b.s) ^ (a - b.t)) / Len(b.t - b.s);
}
inline double dis_PS(pt a, line b) {
  pt x = a - b.s, y = a - b.t, z = b.t - b.s;
  if (dcmp(x * z) < 0) return Len(x);
  if (dcmp(y * z) > 0) return Len(y);
  return dis_PL(a, b);
}
inline pt point_PS(pt a, line b) {
  pt x = a - b.s, y = a - b.t, z = b.t - b.s;
  if (dcmp(x * z) < 0) return b.s;
  if (dcmp(y * z) > 0) return b.t;
  return Footprint(a, b);
}
inline pt cross_LL(line a, line b) {
  pt x = a.t - a.s, y = b.t - b.s, z = a.s - b.s;
  return a.s + x * ((y ^ z) / (x ^ y));
}
inline bool judge_cross_SL(line a, line b) {
  if (!dcmp((a.t - a.s) ^ (b.t - b.s))) return false;
  return judge_PS(cross_LL(a, b), a);
}
inline bool judge_cross_SS(line a, line b) {
  if (maxx(a) < minx(b) || maxy(a) < miny(b)) return false;
  if (maxx(b) < minx(a) || maxy(b) < miny(a)) return false;
  double s1 = (a.t - a.s) ^ (b.s - a.s), s2 = (a.t - a.s) ^ (b.t - a.s);
  double s3 = (b.t - b.s) ^ (a.s - b.s), s4 = (b.t - b.s) ^ (a.t - b.s);
  return dcmp(s1) * dcmp(s2) <= 0 && dcmp(s3) * dcmp(s4) <= 0;
}
}  // namespace CG
using namespace CG;
namespace Polygon {
struct polygon {
  vector<pt> pts;
  inline pt &operator[](int x) { return pts[x]; }
  inline void read(int n) {
    pt cur;
    for (int i = 0; i < n; ++i) cur.read(), pts.push_back(cur);
  }
  inline void clear() { pts.clear(); }
  inline int nxt(int x) { return x < pts.size() - 1 ? x + 1 : 0; }
  inline int include(pt p) {
    int cnt = 0;
    for (int i = 0; i < pts.size(); ++i) {
      pt s = pts[i], t = pts[nxt(i)];
      line L = line(s, t);
      if (judge_PS(p, L)) return 2;
      if (dcmp(p.y - miny(L)) >= 0 && dcmp(maxy(L) - p.y) > 0) {
        double nx = s.x + ((p.y - s.y) / (t.y - s.y) * (t.x - s.x));
        if (dcmp(nx - p.x) > 0) cnt++;
      }
    }
    return cnt & 1;
  }
  inline double area() {
    double ans = 0;
    for (int i = 1; i < pts.size() - 1; ++i)
      ans += (pts[i] - pts[0]) ^ (pts[nxt(i)] - pts[0]);
    return Abs(ans) / 2;
  }
  inline double peri() {
    double ans = 0;
    for (int i = 0; i < pts.size(); ++i) ans += dis_PP(pts[i], pts[nxt(i)]);
    return ans;
  }
  inline bool Left(pt x, pt l, pt r) { return dcmp((l - x) ^ (r - x)) <= 0; }
  inline void rever() { reverse(pts.begin(), pts.end()); }
  inline int include_bs(pt p) {
    int n = pts.size();
    if (!Left(pts[0], p, pts[1])) return 0;
    if (!Left(pts[0], pts[n - 1], p)) return 0;
    if (judge_PS(p, line(pts[0], pts[1]))) return 2;
    if (judge_PS(p, line(pts[0], pts[n - 1]))) return 2;
    int l = 1, r = n - 2, ans = 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (!Left(pts[0], pts[mid], p))
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    if (!Left(pts[ans], p, pts[nxt(ans)])) return 0;
    if (judge_PS(p, line(pts[ans], pts[nxt(ans)]))) return 2;
    return 1;
  }
  inline void insert(pt p) { pts.push_back(p); }
};
inline bool disjoint(polygon A, polygon B) {
  for (int i = 0; i < A.pts.size(); ++i) {
    line x = line(A[i], A[A.nxt(i)]);
    for (int j = 0; j < B.pts.size(); ++j) {
      line y = line(B[j], B[B.nxt(j)]);
      if (judge_cross_SS(x, y)) return false;
    }
  }
  if (A.include_bs(B[0])) return false;
  if (B.include_bs(A[0])) return false;
  return true;
}
}  // namespace Polygon
using namespace Polygon;
namespace Hull {
inline void Andrew(polygon &p) {
  vector<pt> q(p.pts.size() << 1);
  sort(p.pts.begin(), p.pts.end(), cmpx);
  int top = 0, n = p.pts.size();
  q[++top] = p[0];
  for (int i = 1; i < n; ++i) {
    while (top >= 2 && dcmp((q[top - 1] - q[top]) ^ (p[i] - q[top])) >= 0)
      top--;
    q[++top] = p[i];
  }
  int now = top;
  for (int i = n - 2; i >= 0; --i) {
    while (top > now && dcmp((q[top - 1] - q[top]) ^ (p[i] - q[top])) >= 0)
      --top;
    q[++top] = p[i];
  }
  if (n > 1) --top;
  p.clear();
  for (int i = 1; i <= top; ++i) p.insert(q[i]);
}
inline double S(const pt &x, const pt &y, const pt &z) {
  return Abs((y - x) ^ (z - x));
}
inline double diam(polygon &p) {
  int n = p.pts.size();
  double ans = 0;
  for (int i = 0, j = 1; i < n; ++i) {
    for (;; j = p.nxt(j))
      if (dcmp(S(p[j], p[i], p[p.nxt(i)]) -
               S(p[p.nxt(j)], p[i], p[p.nxt(i)])) >= 0)
        break;
    ans = max(ans, dis_PP(p[j], p[i]));
    ans = max(ans, dis_PP(p[j], p[p.nxt(i)]));
  }
  return ans;
}
inline polygon SI(vector<line> q) {
  int n = q.size();
  sort(q.begin(), q.end());
  vector<line> li(n + 1), L(n + 1);
  vector<pt> p(n + 1);
  int len = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && !dcmp(ang(q[i]) - ang(q[i - 1]))) continue;
    L[++len] = q[i];
  }
  int l = 1, r = 0;
  for (int i = 1; i <= len; ++i) {
    while (l < r && dcmp((L[i].t - p[r]) ^ (L[i].s - p[r])) > 0) --r;
    while (l < r && dcmp((L[i].t - p[l + 1]) ^ (L[i].s - p[l + 1])) > 0) ++l;
    li[++r] = L[i];
    if (r > l) p[r] = cross_LL(li[r], li[r - 1]);
  }
  while (l < r && dcmp((li[l].t - p[r]) ^ (li[l].s - p[r])) > 0) --r;
  while (l < r && dcmp((li[r].t - p[l + 1]) ^ (li[r].s - p[l + 1])) > 0) ++l;
  p[r + 1] = cross_LL(li[r], li[l]), ++r;
  polygon P;
  for (int j = l + 1; j <= r; ++j) P.insert(p[j]);
  return P;
}
inline polygon merge(polygon A, polygon B) {
  int n = A.pts.size(), m = B.pts.size(), tot1 = 0, tot2 = 0;
  vector<pt> p(n + 1), q(m + 1);
  for (int i = 1; i < n; ++i) p[++tot1] = A[i] - A[i - 1];
  p[++tot1] = A[0] - A[n - 1];
  for (int i = 1; i < m; ++i) q[++tot2] = B[i] - B[i - 1];
  q[++tot2] = B[0] - B[m - 1];
  int i = 1, j = 1, tot = 0;
  pt last = pt(0, 0);
  polygon C;
  C.pts.resize(n + m + 1);
  C[0] = last = A[0] + B[0];
  while (i <= n && j <= m) {
    if (dcmp(p[i] ^ q[j]) >= 0)
      C[++tot] = last + p[i++], last = C[tot];
    else
      C[++tot] = last + q[j++], last = C[tot];
  }
  while (i <= n) C[++tot] = last + p[i++], last = C[tot];
  while (j <= m) C[++tot] = last + q[j++], last = C[tot];
  Andrew(C);
  return C;
}
}  // namespace Hull
using Hull::Andrew;
using Hull::diam;
using Hull::merge;
namespace Circle {
struct circle {
  pt o;
  double r;
  circle(pt _o = pt(0, 0), double _r = 0) {
    o = _o;
    r = _r;
  }
  circle(pt A, pt B, pt C) {
    pt D = (A + B) / 2, E = (B + C) / 2;
    o = cross_LL(line(D, D + rotate_90(B - A)), line(E, E + rotate_90(C - B)));
    r = dis_PP(o, A);
  }
  inline bool include(pt p) { return dcmp(r - dis_PP(p, o)) >= 0; }
  inline void print(int x) {
    printf("%.*lf\n", x, r);
    printf("%.*lf %.*lf", x, o.x, x, o.y);
  }
};
inline circle mincov(const vector<pt> &p) {
  int n = p.size();
  circle c = circle(0, 0);
  for (int i = 0; i < n; ++i) {
    if (!c.include(p[i])) {
      c = circle(p[i], 0);
      for (int j = 0; j < i; ++j) {
        if (!c.include(p[j])) {
          c = circle((p[i] + p[j]) / 2.0, dis_PP(p[i], p[j]) / 2.0);
          for (int k = 0; k < j; ++k)
            if (!c.include(p[k])) c = circle(p[i], p[j], p[k]);
        }
      }
    }
  }
  return c;
}
}  // namespace Circle
using namespace Circle;
int n, m, d, q;
double x, y;
polygon A, B, C;
int main() {
  scanf("%d", &n);
  A.read(n);
  scanf("%d", &m);
  B.read(m);
  scanf("%d", &d);
  C.read(d);
  Andrew(A);
  Andrew(B);
  Andrew(C);
  A = merge(merge(A, B), C);
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%lf%lf", &x, &y);
    puts(A.include_bs(pt(x, y) * 3.0) > 0 ? "YES" : "NO");
  }
  return 0;
}
