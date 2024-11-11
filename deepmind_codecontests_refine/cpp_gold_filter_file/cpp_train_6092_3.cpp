#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int maxn = 1000010;
struct node {
  int l, r;
  double x, y;
  double the;
} a[maxn << 2];
void rot(double &x, double &y, double the) {
  double newx = x * cos(the) + y * sin(the);
  double newy = -x * sin(the) + y * cos(the);
  x = newx;
  y = newy;
}
void pushdown(int i) {
  rot(a[i].x, a[i].y, a[i].the);
  if (a[i].l != a[i].r) {
    a[2 * i].the += a[i].the;
    a[2 * i + 1].the += a[i].the;
  }
  a[i].the = 0;
}
void pushup(int i) {
  a[i].x = a[2 * i].x + a[2 * i + 1].x;
  a[i].y = a[2 * i].y + a[2 * i + 1].y;
}
void init(int i, int l, int r) {
  a[i].l = l;
  a[i].r = r;
  a[i].x = r - l + 1;
  a[i].y = 0;
  a[i].the = 0;
  if (l != r) {
    int mid = (l + r) / 2;
    init(2 * i, l, mid);
    init(2 * i + 1, mid + 1, r);
  }
}
void insert(int i, int left, int right, int type, int val) {
  pushdown(i);
  pushdown(2 * i);
  pushdown(2 * i + 1);
  int l = a[i].l;
  int r = a[i].r;
  if (l == left && r == right) {
    if (type == 1) {
      double x = a[i].x;
      double y = a[i].y;
      a[i].x += val * x / sqrt(x * x + y * y);
      a[i].y += val * y / sqrt(x * x + y * y);
    } else {
      double the = val * pi / 180.0;
      rot(a[i].x, a[i].y, the);
      a[2 * i].the = the;
      a[2 * i + 1].the = the;
    }
    return;
  }
  int mid = (l + r) / 2;
  if (right <= mid)
    insert(2 * i, left, right, type, val);
  else if (left >= mid + 1)
    insert(2 * i + 1, left, right, type, val);
  else {
    insert(2 * i, left, mid, type, val);
    insert(2 * i + 1, mid + 1, right, type, val);
  }
  pushdown(2 * i);
  pushdown(2 * i + 1);
  pushup(i);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  init(1, 1, n);
  while (m--) {
    int type, num, val;
    scanf("%d%d%d", &type, &num, &val);
    if (type == 1)
      insert(1, num, num, type, val);
    else
      insert(1, num, n, type, val);
    printf("%lf %lf\n", a[1].x, a[1].y);
  }
  return 0;
}
