#include <bits/stdc++.h>
const int maxn = 2e5 + 100;
const int NUM = 30;
int n, q;
int a[maxn], c[maxn];
int pow_2[NUM];
struct node {
  int c[NUM];
  int l, r, val;
  void init() { memset(c, 0, sizeof(c)); }
  void ins(int x) {
    if (!x) return;
    for (int i = NUM - 1; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (c[i])
          x ^= c[i];
        else {
          c[i] = x;
          return;
        }
      }
    }
  }
} SegmentTree[maxn << 2];
int lowbit(int x) { return x & (-x); }
int Query(int id) {
  int ans = 0;
  while (id) {
    ans ^= c[id];
    id -= lowbit(id);
  }
  return ans;
}
void Update(int id, int x) {
  while (id <= n) {
    c[id] ^= x;
    id += lowbit(id);
  }
}
void push_up(int id) {
  for (int i = 0; i < NUM; i++)
    SegmentTree[id].c[i] = SegmentTree[id << 1].c[i];
  for (int i = 0; i < NUM; i++)
    SegmentTree[id].ins(SegmentTree[id << 1 | 1].c[i]);
}
void build(int id, int l, int r) {
  SegmentTree[id].l = l;
  SegmentTree[id].r = r;
  SegmentTree[id].init();
  if (l == r) {
    SegmentTree[id].ins(a[l]);
    SegmentTree[id].val = a[l];
    Update(l, a[l]);
  } else {
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    push_up(id);
  }
}
void update(int id, int pos, int x) {
  int L = SegmentTree[id].l, R = SegmentTree[id].r;
  if (L == R) {
    int val = SegmentTree[id].val;
    SegmentTree[id].init();
    SegmentTree[id].ins(x ^ val);
    SegmentTree[id].val = x ^ val;
    Update(pos, x);
    return;
  }
  int mid = (L + R) >> 1;
  if (pos <= mid)
    update(id << 1, pos, x);
  else
    update(id << 1 | 1, pos, x);
  push_up(id);
}
node query(int id, int l, int r) {
  int L = SegmentTree[id].l, R = SegmentTree[id].r;
  if (l <= L && R <= r) return SegmentTree[id];
  int mid = (L + R) >> 1;
  node ans;
  ans.init();
  if (l <= mid) {
    node res = query(id << 1, l, r);
    for (int i = 0; i < NUM; i++) ans.ins(res.c[i]);
  }
  if (r > mid) {
    node res = query(id << 1 | 1, l, r);
    for (int i = 0; i < NUM; i++) ans.ins(res.c[i]);
  }
  return ans;
}
int main() {
  pow_2[0] = 1;
  for (int i = 1; i < NUM; i++) pow_2[i] = 2 * pow_2[i - 1];
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = n; i >= 1; i--) a[i] ^= a[i - 1];
  build(1, 1, n);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      update(1, l, k);
      if (r != n) update(1, r + 1, k);
    } else {
      int l, r;
      int ans = 0;
      scanf("%d %d", &l, &r);
      node res;
      res.init();
      if (l < r) res = query(1, l + 1, r);
      res.ins(Query(l));
      for (int i = 0; i < NUM; i++) ans += res.c[i] > 0;
      printf("%d\n", pow_2[ans]);
    }
  }
  return 0;
}
