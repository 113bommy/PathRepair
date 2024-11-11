#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], pos[maxn], pre[maxn], nex[maxn];
int ans[maxn];
struct node {
  int l, r, ma;
  int lazy;
} tree[maxn << 2];
inline void pushdown(int x) {
  if (tree[x].lazy) {
    tree[x << 1].ma = 0;
    tree[x << 1].lazy = 1;
    tree[x << 1 | 1].ma = 0;
    tree[x << 1 | 1].lazy = 1;
    tree[x].lazy = 0;
  }
}
inline void pushup(int x) {
  tree[x].ma = max(tree[x << 1].ma, tree[x << 1 | 1].ma);
}
void build(int x, int l, int r) {
  tree[x].l = l;
  tree[x].r = r;
  tree[x].lazy = 0;
  if (l == r) {
    tree[x].ma = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
}
void update(int x, int l, int r) {
  if (l <= tree[x].l && tree[x].r <= r) {
    tree[x].ma = 0;
    tree[x].lazy = 1;
    return;
  }
  pushdown(x);
  int mid = (tree[x].l + tree[x].r) >> 1;
  if (l <= mid) update(x << 1, l, r);
  if (r > mid) update(x << 1 | 1, l, r);
  pushup(x);
}
int query(int x, int l, int r) {
  if (l <= tree[x].l && tree[x].r <= r) return tree[x].ma;
  pushdown(x);
  int mid = (tree[x].l + tree[x].r) >> 1;
  int res = 0;
  if (l <= mid) res = max(res, query(x << 1, l, r));
  if (r > mid) res = max(res, query(x << 1 | 1, l, r));
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
    pre[i] = i - 1;
    nex[i] = i + 1;
  }
  build(1, 1, n);
  int flag = 0;
  while (1) {
    int ma = query(1, 1, n);
    if (ma == 0) break;
    int l = pos[ma], r = pos[ma];
    ans[l] = flag;
    for (int i = 1; i <= k; i++) {
      if (pre[l] != 0) {
        l = pre[l];
        ans[l] = flag;
      } else
        break;
    }
    for (int i = 1; i <= k; i++) {
      if (nex[r] != n + 1) {
        r = nex[r];
        ans[r] = flag;
      } else
        break;
    }
    update(1, l, r);
    pre[nex[r]] = pre[l];
    nex[pre[l]] = nex[r];
    flag ^= 1;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] + 1;
  cout << '\n';
}
