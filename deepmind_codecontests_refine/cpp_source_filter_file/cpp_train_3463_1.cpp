#include <bits/stdc++.h>
using namespace std;
int getInt() {
  int x = 0;
  char ch;
  bool flag = false;
  ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  while ((ch >= '0' && ch <= '9') || ch == '-') {
    if (ch == '-') {
      flag = true;
      ch = getchar();
    }
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return flag ? -x : x;
}
int n, m;
struct TREE {
  int l, mid, r, dis;
  double lPro, rPro;
} tree[200010];
struct MUSHROOM {
  int pos, power;
} mush[200010];
int b[2000020], cur;
double ans;
struct NODE {
  int l, r;
  double tag, pro;
} seg[1000010];
int mogu[1000010];
void build(int i, int l, int r) {
  seg[i].l = l;
  seg[i].r = r;
  seg[i].tag = 1;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
}
void pushDown(int i) {
  if (seg[i].tag != 1) {
    seg[i << 1].tag *= seg[i].tag;
    seg[i << 1 | 1].tag *= seg[i].tag;
    seg[i].tag = 1;
  }
}
void update(int i, int L, int R, double k) {
  if (L <= seg[i].l && seg[i].r <= R) {
    seg[i].tag *= k;
    return;
  }
  int mid = (seg[i].l + seg[i].r) >> 1;
  if (L <= mid) {
    update(i << 1, L, R, k);
  }
  if (R > mid) {
    update(i << 1 | 1, L, R, k);
  }
}
void pushDownRoot(int i) {
  if (seg[i].l == seg[i].r) return;
  pushDown(i);
  pushDownRoot(i << 1);
  pushDownRoot(i << 1 | 1);
}
void getAns(int i) {
  if (seg[i].l == seg[i].r) {
    ans += mogu[seg[i].l] * seg[i].tag;
    return;
  }
  getAns(i << 1);
  getAns(i << 1 | 1);
}
int main() {
  n = getInt();
  m = getInt();
  for (int i = 1; i <= n; i++) {
    tree[i].mid = getInt();
    tree[i].dis = getInt();
    tree[i].l = tree[i].mid - tree[i].dis;
    tree[i].r = tree[i].mid + tree[i].dis;
    tree[i].lPro = (double)getInt() / 100;
    tree[i].rPro = (double)getInt() / 100;
    b[cur++] = tree[i].l;
    b[cur++] = tree[i].r;
    b[cur++] = tree[i].mid;
  }
  for (int i = 1; i <= m; i++) {
    mush[i].pos = getInt();
    mush[i].power = getInt();
    b[cur++] = mush[i].pos;
  }
  sort(b, b + cur);
  cur = unique(b, b + cur) - b;
  for (int i = 1; i <= n; i++) {
    tree[i].mid = lower_bound(b, b + cur, tree[i].mid) - b + 1;
    tree[i].l = lower_bound(b, b + cur, tree[i].l) - b + 1;
    tree[i].r = lower_bound(b, b + cur, tree[i].r) - b + 1;
  }
  for (int i = 1; i <= m; i++) {
    mush[i].pos = lower_bound(b, b + cur, mush[i].pos) - b + 1;
    mogu[mush[i].pos] += mush[i].power;
  }
  build(1, 1, cur);
  for (int i = 1; i <= n; i++) {
    update(1, tree[i].l, tree[i].mid - 1, tree[i].lPro);
    update(1, tree[i].mid + 1, tree[i].r, tree[i].rPro);
  }
  pushDownRoot(1);
  getAns(1);
  printf("%.10f\n", ans);
  return 0;
}
