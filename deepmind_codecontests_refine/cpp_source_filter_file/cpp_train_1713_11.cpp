#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  int fh = 1;
  while (!isdigit(c)) {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= fh;
}
struct Info {
  int nu, x, y, su;
} a[100010];
struct seg {
  int l, r, be, en;
} t[100010 * 4];
int num, li[10000010], c[100010], nc, n, q, x, y;
bool comp(const int &x, const int &y) {
  if (a[x].x != a[y].x) return a[x].x < a[y].x;
  return a[x].y < a[y].y;
}
long long nx(int x) { return a[x].x; }
long long ny(int x) { return a[x].y; }
void build(int nu, int l, int r) {
  t[nu].l = l;
  t[nu].r = r;
  nc = 0;
  for (int i = l; i <= r; i++) c[++nc] = i;
  sort(c + 1, c + nc + 1, comp);
  t[nu].be = num + 1;
  t[nu].en = num;
  for (int i = 1; i <= nc; i++) {
    while (t[nu].be < t[nu].en &&
           (ny(li[t[nu].en]) - ny(li[t[nu].en - 1])) *
                   (nx(c[i]) - nx(li[t[nu].en])) >=
               (ny(c[i]) - ny(li[t[nu].en])) *
                   (nx(li[t[nu].en]) - nx(li[t[nu].en - 1])))
      t[nu].en--;
    li[++t[nu].en] = c[i];
  }
  num = t[nu].en;
  if (l != r) {
    build(nu * 2, l, (l + r) / 2);
    build(nu * 2 + 1, (l + r) / 2 + 1, r);
  }
}
int que1(int l, int r, int k) {
  while (l < r) {
    int mid = (l + r) / 2;
    if ((ny(li[mid + 1]) - ny(li[mid])) >= k * (nx(li[mid + 1]) - nx(li[mid])))
      r = mid;
    else
      l = mid + 1;
  }
  return k * nx(li[r]) + ny(li[r]);
}
int que(int nu, int l, int r, int k) {
  if (t[nu].l == l && t[nu].r == r) return que1(t[nu].be, t[nu].en, k);
  int mid = (t[nu].l + t[nu].r) / 2;
  if (l > mid) return que(nu * 2 + 1, l, r, k);
  if (r <= mid) return que(nu * 2, l, r, k);
  return min(que(nu * 2, l, mid, k), que(nu * 2 + 1, mid + 1, r, k));
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i].nu);
  for (int i = 1; i <= n; i++) a[i].su = a[i - 1].su + a[i].nu;
  for (int i = 1; i <= n; i++) {
    a[i].y = a[i].nu * i - a[i].su;
    a[i].x = a[i].nu;
  }
  build(1, 1, n);
  read(q);
  while (q--) {
    read(x);
    read(y);
    printf("%d\n", a[y].su + que(1, y - x + 1, y, x - y));
  }
  return 0;
}
