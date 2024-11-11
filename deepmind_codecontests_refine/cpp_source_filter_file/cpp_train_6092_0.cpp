#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535898;
const int maxn = 300003;
int n, m;
struct fdfdfd {
  int l, r;
  double endx, endy, ang;
} a[maxn << 2];
void pushup(int x) {
  a[x].endx = a[x << 1].endx + a[x << 1 | 1].endx;
  a[x].endy = a[x << 1].endy + a[x << 1 | 1].endy;
}
void pushtag(int x, double d) {
  a[x].ang += d;
  double tx = a[x].endx, ty = a[x].endy;
  a[x].endx = ty * sin(d) + tx * cos(d), a[x].endy = ty * cos(d) - tx * sin(d);
}
void pushdown(int x) {
  if (a[x].ang > 1e-12)
    pushtag(x << 1, a[x].ang), pushtag(x << 1 | 1, a[x].ang), a[x].ang = 0;
}
void build(int x, int left, int right) {
  a[x].l = left;
  a[x].r = right;
  if (left == right) {
    a[x].endx = 1;
    return;
  }
  int mid = left + right >> 1;
  build(x << 1, left, mid);
  build(x << 1 | 1, mid + 1, right);
  pushup(x);
}
void query(int x, int d, double &nowx, double &nowy) {
  if (a[x].l > d || a[x].r < d) return;
  if (a[x].l == d && a[x].r == d) {
    nowx = a[x].endx, nowy = a[x].endy;
    return;
  }
  pushdown(x);
  query(x << 1, d, nowx, nowy);
  query(x << 1 | 1, d, nowx, nowy);
}
void modify_long(int x, int d, double dx, double dy) {
  if (a[x].l > d || a[x].r < d) return;
  if (a[x].l == d && a[x].r == d) {
    a[x].endx += dx, a[x].endy += dy;
    return;
  }
  pushdown(x);
  modify_long(x << 1, d, dx, dy);
  modify_long(x << 1 | 1, d, dx, dy);
  pushup(x);
}
void modify_rot(int x, int left, int right, double d) {
  if (a[x].l > right || a[x].r < left) return;
  if (left <= a[x].l && right >= a[x].r) {
    pushtag(x, d);
    return;
  }
  pushdown(x);
  modify_rot(x << 1, left, right, d);
  modify_rot(x << 1 | 1, left, right, d);
  pushup(x);
}
int main() {
  scanf("%d%d", &n, &m);
  cout << fixed << setprecision(10);
  build(1, 1, n);
  for (int i = 1, t0, t1, t2; i <= m; ++i) {
    scanf("%d%d%d", &t0, &t1, &t2);
    if (t0 == 1) {
      double x, y;
      query(1, t1, x, y);
      modify_long(1, t1, x * t2 / sqrt(x * x + y * y),
                  y * t2 / sqrt(x * x + y * y));
    } else
      modify_rot(1, t1, n, t2 * PI / 180.0);
    cout << a[1].endx << ' ' << a[1].endy << '\n';
  }
  return 0;
}
