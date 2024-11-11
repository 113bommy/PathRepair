#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const long long mod = 998244353;
const double eps = 1e-10;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, k, mx, tot;
struct node {
  double x, y;
} p[500005], t[4 * 500005], st;
node operator-(node a, node b) { return node{a.x - b.x, a.y - b.y}; }
node operator+(node a, node b) { return node{a.x + b.x, a.y + b.y}; }
node operator*(node a, double x) { return node{a.x * x, a.y * x}; }
bool operator==(node a, node b) {
  return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
}
double operator*(node a, node b) { return a.x * b.y - a.y * b.x; }
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x > 0) return 1;
  return -1;
}
double get_area(node x, node y, node z) { return abs((x - y) * (z - y)); }
double cdot(node a, node b) { return a.x * b.x + a.y * b.y; }
double sqr(double x) { return x * x; }
double get_dis(node x, node y) { return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y)); }
double get_fan(node x) { return sqrt(sqr(x.x) + sqr(x.y)); }
bool is_parallel(node a, node b) { return a * b == 0 ? 1 : 0; }
double get_r(node x, node y, node z) {
  double a = get_dis(x, y), b = get_dis(x, z), c = get_dis(y, z);
  double theta = acos((b * b + c * c - a * a) / 2 / b / c);
  return a / 2 / sin(theta);
}
double parallel_dis(node st, node en, node nd) {
  double tot_area = fabs((en - st) * (nd - st));
  return tot_area / get_dis(st, en);
}
bool cmp(node a, node b) {
  int t = sgn((a - st) * (b - st));
  if (t != 0) return t > 0;
  return get_dis(a, st) < get_dis(b, st);
}
node get_intersection(node a, node b, node c, node d) {
  double a1 = a.y - b.y, a2 = c.y - d.y;
  double b1 = b.x - a.x, b2 = d.x - c.x;
  double c1 = a * b, c2 = c * d;
  double x = c1 * b2 - c2 * b1, y = c1 * a2 - c2 * a1;
  x /= a2 * b1 - a1 * b2, y /= a1 * b2 - a2 * b1;
  return node{x, y};
}
double get_angle(node a, node b) {
  return acos((a.x * b.x + a.y * b.y) / get_fan(a) / get_fan(b));
}
void get_Convex_Graham(node p[], int &len) {
  int i, tp = 2;
  for (i = 3; i <= len; i++) {
    while (tp > 1 && sgn((p[i] - p[tp - 1]) * (p[tp] - p[tp - 1])) >= 0) tp--;
    p[++tp] = p[i];
  }
  len = tp;
  return;
}
void add(node x) {
  if (x.x >= 0 && x.x <= 1e5 && x.y >= 0 && x.y <= 1e5) t[++tot] = x;
}
int main() {
  int i, j;
  double x, y;
  n = read();
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf", &x, &y);
    int v = read();
    add(node{x, y + v}), add(node{x, y - v}), add(node{x - v, y}),
        add(node{x + v, y});
    if (x + y <= v) add(node{0, 0});
    if (x + 1e5 - y <= v) add(node{0, 1e5});
    if (1e5 - x + y <= v) add(node{1e5, 0});
    if (1e5 - x + 1e5 - y <= v) add(node{1e5, 1e5});
    if (x < v) add(node{0, y - (v - x)}), add(node{0, y + (v - x)});
    if (y < v) add(node{x - (v - y), 0}), add(node{x + (v - y), 0});
    if (1e5 - x < v)
      add(node{1e5, y + (v + x - 1e5)}), add(node{1e5, y - (v + x - 1e5)});
    if (1e5 - y < v)
      add(node{x + (v + y - 1e5), 1e5}), add(node{x - (v + y - 1e5), 1e5});
  }
  int w = 1;
  for (i = 2; i <= tot; i++)
    if (t[i].x < t[w].x || (t[w].x == t[i].x && t[i].y < t[w].y)) w = i;
  swap(t[w], t[1]);
  st = t[1];
  sort(t + 2, t + tot + 1, cmp);
  get_Convex_Graham(t, tot);
  t[++tot] = t[1], t[++tot] = t[2];
  double R = 0, now;
  w = 0;
  for (i = 1; i <= tot - 2; i++) {
    now = get_r(t[i], t[i + 1], t[i + 2]);
    if (now > R) R = now, w = i;
  }
  printf("%d %d\n", (int)(t[w].x + eps), (int)(t[w].y + eps));
  printf("%d %d\n", (int)(t[w + 1].x + eps), (int)(t[w + 1].y + eps));
  printf("%d %d\n", (int)(t[w + 2].x + eps), (int)(t[w + 2].y + eps));
  return 0;
}
