#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50;
struct pnt {
  int x, y;
  pnt(int _x = 0, int _y = 0) { x = _x, y = _y; }
  void input() { scanf("%d%d", &x, &y); }
  pnt operator+(const pnt &a) { return pnt(x + a.x, y + a.y); }
  friend pnt operator-(const pnt &a, const pnt &b) {
    return pnt(a.x - b.x, a.y - b.y);
  }
  int operator*(const pnt &a) { return x * a.y - y * a.x; }
  bool operator<(const pnt &a) const { return x == a.x ? y < a.y : x < a.x; }
  int len() { return x * x + y * y; }
};
int n, m, nd;
pnt a[N], b[N];
pnt c[N], stk[N];
double dot(pnt a, pnt b) { return a.x * b.x + a.y * b.y; }
bool cmp(const pnt &a, const pnt &b) {
  int k = (a - stk[1]) * (b - stk[1]);
  if (k) return k > 0;
  return (a - stk[1]).len() < (b - stk[1]).len();
}
void convex() {
  memcpy(c, a, sizeof(a));
  int top = 1;
  sort(c + 1, c + n + 1);
  stk[top] = c[1];
  sort(c + 2, c + n + 1, cmp);
  for (int i = 2; i <= n; i++) {
    while (top > 1 && (c[i] - stk[top - 1]) * (stk[top] - stk[top - 1]) >= 0)
      --top;
    stk[++top] = c[i];
  }
  nd = top;
  for (int i = 1; i <= nd; i++) c[i] = stk[i];
}
void chk(pnt p, pnt q) {
  double lp = -1e18, rp = 1e18;
  for (int i = 1; i <= n; i++) {
    int x = dot(a[i] - p, a[i] - q);
    int y = (a[i] - p) * (q - p);
    if (!y) continue;
    double r = 1.0 * x / y;
    if (y < 0)
      rp = min(rp, r);
    else
      lp = max(lp, r);
    if (lp >= rp) return;
  }
  for (int i = 1; i <= m; i++) {
    int x = dot(b[i] - p, b[i] - q);
    int y = (b[i] - p) * (q - p);
    if (!y && x < 0) return;
    if (!y) continue;
    double r = 1.0 * x / y;
    if (y > 0)
      rp = min(rp, r);
    else
      lp = max(lp, r);
    if (lp >= rp) return;
  }
  puts("YES");
  exit(0);
}
void divide(int l, int r) {
  if (l + 1 == r) return chk(c[l], c[r]), void();
  double mx = -1e18;
  int pt = 0;
  for (int i = l + 1; i <= r - 1; i++) {
    double t =
        1.0 * dot(c[i] - c[l], c[i] - c[r]) / ((c[l] - c[i]) * (c[l] - c[r]));
    if (t > mx) mx = t, pt = i;
  }
  chk(c[l], c[pt]), chk(c[pt], c[r]);
  divide(l, pt), divide(pt, r);
}
void work() {
  convex();
  chk(c[1], c[nd]);
  divide(1, nd);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) a[i].input();
  for (int i = 1; i <= m; i++) b[i].input();
  work();
  swap(n, m), swap(a, b);
  work();
  puts("NO");
  return 0;
}
