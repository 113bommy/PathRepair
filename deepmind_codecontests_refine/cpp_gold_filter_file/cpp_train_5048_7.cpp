#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(const T &a) {
  return a * a;
}
struct Point {
  long long x, y;
  Point() { x = y = 0; }
  Point(long long _x, long long _y) : x(_x), y(_y) {}
  Point operator-(const Point &a) { return Point(x - a.x, y - a.y); }
  bool operator==(const Point &a) const {
    return make_pair(x, y) == make_pair(a.x, a.y);
  }
  bool operator<(const Point &a) const { return (x * a.y - y * a.x) < 0; }
};
int n;
Point a[3000], b[3000];
double c[3000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)n; i++) scanf("%I64d%I64d", &a[i].x, &a[i].y);
  long long ans = 0;
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n; j++) b[j] = a[j] - a[i];
    rotate(b, b + i, b + n);
    for (int j = 1; j < (int)n; j++)
      if (!b[j].y)
        c[j] = 1e9;
      else
        c[j] = 1.0 * b[j].x / b[j].y;
    sort(c + 1, c + n);
    int cnt = 1;
    for (int j = 1; j < (int)n - 1; j++) {
      if (abs(c[j + 1] - c[j]) > 1e-6) {
        if (cnt) ans += (cnt - 1) * (cnt);
        cnt = 0;
      }
      cnt++;
    }
    if (cnt) ans += (cnt - 1) * (cnt);
  }
  printf(
      "%lld"
      "\n",
      1ll * n * (n - 1) * (n - 2) / 6 - (ans) / 6);
}
