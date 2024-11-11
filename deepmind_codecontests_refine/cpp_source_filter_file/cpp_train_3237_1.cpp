#include <bits/stdc++.h>
using namespace std;
const long long LLMAX = 2e18;
const int MOD = 1e9 + 7;
const double eps = 1e-12;
const int MAXN = 1e6 + 10;
const int hmod1 = 0x48E2DCE7;
const int hmod2 = 0x60000005;
inline long long sqr(long long x) { return x * x; }
inline int sqr(int x) { return x * x; }
inline double sqr(double x) { return x * x; }
long long __gcd(long long a, long long b) {
  return b == 0 ? a : __gcd(b, a % b);
}
long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return sum;
}
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return (x > 0 ? 1 : -1);
}
int p[MAXN];
struct Point {
  long long x, y, i, j;
  double ang;
  Point() { x = y = 0; }
  Point(long long a, long long b) { x = a, y = b; }
  Point(long long a, long long b, double c) { i = a, j = b, ang = c; }
  Point operator-(const Point &n) const { return Point(x - n.x, y - n.y); }
  bool operator<(const Point &n) const { return x == n.x ? y < n.y : x < n.x; }
  double polar() { return atan2(y, x); }
  void output() { cout << x << ' ' << y << endl; }
} point[2010], vec[4 * MAXN];
long long cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
long long check(int i, int j, int k) {
  return abs(cross(point[j] - point[i], point[k] - point[i]));
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, s, cnt = 0;
  cin >> n >> s;
  s *= 2;
  for (int i = 0; i < n; i++) cin >> point[i].x >> point[i].y, p[i] = i;
  sort(point, point + n);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      vec[cnt++] = Point(i, j, (point[j] - point[i]).polar());
  sort(vec, vec + cnt, [](Point a, Point b) { return a.ang < b.ang; });
  for (int i = 0; i < cnt; i++) {
    int a = vec[i].i, b = vec[i].j;
    if (p[a] > p[b]) swap(a, b);
    int l = 0, r = p[a] - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      long long area = check(p[a], p[b], mid);
      if (area == s) {
        ans = mid;
        break;
      } else if (area > s)
        l = mid + 1;
      else
        r = mid - 1;
    }
    if (ans != -1) {
      cout << "Yes" << endl;
      point[p[a]].output();
      point[p[b]].output();
      point[p[ans]].output();
      return 0;
    }
    swap(p[a], p[b]);
    swap(point[p[a]], point[p[b]]);
  }
  cout << "No" << endl;
  return 0;
}
