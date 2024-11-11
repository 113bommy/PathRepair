#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 10;
struct tree {
  int l, r, val, tag, pos;
} t[mxn << 2];
struct xian {
  int x1, x2, val, y;
} s[2 * mxn];
int l0[mxn], r0[mxn], v0[mxn], n, cnt, ans, ansx, ansy, x[2 * mxn];
void build(int ro, int l, int r) {
  t[ro].l = l;
  t[ro].r = r;
  if (l == r) {
    t[ro].pos = x[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(ro << 1, l, mid);
  build(ro << 1 | 1, mid + 1, r);
  t[ro].pos = t[ro << 1].pos;
}
bool cmp(xian a, xian b) { return a.y == b.y ? a.val < b.val : a.y < b.y; }
void pushdown(int ro) {
  t[ro << 1].val += t[ro].tag;
  t[ro << 1].tag += t[ro].tag;
  t[ro << 1 | 1].val += t[ro].tag;
  t[ro << 1 | 1].tag += t[ro].tag;
  t[ro].tag = 0;
}
void pushup(int ro) {
  if (t[ro << 1].val > t[ro << 1 | 1].val) {
    t[ro].val = t[ro << 1].val;
    t[ro].pos = t[ro << 1].pos;
  } else {
    t[ro].val = t[ro << 1 | 1].val;
    t[ro].pos = t[ro << 1 | 1].pos;
  }
}
void updat(int ro, int l, int r, int val) {
  pushdown(ro);
  if (x[t[ro].l] >= l && x[t[ro].r] <= r) {
    t[ro].val += val;
    t[ro].tag += val;
    return;
  }
  int mid = (t[ro].l + t[ro].r) >> 1;
  if (l <= x[mid]) updat(ro << 1, l, r, val);
  if (r > x[mid]) updat(ro << 1 | 1, l, r, val);
  pushup(ro);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &l0[i], &v0[i], &r0[i]);
    s[++cnt].y = l0[i], s[cnt].x1 = v0[i], s[cnt].x2 = r0[i], s[cnt].val = 1;
    x[cnt] = v0[i];
    s[++cnt].y = v0[i], s[cnt].x1 = v0[i], s[cnt].x2 = r0[i], s[cnt].val = -1;
    x[cnt] = r0[i];
  }
  sort(x + 1, x + cnt + 1);
  int tot = unique(x + 1, x + cnt + 1) - x - 1;
  build(1, 1, tot);
  sort(s + 1, s + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    updat(1, s[i].x1, s[i].x2, s[i].val);
    if (t[1].val > ans) {
      ans = t[1].val;
      ansx = t[1].pos;
      ansy = s[i].y;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (l0[i] <= ansy && v0[i] >= ansy && v0[i] <= ansx && r0[i] >= ansx)
      printf("%d ", i);
  }
  return 0;
}
