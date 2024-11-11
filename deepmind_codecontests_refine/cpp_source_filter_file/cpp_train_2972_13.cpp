#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
struct Point {
  long long x, y;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
  void read() { scanf("%lld%lld", &x, &y); }
  void write() { printf("%lld %lld\n", x, y); }
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; }
};
long long dot(const Point& A, const Point& B) { return A.x * B.x + A.y * B.y; }
long long det(const Point& A, const Point& B) { return A.x * B.y - A.y * B.x; }
Point ps[N], ch[N];
int convexHull(Point* p, int n, Point* ch) {
  sort(p, p + n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    while (m > 1 && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
    ch[m++] = p[i];
  }
  for (int i = n - 2, t = m; ~i; --i) {
    while (m > t && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
    ch[m++] = p[i];
  }
  if (n > 1) --m;
  return m;
}
vector<int> rotatingCalipers(Point* ch, int n) {
  if (n < 3) return vector<int>();
  int ans = 0;
  vector<int> ret(3);
  ch[n] = ch[0];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1, k = j; j < n; ++j) {
      while (det(ch[j] - ch[i], ch[k + 1] - ch[i]) >
             det(ch[j] - ch[i], ch[k] - ch[i]))
        k = (k + 1) % n;
      if (det(ch[j] - ch[i], ch[k] - ch[i]) > ans) {
        ans = det(ch[j] - ch[i], ch[k] - ch[i]);
        ret = {i, j, k};
      }
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  long long s;
  scanf("%d%lld", &n, &s);
  for (int i = 0; i < n; ++i) ps[i].read();
  int m = convexHull(ps, n, ch);
  vector<int> triangle = rotatingCalipers(ch, m);
  for (int i = 0; i < 3; ++i) {
    Point p =
        ch[triangle[i]] + ch[triangle[(i + 1) % 3]] - ch[triangle[(i + 2) % 3]];
    p.write();
  }
  return 0;
}
