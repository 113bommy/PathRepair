#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int M = 100 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double PI = acos(-1);
int n, m;
double dis(double x, double y) { return sqrt(x * x + y * y); }
struct seg_tree {
  struct node {
    int l, r;
    double x, y, angle;
  } a[N << 2];
  void up(int rt) {
    a[rt].x = a[rt << 1].x + a[rt << 1 | 1].x;
    a[rt].y = a[rt << 1].y + a[rt << 1 | 1].y;
  }
  void down(int rt) {
    if (a[rt].angle == 0.00) return;
    double ang = a[rt].angle;
    a[rt].angle = 0;
    a[rt << 1].angle += ang;
    a[rt << 1 | 1].angle += ang;
    double x = a[rt << 1].x, y = a[rt << 1].y;
    a[rt << 1].x = cos(ang) * x - sin(ang) * y;
    a[rt << 1].y = sin(ang) * x + cos(ang) * y;
    x = a[rt << 1 | 1].x, y = a[rt << 1 | 1].y;
    a[rt << 1 | 1].x = cos(ang) * x - sin(ang) * y;
    a[rt << 1 | 1].y = sin(ang) * x + cos(ang) * y;
  }
  void build(int l, int r, int rt) {
    a[rt].l = l, a[rt].r = r;
    if (l == r) {
      a[rt].x = 1, a[rt].y = 0;
      a[rt].angle = 0;
      return;
    }
    int mid = (l + r >> 1);
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    up(rt);
  }
  void update_ang(int L, int R, int rt, double ang) {
    int l = a[rt].l, r = a[rt].r;
    if (l >= L && r <= R) {
      a[rt].angle += ang;
      double x = a[rt].x, y = a[rt].y;
      a[rt].x = cos(ang) * x - sin(ang) * y;
      a[rt].y = sin(ang) * x + cos(ang) * y;
      return;
    }
    int mid = (l + r) >> 1;
    down(rt);
    if (L <= mid) update_ang(L, R, rt << 1, ang);
    if (R > mid) update_ang(L, R, rt << 1 | 1, ang);
    up(rt);
  }
  void update_len(int pos, int rt, double len) {
    int l = a[rt].l, r = a[rt].r;
    if (l == r) {
      double d = dis(a[rt].x, a[rt].y);
      double x = a[rt].x / d * len, y = a[rt].y / d * len;
      a[rt].x += x;
      a[rt].y += y;
      return;
    }
    int mid = (l + r) >> 1;
    down(rt);
    if (pos <= mid)
      update_len(pos, rt << 1, len);
    else
      update_len(pos, rt << 1 | 1, len);
    up(rt);
  }
} seg;
int main() {
  scanf("%d%d", &n, &m);
  seg.build(1, n, 1);
  while (m--) {
    int op, num;
    double v;
    scanf("%d %d %lf", &op, &num, &v);
    if (op == 1) {
      seg.update_len(num, 1, v);
    } else {
      v = v * PI / 180.0;
      seg.update_ang(num, n, 1, -v);
    }
    printf("%.12f %.12f\n", seg.a[1].x, seg.a[1].y);
  }
  return 0;
}
