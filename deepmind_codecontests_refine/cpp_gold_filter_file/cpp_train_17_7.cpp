#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int n, q;
struct node {
  int x, y, z;
} a[maxn], b[maxn], c[maxn];
int tot = 1, ans[maxn];
bool tmp(const node &u, const node &v) {
  if (u.x != v.x) return u.x > v.x;
  return u.y < v.y;
}
bool cc(const node &u, const node &v) {
  if (u.x != v.x) return u.x < v.x;
  return u.y < v.y;
}
bool cmp(const node &u, const node &v) { return u.y < v.y; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].x), a[i].y = i;
  sort(a + 1, a + n + 1, tmp);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) scanf("%d %d", &b[i].x, &b[i].y), b[i].z = i;
  sort(b + 1, b + q + 1, cc);
  for (int i = 1; i <= q;) {
    int m = b[i].x;
    for (; tot <= m; tot++) c[tot].x = a[tot].x, c[tot].y = a[tot].y;
    sort(c + 1, c + tot, cmp);
    for (; b[i].x == m; i++) ans[b[i].z] = c[b[i].y].x;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
