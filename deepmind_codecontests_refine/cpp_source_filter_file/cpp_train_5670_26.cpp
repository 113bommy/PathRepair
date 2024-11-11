#include <bits/stdc++.h>
const int maxlongint = 2147483647;
const int N = 102001;
int n, m, w1, w2, cdq;
struct Tree {
  int lv, rv, v;
  int lazy;
} tree[(N + 3) << 2 | 1];
int ql[N], qr[N], used[N];
using namespace std;
void build(int k, int L, int R) {
  tree[k].lv = tree[k].rv = tree[k].v = R - L + 1;
  tree[k].lazy = -1;
  if (L != R) {
    int mid = (L + R) >> 1;
    build(k << 1, L, mid);
    build(k << 1 | 1, mid + 1, R);
  }
}
inline void Change(int k, const int& flag, int L, int R) {
  tree[k].lv = tree[k].rv = tree[k].v = flag * (R - L + 1);
  tree[k].lazy = flag;
}
inline void merge(int k, int L, int R) {
  int mid = (L + R) >> 1;
  tree[k].lv = tree[k << 1].lv;
  tree[k].rv = tree[k << 1 | 1].rv;
  if (tree[k << 1].lv == mid - L + 1)
    tree[k].lv = tree[k << 1].lv + tree[k << 1 | 1].lv;
  if (tree[k << 1 | 1].lv == R - mid)
    tree[k].rv = tree[k << 1].rv + tree[k << 1 | 1].rv;
  tree[k].v = max(max(tree[k << 1].v, tree[k << 1 | 1].v),
                  tree[k << 1].rv + tree[k << 1 | 1].lv);
}
void change(int k, int l, int r, const int& flag, int L, int R) {
  if (L == l && R == r) {
    Change(k, flag, L, R);
    return;
  } else {
    int mid = (L + R) >> 1;
    if (tree[k].lazy >= 0)
      Change(k << 1, tree[k].lazy, L, mid),
          Change(k << 1 | 1, tree[k].lazy, mid + 1, R), tree[k].lazy = -1;
    if (r <= mid)
      change(k << 1, l, r, flag, L, mid);
    else if (l > mid)
      change(k << 1 | 1, l, r, flag, mid + 1, R);
    else
      change(k << 1, l, mid, flag, L, mid),
          change(k << 1 | 1, mid + 1, r, flag, mid + 1, R);
    merge(k, L, R);
  }
}
int quest(int k, int len, int L, int R) {
  if (L == R) return L;
  int mid = (L + R) >> 1;
  if (tree[k].lazy >= 0)
    Change(k << 1, tree[k].lazy, L, mid),
        Change(k << 1 | 1, tree[k].lazy, mid + 1, R), tree[k].lazy = -1;
  if (tree[k << 1].v >= len) return quest(k << 1, len, L, mid);
  if (tree[k << 1].rv && tree[k << 1].rv + tree[k << 1 | 1].lv >= len)
    return mid - tree[k << 1].rv + 1;
  if (tree[k << 1 | 1].v >= len) return quest(k << 1 | 1, len, mid + 1, R);
  while (1)
    ;
}
void init() {
  scanf("%d%d%d", &n, &w1, &w2);
  n++;
  n += w1 + w2;
  build(1, 1, n);
}
void solve() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int flag, p;
    ++cdq;
    scanf("%d%d", &flag, &p);
    if (flag == 1) {
      if (tree[1].v >= p + w1 + w2) {
        int aaa = quest(1, p + w1 + w2, 1, n);
        change(1, aaa + w1, aaa + w1 + p - 1, 0, 1, n);
        ql[cdq] = aaa + w1;
        qr[cdq] = aaa + w1 + p - 1;
        used[i] = 1;
        printf("%d\n", aaa - 1);
      } else
        printf("-1\n");
    }
    if (flag == 2) {
      if (p <= cdq && used[p]) change(1, ql[p], qr[p], 1, 1, n), used[p] = 0;
    }
  }
}
int main() {
  init();
  solve();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
