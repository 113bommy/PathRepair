#include <bits/stdc++.h>
using namespace std;
int qr() {
  char ch = getchar();
  int x = 1, s = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return x * s;
}
int n, m, tree[1000002 << 2], tag[1000002 << 2], ans = 1e6, r;
struct node {
  int l, r, w;
} seg[300002];
bool cmp(node a, node b) { return a.w < b.w; }
int minn(int a, int b) { return a < b ? a : b; }
void upd(int id) { tree[id] = minn(tree[id << 1], tree[id << 1 | 1]); }
void pushdown(int id) {
  int ls = id << 1, rs = id << 1 | 1;
  tree[ls] += tag[id];
  tag[ls] += tag[id];
  tree[rs] += tag[id];
  tag[rs] += tag[id];
  tag[id] = 0;
}
void add(int l, int r, int i, int j, int id, int d) {
  if (l <= i && j <= r) {
    tree[id] += d;
    tag[id] += d;
    return;
  }
  int mid = (i + j) >> 1, ls = id << 1, rs = id << 1 | 1;
  pushdown(id);
  if (l <= mid) add(l, r, i, mid, ls, d);
  if (r > mid) add(l, r, mid + 1, j, rs, d);
  upd(id);
}
int main() {
  n = qr();
  m = qr();
  for (int i = 1; i <= n; i++) {
    seg[i].l = qr();
    seg[i].r = qr();
    seg[i].w = qr();
  }
  sort(seg + 1, seg + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    while (r < n && tree[1] == 0) {
      r++;
      add(seg[r].l, seg[r].r - 1, 1, m - 1, 1, 1);
    }
    if (tree[1] == 0) break;
    if (ans > seg[r].w - seg[i].w) ans = seg[r].w - seg[i].w;
    add(seg[i].l, seg[i].r - 1, 1, m - 1, 1, -1);
  }
  printf("%d", ans);
  return 0;
}
