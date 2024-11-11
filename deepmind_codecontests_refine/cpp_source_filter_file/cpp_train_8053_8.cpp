#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double pi = acos(-1), eps = 1e-10;
int rd() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
int n, m, bt[N];
void add(int x, int y) {
  while (x <= m) bt[x] = max(bt[x], y), x += x & (-x);
}
int gsm(int x) {
  int an = 0;
  while (x) an = max(an, bt[x]), x -= x & (-x);
  return an;
}
double a1, a2, bx[N];
double fc() {
  double y = rd(), x = rd();
  return atan2(y, x);
}
struct node {
  double x, y;
  bool operator<(const node &bb) const {
    return fabs(y - bb.y) < eps ? y > bb.y : x < bb.x;
  }
} a[N];
int main() {
  n = rd(), a1 = fc(), a2 = fc() - a1;
  for (int i = 1; i <= n; ++i) {
    double xx = rd(), yy = rd();
    a[i].x = cos(-a1) * xx - sin(-a1) * yy,
    a[i].y = cos(-a1) * yy + sin(-a1) * xx;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i].y < eps || atan2(a[i].y, a[i].x) > a2 - eps)
      a[i].y = -1;
    else {
      a[i].x -= fabs(a2 - pi / 2) > eps ? a[i].y / tan(a2) : 0;
      bx[i] = a[i].x;
    }
  }
  a[++n] = (node){0, 0};
  sort(a + 1, a + n + 1);
  sort(bx + 1, bx + n + 1);
  for (int i = 1; i <= n; ++i)
    if (i == 1 || fabs(bx[i] - bx[i - 1]) > eps) bx[++m] = bx[i];
  bx[m + 1] = 1e9;
  while (a[n].y < -eps) --n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int xx = upper_bound(bx + 1, bx + m + 2, a[i].x) - bx - 1;
    int nw = gsm(m - (xx + 1) + 1) + 1;
    if (i == n)
      ans = nw;
    else
      add(m - xx + 1, nw);
  }
  printf("%d\n", ans - 1);
  return 0;
}
