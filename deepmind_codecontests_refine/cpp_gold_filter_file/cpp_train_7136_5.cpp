#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
bitset<N> nums;
struct Node {
  int l, r, sum;
  bitset<N> a;
} tr[N * N * 2];
int root[N * N];
int ppp;
int n, m, q, idx, now;
int insert(int p, int l, int r, int op, int x, int y) {
  int q = ++idx;
  tr[q] = tr[p];
  if (l == r) {
    if (op == 1) {
      tr[q].a.set(y);
    } else if (op == 0) {
      tr[q].a.reset(y);
    } else {
      for (int i = 1; i <= m; i++) tr[q].a[i].flip();
    }
    tr[q].sum = tr[q].a.count();
    return q;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    tr[q].l = insert(tr[p].l, l, mid, op, x, y);
  else
    tr[q].r = insert(tr[p].r, mid + 1, r, op, x, y);
  tr[q].sum = tr[tr[q].l].sum + tr[tr[q].r].sum;
  return q;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) nums.set(i);
  while (q--) {
    int op, x, y;
    now++;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%d", &y);
      root[now] = insert(root[now - 1], 1, n, 1, x, y);
    } else if (op == 2) {
      scanf("%d", &y);
      root[now] = insert(root[now - 1], 1, n, 0, x, y);
    } else if (op == 3) {
      root[now] = insert(root[now - 1], 1, n, -1, x, y);
    } else {
      root[now] = root[x];
    }
    printf("%d\n", tr[root[now]].sum);
  }
  return 0;
}
