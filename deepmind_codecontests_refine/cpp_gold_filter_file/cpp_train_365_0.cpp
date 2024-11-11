#include <bits/stdc++.h>
using namespace std;
const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point {
  double x, y;
  point(double a, double b) : x(a), y(b) {}
  point() : x(0.0), y(0.0) {}
  point operator+(point q) { return point(x + q.x, y + q.y); }
  point operator-(point q) { return point(x - q.x, y - q.y); }
  point operator*(double t) { return point(x * t, y * t); }
  point operator/(double t) { return point(x / t, y / t); }
  double operator*(point q) { return x * q.x + y * q.y; }
  double operator^(point q) { return x * q.y - y * q.x; }
  double polar() { return ((y > -EPS) ? atan2(y, x) : 2 * PI + atan2(y, x)); }
  double mod() { return sqrt(x * x + y * y); }
  double mod2() { return (x * x + y * y); }
  point rotate(double t) {
    return point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
  }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator==(point q) const { return cmp(q) == 0; }
  bool operator!=(point q) const { return cmp(q) != 0; }
  bool operator<(point q) const { return cmp(q) < 0; }
};
int n, tam;
point P[MAX];
point Q[MAX * MAX];
inline int ccw(point p, point q, point r) { return cmp((q - r) ^ (p - r)); }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;
  if (P[0].x == P[1].x) {
    tam = 0;
    if (P[1].y > P[0].y) {
      for (int i = P[0].y; i <= P[1].y; i++) Q[tam++] = point(P[0].x, i);
    } else {
      for (int i = P[0].y; i >= P[1].y; i--) Q[tam++] = point(P[0].x, i);
    }
  } else if (P[0].y == P[1].y) {
    tam = 0;
    if (P[1].x > P[0].x) {
      for (int i = P[0].x; i <= P[1].x; i++) Q[tam++] = point(i, P[0].y);
    } else {
      for (int i = P[0].x; i >= P[1].x; i--) Q[tam++] = point(i, P[0].y);
    }
  } else {
    tam = 0;
    int g = gcd((int)(abs(P[0].y - P[1].y)), (int)(abs(P[0].x - P[1].x)));
    int p = (P[0].y - P[1].y) / g;
    int q = (P[0].x - P[1].x) / g;
    for (int i = P[0].x; q ? (i <= P[1].x) : (i >= P[1].x); i += q)
      Q[tam++] = point(i, P[0].y + ((i - P[0].x) * p) / q);
  }
  int st = 0, ed = tam - 1;
  fprintf(stderr, "%d %d\n", st, ed);
  for (int i = 1; i < n; i++) {
    while (st <= ed && ccw(P[i], P[(i + 1) % n], Q[st]) < 0) st++;
    while (ed >= st && ccw(P[i], P[(i + 1) % n], Q[ed]) < 0) ed--;
  }
  cout << max(ed - st + 1, 0) << '\n';
}
