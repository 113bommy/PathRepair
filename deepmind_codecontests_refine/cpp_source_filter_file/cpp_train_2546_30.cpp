#include <bits/stdc++.h>
struct box {
  double x, y, a1[3], a2[3];
  int cnt;
} wall[1000000];
int min[5000000];
double v, ang[1000000];
inline int h(int l, int r) { return (l + r) | (l != r); }
void solve(double x, double y, int num) {
  double a, b, c, delta, sdelta, x1, x2;
  a = 9.8 * x * x / 2 / v / v;
  b = -x;
  c = 9.8 * x * x / 2 / v / v + y;
  delta = b * b - 4 * a * c;
  if (delta >= 0) {
    sdelta = sqrt(delta);
    x1 = (-sdelta - b) / 2 / a;
    x2 = (sdelta - b) / 2 / a;
  }
  if (delta <= 0) {
    wall[num].cnt = 1;
    wall[num].a1[1] = 0;
    wall[num].a2[1] = 1;
    return;
  }
  if (x1 >= 0) {
    wall[num].a1[++wall[num].cnt] = 0;
    wall[num].a2[wall[num].cnt] = std::min(1.0, x1);
  }
  if (x2 <= 1) {
    wall[num].a1[++wall[num].cnt] = std::max(0.0, x2);
    wall[num].a2[wall[num].cnt] = 1;
  }
}
int comp(const void *p, const void *q) {
  return (*(struct box *)p).x > (*(struct box *)q).x ? 1 : -1;
}
void insert(int l, int r, int ll, int rr, int num) {
  int mid = (l + r) >> 1;
  if (l == ll && r == rr) {
    min[h(l, r)] = num;
    return;
  }
  if (min[h(l, r)] > 0) min[h(l, mid)] = min[h(mid + 1, r)] = min[h(l, r)];
  min[h(l, r)] = 0;
  if (ll > mid)
    insert(mid + 1, r, ll, rr, num);
  else if (rr <= mid)
    insert(l, mid, ll, rr, num);
  else
    insert(l, mid, ll, mid, num), insert(mid + 1, r, mid + 1, rr, num);
}
int query(int l, int r, int pos) {
  if (l == r)
    return min[h(l, r)];
  else if (min[h(l, r)])
    return min[h(l, r)];
  int mid = (l + r) >> 1;
  if (min[h(l, r)]) min[h(l, mid)] = min[h(mid + 1, r)] = min[h(l, r)];
  if (pos > mid)
    return query(mid + 1, r, pos);
  else
    return query(l, mid, pos);
}
void calc(double alpha) {
  int tmp = query(1, 1000001, tan(alpha) * 1000000 + 1);
  double time = wall[tmp].x / (v * cos(alpha));
  if (tmp == 0 || v * sin(alpha) * time - 9.8 * time * time / 2 <= 0) {
    printf("%.5lf 0\n", 2 * v * sin(alpha) / 9.8 * v * cos(alpha));
    return;
  }
  printf("%.5lf %.5lf\n", wall[tmp].x,
         v * sin(alpha) * time - 9.8 * time * time / 2);
}
int main() {
  int i, n, m;
  scanf("%d%lf", &n, &v);
  for (i = 1; i <= n; i++) scanf("%lf", &ang[i]);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%lf%lf", &wall[i].x, &wall[i].y);
    wall[i].cnt = 0;
    solve(wall[i].x, wall[i].y, i);
  }
  qsort(wall + 1, m, sizeof(wall[0]), comp);
  for (i = m; i >= 1; i--)
    for (int j = 1; j <= wall[i].cnt; j++) {
      int l = wall[i].a1[wall[i].cnt] * 1000000 + 1;
      int r = wall[i].a2[wall[i].cnt] * 1000000 + 1;
      insert(1, 1000001, l, r, i);
    }
  for (i = 1; i <= n; i++) calc(ang[i]);
}
