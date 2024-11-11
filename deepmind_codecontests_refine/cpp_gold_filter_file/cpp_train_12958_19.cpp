#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100100;
const int INF = 0x7f7f7f7f;
const double eps = 1e-8;
const double pi = 3.1415926535897932384626433832795;
struct Point {
  double x, y;
  Point() {}
  Point(double x1, double y1) : x(x1), y(y1) {}
  bool operator<(const Point &b) const {
    return y < b.y || (y == b.y && x < b.x);
  }
  double Dist(Point p) {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  }
};
bool Cross(Point &p, Point &from, Point &to) {
  return (to.x - from.x) * (p.y - from.y) >= (to.y - from.y) * (p.x - from.x);
}
int Graham(Point pnt[], int n, Point res[]) {
  int len, top = 1;
  sort(pnt, pnt + n);
  if (n == 0) return 0;
  res[0] = pnt[0];
  if (n == 1) return 1;
  res[1] = pnt[1];
  if (n == 2) return 2;
  res[2] = pnt[2];
  for (int i = 2; i < n; i++) {
    while (top && Cross(res[top], res[top - 1], pnt[i])) top--;
    res[++top] = pnt[i];
  }
  len = top;
  res[++top] = pnt[n - 2];
  for (int i = n - 3; i >= 0; i--) {
    while (top != len && Cross(res[top], res[top - 1], pnt[i])) top--;
    res[++top] = pnt[i];
  }
  return top;
}
Point p[Maxn], res[Maxn];
int main() {
  int n, ans = 0, u, v, cnt = 0;
  set<pair<int, int> > st;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &u, &v);
    if (st.find(pair<int, int>(u, v)) == st.end()) {
      p[cnt].x = u;
      p[cnt++].y = v;
      st.insert(pair<int, int>(u, v));
    }
  }
  cnt = Graham(p, cnt, res);
  res[cnt] = res[0];
  for (int i = 0; i < cnt; i++)
    ans += max(abs(res[i].x - res[i + 1].x), abs(res[i].y - res[i + 1].y));
  printf("%d\n", ans + 4);
  return 0;
}
