#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int n;
long long area, cnt;
double fac[200], calc, ans;
struct Point {
  long long x, y;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
  Point operator-(const Point& tmp) const {
    return Point(x - tmp.x, y - tmp.y);
  }
} p[maxn];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
int main() {
  if (fopen("D.in", "r") != NULL) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
  }
  n = read();
  for (int i = 0; i < n; i++) p[i].x = read(), p[i].y = read();
  fac[0] = 1;
  for (int i = 1; i <= 63; i++) fac[i] = fac[i - 1] * 2;
  if (n <= 63) calc = fac[n] - 1 - n - n * (n - 1) / 2;
  for (int i = 0; i < n; i++)
    cnt += gcd(abs(p[i].x - p[(i + 1) % n].x), abs(p[i].y - p[(i + 1) % n].y));
  for (int i = 1; i < n - 1; i++) area += cross(p[i] - p[0], p[i + 1] - p[0]);
  ans = (area - cnt) / 2 + 1;
  for (int i = 0; i < n; i++) {
    area = 0,
    cnt =
        gcd(abs(p[i].x - p[(i + 1) % n].x), abs(p[i].y - p[(i + 1) % n].y)) + 1;
    for (int k = 2, j; k <= 62; k++) {
      j = (i + k) % n;
      if ((j + 1) % n == i) break;
      cnt += gcd(abs(p[j].x - p[(j - 1 + n) % n].x),
                 abs(p[j].y - p[(j - 1 + n) % n].y));
      area += cross(p[(j + n - 1) % n] - p[i], p[j] - p[i]);
      long long tmp = gcd(abs(p[j].x - p[i].x), abs(p[j].y - p[i].y)) - 1;
      long long s = (area - (cnt + tmp)) / 2 + 1;
      if (n <= 100)
        ans -= (double)(tmp + s) * (fac[n - k - 1] - 1) / calc;
      else
        ans -= (double)(tmp + s) * (1.0 / fac[k + 1]);
    }
  }
  printf("%.12lf\n", ans);
  return 0;
}
