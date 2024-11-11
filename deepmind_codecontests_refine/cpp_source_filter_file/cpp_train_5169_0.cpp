#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], root[100005], ls[4000005], rs[4000005], tree[4000005],
    cnt;
vector<int> to[100005];
long long f[100005];
long long get(int id, int x) { return 1ll * b[id] * x + f[id]; }
void modify(int l, int r, int &x, int a) {
  if (!x) x = ++cnt;
  if (!tree[x]) {
    tree[x] = a;
    return;
  }
  long long c1 = get(a, l), c2 = get(a, r), d1 = get(tree[x], l),
            d2 = get(tree[x], r);
  if (c1 > d1 && c2 > d2) {
    tree[x] = a;
    return;
  }
  if (l == r || (c1 <= d1 && c2 <= d2)) return;
  int mid = (l + r) >> 1;
  long long c3 = get(a, mid), d3 = get(tree[x], mid);
  if (c3 > d3) swap(tree[x], a), swap(c1, d1);
  if (c1 > d1)
    modify(mid + 1, r, rs[x], a);
  else
    modify(l, mid, ls[x], a);
}
int merge(int l, int r, int x, int y) {
  if (!x || !y) return x + y;
  int mid = (l + r) >> 1;
  ls[x] = merge(l, mid, ls[x], ls[y]), rs[x] = merge(mid + 1, r, rs[x], rs[y]);
  if (tree[y]) modify(l, r, x, tree[y]);
  return x;
}
long long query(int l, int r, int x, int a) {
  if (!x) return 1e18;
  if (l == r) return tree[x] ? get(tree[x], a) : 1e18;
  int mid = (l + r) >> 1;
  long long res = tree[x] ? get(tree[x], a) : 1e18;
  if (a <= mid) return min(res, query(l, mid, ls[x], a));
  return min(res, query(mid + 1, r, rs[x], a));
}
void dfs(int x, int fa) {
  f[x] = 1e18;
  for (auto tar : to[x]) {
    if (tar == fa) continue;
    dfs(tar, x);
    f[x] = min(f[x], query(-1e5, 1e5, root[tar], a[x]));
    root[x] = merge(-1e5, 1e5, root[x], root[tar]);
  }
  if (f[x] == 1e18) f[x] = 0;
  modify(-1e5, 1e5, root[x], x);
}
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i < n; i++)
    scanf("%d%d", &x, &y), to[x].push_back(y), to[y].push_back(x);
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%lld ", f[i]);
  return 0;
}
