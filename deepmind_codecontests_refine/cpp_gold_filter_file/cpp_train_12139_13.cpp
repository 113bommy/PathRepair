#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
vector<int> v[MAXN];
int root[MAXN], ls[MAXN * 50], rs[MAXN * 50], add[MAXN * 50], tot;
void build(int l, int r, int &rt) {
  rt = ++tot;
  add[rt] = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  build(l, mid, ls[rt]);
  build(mid + 1, r, rs[rt]);
}
void insert(int l, int r, int x, int y, int &r1, int r2) {
  r1 = ++tot;
  add[r1] = add[r2];
  ls[r1] = ls[r2];
  rs[r1] = rs[r2];
  if (l == x && r == y) {
    add[r1]++;
    return;
  }
  int mid = l + r >> 1;
  if (mid >= y)
    insert(l, mid, x, y, ls[r1], ls[r2]);
  else if (mid < x)
    insert(mid + 1, r, x, y, rs[r1], rs[r2]);
  else
    insert(l, mid, x, mid, ls[r1], ls[r2]),
        insert(mid + 1, r, mid + 1, y, rs[r1], rs[r2]);
}
int query(int l, int r, int x, int rt) {
  if (l == r) return add[rt];
  int mid = l + r >> 1;
  if (x <= mid)
    return add[rt] + query(l, mid, x, ls[rt]);
  else
    return add[rt] + query(mid + 1, r, x, rs[rt]);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  build(1, n, root[0]);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (v[x].size() >= k)
      insert(1, n, v[x][v[x].size() - k] + 1, i, root[i], root[i - 1]);
    else
      insert(1, n, 1, i, root[i], root[i - 1]);
    v[x].push_back(i);
  }
  int lst = 0, m;
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = (l + lst) % n + 1;
    r = (r + lst) % n + 1;
    if (l > r) swap(l, r);
    lst = query(1, n, l, root[r]);
    printf("%d\n", lst);
  }
  return 0;
}
