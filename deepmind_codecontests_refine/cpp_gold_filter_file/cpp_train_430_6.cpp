#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int tree[maxn << 2], lazy[maxn << 2], n, m;
int a[maxn], b[maxn];
inline void push_down(int pos) {
  if (lazy[pos]) {
    lazy[pos << 1] += lazy[pos];
    lazy[pos << 1 | 1] += lazy[pos];
    tree[pos << 1] += lazy[pos];
    tree[pos << 1 | 1] += lazy[pos];
    lazy[pos] = 0;
  }
}
inline void push_up(int pos) {
  tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
}
void updata(int L, int R, int l, int r, int pos, int v) {
  if (L >= l && R <= r) {
    lazy[pos] += v;
    tree[pos] += v;
    return;
  }
  push_down(pos);
  int mid = (L + R) >> 1;
  if (l <= mid) updata(L, mid, l, r, pos << 1, v);
  if (r > mid) updata(mid + 1, R, l, r, pos << 1 | 1, v);
  push_up(pos);
}
int query(int L, int R, int pos) {
  if (L == R) return R;
  push_down(pos);
  int mid = (L + R) >> 1;
  if (tree[pos << 1 | 1] > 0) return query(mid + 1, R, pos << 1 | 1);
  return query(L, mid, pos << 1);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), updata(1, maxn, 1, a[i], 1, 1);
  for (int i = 1; i <= m; i++)
    scanf("%d", &b[i]), updata(1, maxn, 1, b[i], 1, -1);
  int q;
  scanf("%d", &q);
  int op, id, v;
  while (q--) {
    scanf("%d%d%d", &op, &id, &v);
    if (op == 1) {
      updata(1, maxn, 1, a[id], 1, -1);
      updata(1, maxn, 1, v, 1, 1);
      a[id] = v;
    } else {
      updata(1, maxn, 1, b[id], 1, 1);
      updata(1, maxn, 1, v, 1, -1);
      b[id] = v;
    }
    if (tree[1] > 0)
      printf("%d\n", query(1, maxn, 1));
    else
      printf("-1\n");
  }
  return 0;
}
