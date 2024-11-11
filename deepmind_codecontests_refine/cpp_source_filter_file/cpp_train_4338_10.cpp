#include <bits/stdc++.h>
using namespace std;
int n, m, v1, v2, v;
int a[100005], b[100005];
int Q, x, y, xx, yy;
int st, el;
int ans;
void init() { freopen("c.in", "r", stdin); }
int get_a(int l, int r, int tot) {
  int pos = 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (a[mid] < tot) {
      pos = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (pos == v1 || (abs(tot - a[pos]) <= abs(tot - a[pos + 1])))
    return a[pos];
  else
    return a[pos + 1];
}
int get_b(int l, int r, int tot) {
  int pos = 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (b[mid] < tot) {
      pos = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (pos == v2 || (abs(tot - b[pos]) <= abs(tot - b[pos + 1])))
    return b[pos];
  else
    return b[pos + 1];
}
int pd() {
  if (abs(x - xx) % v)
    return 1;
  else
    return 0;
}
void get() {
  if (st != -1) ans = min(ans, abs(y - st) + abs(yy - st) + abs(x - xx));
  if (el != -1)
    ans = min(ans, abs(y - el) + abs(yy - el) + abs(x - xx) / v + pd());
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &v1, &v2, &v);
  for (int i = 1; i <= v1; i++) scanf("%d", &a[i]);
  sort(a + 1, a + v1 + 1);
  for (int i = 1; i <= v2; i++) scanf("%d", &b[i]);
  sort(b + 1, b + v2 + 1);
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d%d%d", &x, &y, &xx, &yy);
    if (x == xx)
      ans = abs(y - yy);
    else
      ans = 2147483647 / 2;
    if (v1)
      st = get_a(1, v1, y);
    else
      st = -1;
    if (v2)
      el = get_b(1, v2, y);
    else
      el = -1;
    get();
    if (v1)
      st = get_a(1, v1, yy);
    else
      st = -1;
    if (v2)
      el = get_b(1, v2, yy);
    else
      el = -1;
    get();
    if (v1)
      st = get_a(1, v1, (y + yy) / 2);
    else
      st = -1;
    if (v2)
      el = get_b(1, v2, (y + yy) / 2);
    else
      el = -1;
    get();
    printf("%d\n", ans);
  }
  return 0;
}
