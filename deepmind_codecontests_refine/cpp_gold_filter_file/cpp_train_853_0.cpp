#include <bits/stdc++.h>
using namespace std;
const int MAXN = 555555;
int MAX[MAXN << 2];
struct Node {
  int x, y, z;
} a[MAXN];
bool cmpy(Node a, Node b) { return a.y < b.y; }
bool cmpx(Node a, Node b) {
  if (a.x == b.x) {
    if (a.y != b.y) return a.y > b.y;
    return a.z > b.z;
  }
  return a.x > b.x;
}
int lson(int rt) { return rt << 1; }
int rson(int rt) { return rt << 1 | 1; }
void pushUp(int rt) { MAX[rt] = max(MAX[lson(rt)], MAX[rson(rt)]); }
void build(int l, int r, int rt) {
  MAX[rt] = -1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, lson(rt));
  build(mid + 1, r, rson(rt));
  pushUp(rt);
}
void update(int p, int c, int l, int r, int rt) {
  if (l == r) {
    MAX[rt] = max(MAX[rt], c);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    update(p, c, l, mid, lson(rt));
  else
    update(p, c, mid + 1, r, rson(rt));
  pushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return MAX[rt];
  }
  int res = -1;
  int mid = (l + r) >> 1;
  if (L <= mid) res = max(res, query(L, R, l, mid, lson(rt)));
  if (R > mid) res = max(res, query(L, R, mid + 1, r, rson(rt)));
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].x);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].y);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].z);
  sort(a + 1, a + n + 1, cmpy);
  a[1].y = 1;
  int pre = a[1].y;
  for (int i = 2; i <= n; i++) {
    int tmp = a[i].y;
    if (a[i].y == pre)
      a[i].y = a[i - 1].y;
    else
      a[i].y = a[i - 1].y + 1;
    pre = tmp;
  }
  int len = a[n].y;
  sort(a + 1, a + n + 1, cmpx);
  build(1, len, 1);
  int ans = 0;
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && a[i].x == a[j].x) {
      if (j <= n && query(a[j].y + 1, len, 1, len, 1) > a[j].z) ans++;
      j++;
    }
    j = i;
    while (j <= n && a[i].x == a[j].x) {
      update(a[j].y, a[j].z, 1, len, 1);
      j++;
    }
    i = j;
  }
  printf("%d\n", ans);
  return 0;
}
