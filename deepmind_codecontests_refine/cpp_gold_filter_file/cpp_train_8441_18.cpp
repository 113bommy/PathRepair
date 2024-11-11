#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch;
  ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  if (f)
    return x;
  else
    return -x;
}
const int N = 2010;
int n, m;
long long ans;
struct Point {
  double x, y, ang;
} P[N], p[N];
inline bool operator<(const Point &a, const Point &b) { return a.ang < b.ang; }
inline Point operator-(const Point &a, const Point &b) {
  return (Point){a.x - b.x, a.y - b.y};
}
inline double Cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
inline long long solve(int A, int B) {
  int L = (1ll * B - A + n - 1) % (n - 1), R = n - 2 - L;
  return 1ll * L * (L - 1) / 2 * R * (R - 1) / 2;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) P[i].x = 1.0 * read(), P[i].y = 1.0 * read();
  for (int i = 1; i <= n; i++) {
    m = 0;
    for (int j = 1; j <= n; j++)
      if (i != j) {
        p[++m] = P[j];
        p[m].ang = atan2(P[j].y - P[i].y, P[j].x - P[i].x);
        if (p[m].ang < 0) p[m].ang += pi * 2;
      }
    sort(p + 1, p + 1 + m);
    int pos = 1;
    for (int j = 2; j <= m; j++)
      if (Cross(p[1] - P[i], p[j] - P[i]) > 0) pos = j;
    ans += solve(1, pos);
    for (int j = 2; j <= m; j++) {
      while (Cross(p[j] - P[i], p[((pos) < (n - 1) ? (pos) + 1 : 1)] - P[i]) >
             0)
        pos = ((pos) < (n - 1) ? (pos) + 1 : 1);
      ans += solve(j, pos);
    }
  }
  printf("%I64d\n", ans >> 1);
  return 0;
}
