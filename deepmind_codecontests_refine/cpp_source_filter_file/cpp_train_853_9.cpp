#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, z;
} a[500005];
int y[500005];
struct seg_tree {
  int l, r;
  int cnt;
} s[1500006];
bool cmpy(const node a, const node b) { return a.y < b.y; }
bool cmpx(const node a, const node b) {
  if (a.x != b.x)
    return a.x > b.x;
  else if (a.y != b.y)
    return a.y > b.y;
  else
    return a.z > b.z;
}
void build(int l, int r, int i) {
  s[i].l = l;
  s[i].r = r;
  s[i].cnt = -1;
  if (l == r) return;
  int m = (s[i].l + s[i].r) / 2;
  build(l, m, i * 2);
  build(m + 1, r, i * 2 + 1);
}
void update(int l, int i, int cnt) {
  s[i].cnt = max(s[i].cnt, cnt);
  if (s[i].l == s[i].r) return;
  int m = (s[i].l + s[i].r) / 2;
  if (l <= m)
    update(l, i * 2, cnt);
  else if (l > m)
    update(l, i * 2 + 1, cnt);
}
int query(int l, int r, int i) {
  if (l > r) return -1;
  if (s[i].l == l && s[i].r == r) {
    return s[i].cnt;
  }
  int m = (s[i].l + s[i].r) / 2;
  if (r <= m)
    return query(l, r, i * 2);
  else if (l > m)
    return query(l, r, i * 2 + 1);
  else
    return max(query(l, m, i * 2), query(m + 1, r, i * 2 + 1));
}
int main() {
  int n, i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &a[i].x);
    for (i = 0; i < n; i++) scanf("%d", &a[i].y);
    for (i = 0; i < n; i++) scanf("%d", &a[i].z);
    sort(a, a + n, cmpy);
    y[0] = a[0].y;
    a[0].y = 1;
    for (i = 1; i < n; i++) {
      y[i] = a[i].y;
      if (y[i] == y[i - 1])
        a[i].y = a[i - 1].y;
      else
        a[i].y = a[i - 1].y + 1;
    }
    int m = a[n - 1].y;
    sort(a, a + n, cmpx);
    build(1, m, 1);
    int ans = 0;
    for (i = 0; i < n; i++) {
      for (j = i; j < n && a[i].x == a[j].x; j++) {
        if (query(a[j].y + 1, m, 1) > a[j].z) ans++;
      }
      for (j = i; j < n && a[i].x == a[j].x; j++) {
        update(a[j].y, 1, a[j].z);
      }
    }
    printf("%d\n", ans);
  }
}
