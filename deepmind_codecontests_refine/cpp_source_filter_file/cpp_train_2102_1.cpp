#include <bits/stdc++.h>
using namespace std;
namespace TYC {
const int N = 5e4 + 5;
const double eps = 1e-7, PI = acos(-1);
inline bool equal(const double a, const double b) { return fabs(a - b) < eps; }
struct point {
  double x, y, theta;
  point(const double _x = 0, const double _y = 0) : x(_x), y(_y) { angle(); }
  void angle() { theta = atan2(y, x) + PI; }
  bool operator!=(const point &t) const {
    return !equal(x, t.x) || !equal(y, t.y);
  }
};
double cross(const point &A, const point &B) { return A.x * B.y - A.y * B.x; }
double area(const point &A, const point &B) { return fabs(cross(A, B)) / 2; }
double dis(const point &A) { return sqrt(A.x * A.x + A.y * A.y); }
struct line {
  point A, B;
  line(const point &_A = point(), const point &_B = point()) : A(_A), B(_B) {
    if (cross(A, B) < 0) swap(A, B);
  }
};
point get(const line &L, const double theta) {
  double t = tan(theta);
  if (equal(L.A.x, L.B.x))
    return point(L.A.x, t * L.A.x);
  else {
    double k = (L.A.y - L.B.y) / (L.A.x - L.B.x), b = L.A.y - k * L.A.x;
    return point(b / (t - k), b / (t - k) * t);
  }
}
double dis(const line &L, const double theta) { return dis(get(L, theta)); }
inline bool internal(const point &A, const point &L, const point &R) {
  if (L.theta <= R.theta)
    return L.theta <= A.theta && A.theta <= R.theta;
  else
    return A.theta >= L.theta || A.theta <= R.theta;
}
bool operator<(const line &P, const line &Q) {
  if (P.A != Q.A && P.A != Q.B && internal(P.A, Q.A, Q.B))
    return dis(P, P.A.theta) < dis(Q, P.A.theta);
  if (P.B != Q.A && P.B != Q.B && internal(P.B, Q.A, Q.B))
    return dis(P, P.B.theta) < dis(Q, P.B.theta);
  if (Q.A != P.A && Q.A != P.B && internal(Q.A, P.A, P.B))
    return dis(P, Q.A.theta) < dis(Q, Q.A.theta);
  if (Q.B != P.A && Q.B != P.B && internal(Q.B, P.A, P.B))
    return dis(P, Q.B.theta) < dis(Q, Q.B.theta);
  return false;
}
set<line> S;
int n, lc, dc;
double d[N];
line L[N << 1];
vector<int> in[N], out[N];
inline int getid(const double x) {
  int p = int(lower_bound(d + 1, d + 1 + dc, x) - d);
  return p - (!equal(d[p], x));
}
void work() {
  scanf("%d", &n);
  d[++dc] = 0;
  d[++dc] = 2 * PI - eps;
  static point P[N];
  for (int i = 1, cnt; i <= n; i++) {
    scanf("%d", &cnt);
    point p, tmp;
    scanf("%lf%lf", &p.x, &p.y);
    p.angle();
    P[cnt] = tmp = p;
    while (cnt--) {
      if (cnt) {
        scanf("%lf%lf", &p.x, &p.y);
        p.angle();
        P[cnt] = p;
      } else
        p = tmp;
      if (!equal(p.theta, P[cnt + 1].theta)) {
        d[++dc] = p.theta;
        line l = line(P[cnt + 1], p);
        if (l.A.theta < l.B.theta)
          L[++lc] = l;
        else {
          L[++lc] = line(get(l, 2 * PI - eps), l.A);
          L[++lc] = line(get(l, 0), l.B);
        }
      }
    }
  }
  sort(d + 1, d + 1 + dc);
  dc = int(unique(d + 1, d + 1 + dc, equal) - d);
  for (int i = 1; i <= lc; i++) {
    int a = getid(L[i].A.theta), b = getid(L[i].B.theta);
    if (a < b) in[a].push_back(i), out[b].push_back(i);
  }
  double ans = 0;
  for (int i = 1; i < dc; i++) {
    for (int j : out[i]) S.erase(L[j]);
    for (int j : in[i]) S.insert(L[j]);
    if (int(S.size()) >= 2) {
      line p = *S.begin(), q = *next(S.begin());
      ans += area(get(q, d[i]), get(q, d[i + 1])) -
             area(get(p, d[i]), get(p, d[i + 1]));
    }
  }
  printf("%.10f", ans);
}
}  // namespace TYC
int main() {
  TYC::work();
  return 0;
}
