#include <bits/stdc++.h>
using namespace std;
int n, m, q, l, r;
double d, s, t, x, y;
int tree[2000010 * 4], pl[2000010 * 4], pr[2000010 * 4], cnt = 1;
bool flag[2000010 * 4];
void change(int l, int r, int id, int l1, int r1) {
  if (l >= l1 && r <= r1) {
    tree[id] = r - l + 1;
    flag[id] = 1;
    return;
  }
  if (flag[id]) return;
  int mid = (l + r) >> 1;
  if (l1 <= mid) {
    if (pl[id] == 0) pl[id] = ++cnt;
    change(l, mid, pl[id], l1, r1);
  }
  if (r1 > mid) {
    if (pr[id] == 0) pr[id] = ++cnt;
    change(mid + 1, r, pr[id], l1, r1);
  }
  tree[id] = tree[pl[id]] + tree[pr[id]];
}
int dist(int l, int r, int l1, int r1) {
  int l2 = max(l, l1);
  int r2 = min(r, r1);
  return r2 - l2 + 1;
}
int query(int l, int r, int id, int l1, int r1) {
  if (l1 > r1) return 0;
  if (l >= l1 && r <= r1) return tree[id];
  if (flag[id]) return dist(l, r, l1, r1);
  int mid = (l + r) >> 1;
  int res = 0;
  if (l1 <= mid && pl[id]) res += query(l, mid, pl[id], l1, r1);
  if (r1 > mid && pr[id]) res += query(mid + 1, r, pr[id], l1, r1);
  return res;
}
int main() {
  scanf("%lf%lf%lf", &d, &s, &t);
  d *= -1.0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l, &r);
    change(1, 0x3FFFFFFF, 1, l, r - 1);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%lf%lf", &x, &y);
    double ts = (y + d) / y;
    double l1 = x + (s - x) / ts;
    double r1 = x + (t - x) / ts;
    int l2 = ceil(l1);
    int r2 = floor(r1);
    double ans = 0;
    if (l2 == r2 + 1) {
      if (query(1, 0x3FFFFFFF, 1, l2 - 1, l2 - 1)) ans = r1 - l1;
    } else {
      ans += query(1, 0x3FFFFFFF, 1, l2, r2 - 1);
      if (query(1, 0x3FFFFFFF, 1, l2 - 1, l2 - 1)) ans += l2 * 1.0 - l1;
      if (query(1, 0x3FFFFFFF, 1, r2, r2)) ans += r1 - r2 * 1.0;
    }
    ans *= ts;
    printf("%.6lf\n", ans);
  }
}
