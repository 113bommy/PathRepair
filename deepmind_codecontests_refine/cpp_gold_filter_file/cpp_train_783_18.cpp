#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
const long double PI = acos(-1);
bool eq(long double a, long double b) { return fabsl(a - b) <= EPS; }
struct point {
  long double x, y;
  int id;
  point(long double x = 0, long double y = 0, int id = 0)
      : x(x), y(y), id(id) {}
  point operator+(const point &o) const { return {x + o.x, y + o.y}; }
  point operator-(const point &o) const { return {x - o.x, y - o.y}; }
  point operator*(long double t) const { return {x * t, y * t}; }
  point operator/(long double t) const { return {x / t, y / t}; }
  long double operator*(const point &o) const { return x * o.x + y * o.y; }
  long double operator^(const point &o) const { return x * o.y - y * o.x; }
  bool operator<(const point &o) const {
    if (!eq(x, o.x)) return x < o.x;
    return y < o.y;
  }
  bool operator==(const point &o) const { return eq(x, o.x) and eq(y, o.y); }
};
long double norm(point a) { return sqrt(a * a); }
int ccw(point a, point b, point e) {
  long double tmp = (b - a) ^ (e - a);
  return (tmp > EPS) - (tmp < -EPS);
}
bool insideT(vector<point> &vet, point e) {
  int x = ccw(vet[0], vet[1], e);
  int y = ccw(vet[1], vet[2], e);
  int z = ccw(vet[2], vet[0], e);
  if (!x or !y or !z) return false;
  return !((x == 1 or y == 1 or z == 1) and (x == -1 or y == -1 or z == -1));
}
struct line {
  point p1, p2;
  long double a, b, c;
  line(point p1 = 0, point p2 = 0) : p1(p1), p2(p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -(a * p1.x + b * p1.y);
  }
  line(long double a = 0, long double b = 0, long double c = 0)
      : a(a), b(b), c(c) {}
  long double eval(point p) { return a * p.x + b * p.y + c; }
  bool inside(point p) { return eq(eval(p), 0); }
  point normal() { return point(a, b); }
  point mid() { return point((p1 + p2) / 2); }
  long double len() { return norm(p2 - p1); }
  bool inside_seg(point p) {
    return (inside(p) and min(p1.x, p2.x) <= p.x and p.x <= max(p1.x, p2.x) and
            min(p1.y, p2.y) <= p.y and p.y <= max(p1.y, p2.y));
  }
};
point inter(line &l1, line &l2) {
  long double det = l1.a * l2.b - l1.b * l2.a;
  if (det == 0) return point(INF, INF);
  long double x = (l1.b * l2.c - l1.c * l2.b) / det;
  long double y = (l1.c * l2.a - l1.a * l2.c) / det;
  return point(x, y);
}
point inter_seg(line &l1, line &l2) {
  point ans = inter(l1, l2);
  if (ans.x == INF or !l1.inside_seg(ans) or !l2.inside_seg(ans))
    return point(INF, INF);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cout << fixed << setprecision(12);
  long long n, w, v, u, x, y;
  cin >> n >> w >> v >> u;
  vector<point> p;
  point low = point(INF, INF), right = point(-INF, -INF);
  bool corremano = true;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p.push_back(point(x, y, i));
    if (x < 0 or y * v > x * u) corremano = false;
    if (y < low.y or (y == low.y and x > low.x)) low = point(x, y, i);
    if (x > right.x or (x == right.x and y < right.y)) right = point(x, y, i);
  }
  if (corremano) {
    cout << w / (long double)u << '\n';
    return 0;
  }
  long double ans = 0;
  point lst = point(0, 0);
  int i;
  for (i = low.id; ((i - 1 + n) % n) != right.id; i = ((i + 1) % n)) {
    long double dy = p[i].y - lst.y;
    long double dx = p[i].x - lst.x;
    if (dx < 0) continue;
    if (dy * v > u * dx) {
      ans += dy / u;
      lst = point(lst.x + (dy * v) / u, lst.y + dy);
    } else {
      ans += dx / v;
      lst = p[i];
    }
  }
  ans += (w - lst.y) / (long double)u;
  cout << ans << '\n';
  return 0;
}
