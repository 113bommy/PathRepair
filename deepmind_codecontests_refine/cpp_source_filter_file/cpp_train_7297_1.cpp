#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
template <class T, class U>
using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
constexpr ll MOD = 1000000007;
constexpr ll HIGHINF = (ll)1e18;
constexpr int INF = 1e9;
ll gcdll(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcdll(b, a % b);
}
struct Point {
  ll x, y;
  constexpr bool operator<(const Point& p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  constexpr bool operator==(const Point& p) const {
    return x == p.x && y == p.y;
  }
};
ll cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
ll dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ll norm(Point a) { return a.x * a.x + a.y * a.y; }
int ccw(Point p0, Point p1, Point p2) {
  Point a = {p1.x - p0.x, p1.y - p0.y}, b = {p2.x - p0.x, p2.y - p0.y};
  if (cross(a, b) > 0) return 1;
  if (cross(a, b) < 0) return -1;
  if (dot(a, b) < 0) return 2;
  if (norm(a) < norm(b)) return -2;
  return 0;
}
bool intersect(Point a1, Point a2, Point b1, Point b2) {
  return (ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
          ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  V<Point> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += gcdll(abs(a[i].x - b[i].x), abs(a[i].y - b[i].y)) + 1;
    Point base = {a[i].x - b[i].x, a[i].y - b[i].y};
    set<Point> crossp;
    for (int j = 0; j < i; j++) {
      if (!intersect(a[i], b[i], a[j], b[j])) continue;
      Point tmp1 = {a[j].x - a[i].x, a[j].y - a[i].y},
            tmp2 = {b[j].x - a[i].x, b[j].y - a[i].y};
      ll d1 = abs(cross(base, tmp1)), d2 = abs(cross(base, tmp2));
      ll gcdd = gcdll(d1, d2);
      d1 /= gcdd, d2 /= gcdd;
      Point ret = {b[j].x - a[j].x, b[j].y - a[j].y};
      if (abs(ret.x) % (d1 + d2) != 0 || abs(ret.y) % (d1 + d2) != 0) continue;
      crossp.insert(Point(
          {a[j].x + ret.x / (d1 + d2) * d1, a[j].y + ret.y / (d1 + d2) * d2}));
    }
    ans -= ll(crossp.size());
  }
  cout << ans << '\n';
  return 0;
}
