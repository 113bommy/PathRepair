#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int maxn = 2000 + 10;
struct Line {
  int a, b, c;
} e[maxn];
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 1 ? -1 : 1;
}
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
} inter;
int n, top;
double st[maxn];
long long ans;
inline int read() {
  int x = 0, f = 1;
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
inline double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
inline double Length(Point A) { return sqrt(Dot(A, A)); }
inline double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
inline double Angle(Point A, Point B) {
  double cos = Dot(A, B) / Length(A) / Length(B);
  double sin = Cross(A, B) / Length(A) / Length(B);
  return atan2(sin, cos);
}
inline Point Get_Inter(int l, int r) {
  return Point(((double)e[l].b * e[r].c - e[l].c * e[r].b) /
                   ((double)e[l].a * e[r].b - e[l].b * e[r].a),
               ((double)e[l].a * e[r].c - e[l].c * e[r].a) /
                   ((double)e[l].b * e[r].a - e[l].a * e[r].b));
}
inline bool On_left(Point A, Point B) {
  if (dcmp(A.x * B.y - A.y * B.x) <= 0) return 0;
  return 1;
}
int main() {
  if (fopen("D.in", "r") != NULL) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
  }
  n = read();
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    e[i].a = read(), e[i].b = read();
    e[i].c = read(), e[i].c *= -1;
    if (e[i].c == 0) res++, i--, n--;
  }
  if (res) res = (res * (res - 1) >> 1) * n;
  for (int i = 1; i <= n; i++) {
    top = 0;
    Point v = Point(-e[i].b, e[i].a);
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      inter = Get_Inter(i, j);
      if (On_left(v, Point(-e[j].b, e[j].a)) ^ On_left(v, inter))
        st[++top] = Angle(Point(e[j].b, -e[j].a), inter);
      else
        st[++top] = Angle(Point(-e[j].b, e[j].a), inter);
    }
    sort(st + 1, st + top + 1);
    st[top + 1] = 100;
    for (int j = 2, cnt = 1; j <= top + 1; j++)
      if (dcmp(st[j] - st[j - 1]) != 0) {
        ans += (long long)cnt * (cnt - 1) >> 1;
        cnt = 1;
      } else
        cnt++;
  }
  printf("%I64d\n", (ans >> 1) + res);
  return 0;
}
