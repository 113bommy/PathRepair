#include <bits/stdc++.h>
using namespace std;
struct lx {
  lx() {}
  lx(int x, int y, long long r) {
    posl = x;
    posr = y;
    val = r;
  }
  int posl, posr;
  long long val;
} tree[300005 * 4];
long long h[300005 * 2], sum[300005 * 2];
long long getdis(int x, int y) {
  if (x > y) swap(x, y);
  return sum[y - 1] - sum[x - 1];
}
void pushup(int l, int r, int id) {
  long long tmp = 2 * h[tree[id * 2].posr] + getdis(r, tree[id * 2].posr);
  if (tmp > 2 * h[tree[id * 2 + 1].posr] + getdis(r, tree[id * 2 + 1].posr)) {
    tree[id].posr = tree[id * 2].posr;
  } else {
    tree[id].posr = tree[id * 2 + 1].posr;
  }
  tmp = 2 * h[tree[id * 2].posl] + getdis(tree[id * 2].posl, l);
  if (tmp > 2 * h[tree[id * 2 + 1].posl] + getdis(tree[id * 2 + 1].posl, l)) {
    tree[id].posl = tree[id * 2].posl;
  } else {
    tree[id].posl = tree[id * 2 + 1].posl;
  }
  tree[id].val = max(tree[id * 2].val, tree[id * 2 + 1].val);
  tmp = 2 * (h[tree[2 * id].posr] + h[tree[2 * id + 1].posl]) +
        getdis(tree[2 * id].posr, tree[2 * id + 1].posl);
  tree[id].val = max(tree[id].val, tmp);
}
void build(int l, int r, int id) {
  if (l == r) {
    tree[id] = lx(l, r, 2 * h[l]);
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, 2 * id);
  build(mid + 1, r, 2 * id + 1);
  pushup(l, r, id);
}
long long ans, idx;
void query(int l, int r, int L, int R, int id) {
  if (L <= l && r <= R) {
    ans = max(ans, tree[id].val);
    if (idx != -1) {
      ans = max(ans,
                2 * (h[idx] + h[tree[id].posl]) + getdis(tree[id].posl, idx));
      long long tmp = 2 * h[idx] + getdis(r, idx);
      if (tmp < 2 * h[tree[id].posr] + getdis(tree[id].posr, r)) {
        idx = tree[id].posr;
      }
    } else {
      idx = tree[id].posr;
    }
    return;
  }
  int mid = (l + r) / 2;
  if (L <= mid) query(l, mid, L, R, id * 2);
  if (R > mid) query(mid + 1, r, L, R, id * 2 + 1);
}
int main() {
  int n, m, l, r;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &sum[i]);
    sum[i + n] = sum[i];
  }
  for (int i = 1; i <= 2 * n; ++i) sum[i] += sum[i - 1];
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &h[i]);
    h[i + n] = h[i];
  }
  build(1, 2 * n, 1);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &l, &r);
    ans = 0;
    idx = -1;
    if (l <= r) {
      query(1, n * 2, r + 1, l + n - 1, 1);
    } else {
      query(1, n * 2, r + 1, l - 1, 1);
    }
    printf("%I64d\n", ans);
  }
}
