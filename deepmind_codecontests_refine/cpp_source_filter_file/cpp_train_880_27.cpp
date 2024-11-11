#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
struct P {
  double x, y;
  P() {}
  P(int x, int y) : x(double(x)), y(double(y)) {}
  P(double x, double y) : x(x), y(y) {}
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  double operator^(const P &a) const { return x * a.x + y * a.y; }
  void in() { scanf("%lf%lf", &x, &y); }
  void out() { printf("REQUIRED %.7f %.7f\n", x, y); }
  double dist(P a, P b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }
  double sqdist(P a, P b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }
};
int h, n, m, k, q;
int s[200001 + 200001];
int x1[200001], x2[200001], y3[200001], y2[200001];
int l[600000], r[600000], va[600000];
void build(int u, int lb, int rb) {
  va[u] = 0;
  if (lb == rb) return;
  build(l[u] = ++h, lb, (lb + rb) / 2);
  build(r[u] = ++h, (lb + rb) / 2 + 1, rb);
}
void update(int u, int lb, int rb, int pos, int val) {
  if (lb == rb) {
    va[u] = val;
    return;
  }
  if ((lb + rb) / 2 >= pos)
    update(l[u], lb, (lb + rb) / 2, pos, val);
  else
    update(r[u], (lb + rb) / 2 + 1, rb, pos, val);
  va[u] = min(va[l[u]], va[r[u]]);
}
int query(int u, int lb, int rb, int lq, int rq) {
  if (lb >= lq && rb <= rq) return va[u];
  int mid = (lb + rb) / 2;
  int t1 = 2147483647, t2 = 2147483647;
  if (mid >= lq) t1 = query(l[u], lb, mid, lq, rq);
  if (mid < rq) t2 = query(r[u], mid + 1, rb, lq, rq);
  return min(t1, t2);
}
struct dat {
  int x, y, ty, id;
  dat() {}
  dat(int x, int y, int ty, int id) : x(x), y(y), ty(ty), id(id) {}
} a[200001 + 200001];
bool compx(dat u, dat v) {
  if (u.x == v.x) return u.ty < v.ty;
  return u.x < v.x;
}
bool compy(dat u, dat v) {
  if (u.y == v.y) return u.ty < v.ty;
  return u.y < v.y;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = (1); i <= (k); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = dat(x, y, 0, 0);
  }
  for (int i = (1); i <= (q); i++) {
    scanf("%d%d%d%d", &x1[i], &y3[i], &x2[i], &y2[i]);
    a[i + k] = dat(x2[i], y2[i], 1, i);
    s[i] = 0;
  }
  sort(a + 1, a + k + q + 1, compx);
  build(0, 1, m);
  for (int i = (1); i <= (k + q); i++) {
    if (a[i].ty == 0)
      update(0, 1, n, a[i].y, a[i].x);
    else {
      int w = a[i].id;
      if (query(0, 1, n, y3[w], y2[w]) >= x1[w]) s[w] = 1;
    }
  }
  sort(a + 1, a + k + q + 1, compy);
  h = 0;
  build(0, 1, n);
  for (int i = (1); i <= (k + q); i++) {
    if (a[i].ty == 0)
      update(0, 1, n, a[i].x, a[i].y);
    else {
      int w = a[i].id;
      if (query(0, 1, n, x1[w], x2[w]) >= y3[w]) s[w] = 1;
    }
  }
  for (int i = (1); i <= (q); i++)
    if (s[i])
      puts("YES");
    else
      puts("NO");
  return 0;
}
