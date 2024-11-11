#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int lazy[4 * N], tree[4 * N];
int arr[N];
int m, ind, type, val;
void upd(int id, int lo, int hi, int l, int r, int val) {
  if (l > hi or r < lo) return;
  if (l <= lo and r >= hi) {
    lazy[id] += val;
    return;
  }
  int mid = (lo + hi) >> 1;
  upd(2 * id, lo, mid, l, r, val);
  upd(2 * id + 1, mid + 1, hi, l, r, val);
  tree[id] =
      max(tree[2 * id] + lazy[2 * id], tree[2 * id + 1] + lazy[2 * id + 1]);
}
int query(int id, int lo, int hi, int have) {
  if (lo == hi and have + lazy[id] + tree[id])
    return lo;
  else if (lo == hi)
    return -1;
  int mid = (lo + hi) >> 1;
  if (have + lazy[id] + tree[2 * id + 1] + lazy[2 * id + 1] > 0)
    return query(2 * id + 1, mid + 1, hi, have + lazy[id]);
  if (have + lazy[id] + tree[2 * id] + lazy[2 * id] > 0)
    return query(2 * id, lo, mid, have + lazy[id]);
  return -1;
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &ind, &type);
    if (type == 0) {
      upd(1, 1, m, 1, ind, -1);
    } else {
      scanf("%d", &val);
      arr[ind] = val;
      upd(1, 1, m, 1, ind, 1);
    }
    int ans = query(1, 1, m, 0);
    if (ans == -1)
      printf("%d\n", ans);
    else
      printf("%d\n", arr[ans]);
  }
}
