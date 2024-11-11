#include <bits/stdc++.h>
const int maxn = 2010;
const double eps = 1e-12, pi = acos(-1);
using namespace std;
int n, cnt, ans;
double ang[maxn];
int dcmp(double x) { return fabs(x) < eps ? 0 : x < 0 ? -1 : 1; }
struct poi {
  double x, y;
} ori = (poi){0, 0};
poi operator+(const poi &p, const poi &v) {
  return (poi){p.x + v.x, p.y + v.y};
}
poi operator-(const poi &a, const poi &b) {
  return (poi){a.x - b.x, a.y - b.y};
}
poi operator*(const poi &v, const double &k) { return (poi){v.x * k, v.y * k}; }
bool operator==(const poi &a, const poi &b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double cross(poi a, poi b) { return a.x * b.y - a.y * b.x; }
struct line {
  poi p;
  poi v;
  void print() {
    if (dcmp(v.x) == 0)
      printf("x=%.3lf\n", p.x);
    else
      printf("y=%.3lfx+%.3lf\n", v.y / v.x, p.y);
  }
} l[maxn];
poi get_line_intersection(line a, line b) {
  poi v = a.p - b.p;
  double t = cross(b.v, v) / cross(a.v, b.v);
  return a.p + a.v * t;
}
double get_intersection_angle(poi u, poi v) {
  double angle = atan2(u.y, u.x) - atan2(v.y, v.x);
  if (dcmp(angle) < 0) angle += 2.0 * pi;
  if (dcmp(angle - pi) >= 0) angle -= pi;
  return angle;
}
void billy(int a, int b) {
  poi o = get_line_intersection(l[a], l[b]);
  if (o == ori) {
    ans += a - 2;
    return;
  }
  poi u = ori - o, v = l[b].v;
  double angle = get_intersection_angle(u, v);
  ang[++cnt] = angle;
}
void count() {
  sort(ang + 1, ang + cnt + 1);
  ang[cnt + 1] = -1;
  int lover = 1;
  for (int i = 1; i <= cnt; i++)
    if (dcmp(ang[i] - ang[i + 1]) != 0) {
      ans += lover * (lover - 1) / 2;
      lover = 1;
    } else
      lover++;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    c *= -1;
    if (dcmp(b) == 0)
      l[i] = (line){(poi){-c / a, 0}, (poi){0, 1}};
    else
      l[i] = (line){(poi){0, -c / b}, (poi){-b, a}};
    cnt = 0;
    for (int j = 1; j < i; j++) billy(i, j);
    count();
  }
  printf("%d\n", ans);
  return 0;
}
