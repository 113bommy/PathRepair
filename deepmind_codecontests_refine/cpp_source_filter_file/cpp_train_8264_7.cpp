#include <bits/stdc++.h>
const int MAX_N = 1 << 18;
int n, m;
int a[MAX_N];
struct node {
  int idx, l, r, val, Or;
} seg[MAX_N << 2];
void build(int l, int r, int idx) {
  seg[idx] = node{idx, l, r, 0, 0};
  if (l == r) {
    seg[idx].val = a[l];
    seg[idx].Or = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, idx << 1);
  build(mid + 1, r, (idx << 1) + 1);
  seg[idx].Or = seg[idx << 1].Or ^ 1;
  if (seg[idx].Or)
    seg[idx].val = seg[idx << 1].val ^ seg[(idx << 1) + 1].val;
  else
    seg[idx].val = seg[idx << 1].val | seg[(idx << 1) + 1].val;
}
void update(int l, int r, int idx, int p, int b) {
  if (l == r) {
    seg[idx].val = b;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    update(l, mid, idx << 1, p, b);
  else
    update(mid + 1, r, (idx << 1) + 1, p, b);
  if (seg[idx].Or)
    seg[idx].val = seg[idx << 1].val ^ seg[(idx << 1) + 1].val;
  else
    seg[idx].val = seg[idx << 1].val | seg[(idx << 1) + 1].val;
}
int main() {
  scanf("%d%d", &n, &m);
  n <<= 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  build(1, n, 1);
  for (int i = 0; i < m; ++i) {
    int p, b;
    scanf("%d%d", &p, &b);
    update(1, n, 1, p, b);
    printf("%d\n", seg[1].val);
  }
  return 0;
}
