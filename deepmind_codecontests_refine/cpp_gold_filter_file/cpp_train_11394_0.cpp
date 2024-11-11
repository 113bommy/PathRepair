#include <bits/stdc++.h>
using namespace std;
const int MN = 211;
struct Point {
  long long x, y;
  Point(long long x = 0, long long y = 0) : x(x), y(y) {}
  Point operator+(Point a) { return Point(x + a.x, y + a.y); }
  Point operator-(Point a) { return Point(x - a.x, y - a.y); }
  Point operator*(long long k) { return Point(x * k, y * k); }
  Point operator/(long long k) { return Point(x / k, y / k); }
  long long operator*(Point a) { return x * a.x + y * a.y; }
  long long norm() { return x * x + y * y; }
  bool operator==(Point a) { return x == a.x && y == a.y; }
} a[MN];
int n;
int ccw(Point a, Point b, Point c) {
  b = b - a;
  c = c - a;
  long long t = b.x * c.y - b.y * c.x;
  if (t == 0)
    return 0;
  else if (t < 0)
    return -1;
  else
    return 1;
}
const long long MOD = 1000000007;
long long f[211][211];
bool good[211][211];
bool intersect(Point a, Point b, Point c, Point d) {
  return ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0;
}
int next(int u) {
  if (u == n)
    return 1;
  else
    return u + 1;
}
bool between(Point a, Point b, Point c) {
  if (a == c) return false;
  if (b == c) return false;
  return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y &&
         c.y <= max(a.y, b.y);
}
double angle(Point a, Point o, Point b) {
  a = a - o;
  b = b - o;
  return acos((a * b) / sqrt(a.norm() * (double)b.norm()));
}
bool in_polygon(Point pt) {
  for (int i = (1), _b = (n); i <= _b; i++) {
    if (pt == a[i]) return true;
    Point Pj = a[next(i)];
    if (ccw(a[i], Pj, pt) == 0 && between(a[i], Pj, pt)) return true;
  }
  double sum = 0;
  for (int i = (1), _b = (n); i <= _b; i++) {
    Point Pj = a[next(i)];
    if (ccw(pt, a[i], Pj) > 0)
      sum += angle(a[i], pt, Pj);
    else
      sum -= angle(a[i], pt, Pj);
  }
  return fabs(fabs(sum) - 2 * acos(-1)) < 1e-3;
}
bool check(int i, int j) {
  for (int x = (1), _b = (n); x <= _b; x++) {
    if (ccw(a[i], a[j], a[x]) == 0 && between(a[i], a[j], a[x])) return false;
    if (intersect(a[i], a[j], a[x], a[next(x)])) return false;
  }
  Point mid = (a[i] + a[j]) / 2;
  return in_polygon(mid);
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout << (fixed) << setprecision(6);
  while (cin >> n) {
    for (int i = (1), _b = (n); i <= _b; i++) {
      cin >> a[i].x >> a[i].y;
      a[i] = a[i] * 2;
    }
    memset(f, 0, sizeof f);
    for (int i = (1), _b = (n); i <= _b; i++)
      for (int j = (i + 1), _b = (n); j <= _b; j++)
        good[i][j] = good[j][i] = check(i, j);
    for (int i = (n), _b = (1); i >= _b; i--)
      for (int j = (i + 1), _b = (n); j <= _b; j++) {
        if (j == i + 1) {
          f[i][j] = 1;
          continue;
        }
        if (!good[i][j]) continue;
        if (j == i + 2)
          f[i][j] = 1;
        else {
          for (int k = (i + 1), _b = (j - 1); k <= _b; k++)
            if (good[i][k] && good[k][j])
              f[i][j] = (f[i][j] + f[i][k] * f[k][j]) % MOD;
        }
      }
    cout << f[1][n] << endl;
  }
  return 0;
}
