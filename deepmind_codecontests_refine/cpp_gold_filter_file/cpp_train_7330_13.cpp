#include <bits/stdc++.h>
using namespace std;
int n, m, d[1000000], maxx, ansl, ansr, a[2000000], lazy[2000000], f[1000000],
    e[1000000];
struct arr {
  int x, bo, num;
} b[1000000];
struct what {
  int x, y;
} c[1000000];
bool cmp(arr x, arr y) {
  return ((x.x < y.x) || ((x.x == y.x) && (x.bo > y.bo)));
}
void pushdown(int k) {
  if (!lazy[k]) return;
  int t = lazy[k];
  lazy[k * 2] += t;
  lazy[k * 2 + 1] += t;
  a[k * 2] += t;
  a[k * 2 + 1] += t;
  lazy[k] = 0;
}
void update(int l, int r, int k, int x, int y, int z) {
  if (l >= x && r <= y) {
    lazy[k] += z;
    a[k] += z;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(k);
  if (x <= mid) update(l, mid, k * 2, x, y, z);
  if (y > mid) update(mid + 1, r, k * 2 + 1, x, y, z);
  a[k] = max(a[k * 2], a[k * 2 + 1]);
}
int find(int l, int r, int k) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  pushdown(k);
  if (a[k * 2 + 1] > a[k * 2])
    return find(mid + 1, r, k * 2 + 1);
  else
    return find(l, mid, k * 2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    ++m;
    b[m] = {x, 1, i};
    ++m;
    b[m] = {y, -1, i};
    c[i] = {y, z};
    d[i] = y;
    e[i] = x;
    f[i] = z;
  }
  sort(b + 1, b + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    update(1, 300000, 1, c[b[i].num].x, c[b[i].num].y, b[i].bo);
    if (maxx < a[1]) {
      maxx = a[1];
      ansl = b[i].x;
      ansr = find(1, 300000, 1);
    }
  }
  printf("%d\n", maxx);
  for (int i = 1; i <= n; i++)
    if (d[i] >= ansl && e[i] <= ansl && d[i] <= ansr && ansr <= f[i])
      printf("%d ", i);
}
