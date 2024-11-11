#include <bits/stdc++.h>
using namespace std;
int n, a[100005], tot, rt[100005];
struct node {
  int l, r, x;
} f[100005 * 20];
vector<int> v[100005];
void ch(int &x, int y, int l, int r, int pos, int val) {
  x = ++tot;
  if (l == r) {
    f[x].x = val;
    return;
  }
  f[x] = f[y];
  int mid = l + r >> 1;
  if (pos <= mid)
    ch(f[x].l, f[y].l, l, mid, pos, val);
  else
    ch(f[x].r, f[y].r, mid + 1, r, pos, val);
  f[x].x = min(f[f[x].l].x, f[f[x].r].x);
}
int query(int x, int l, int r, int val) {
  if (l == r) return l;
  int mid = l + r >> 1;
  if (f[f[x].l].x <= val)
    return query(f[x].l, l, mid, val);
  else
    return query(f[x].r, mid + 1, r, val);
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
    ch(rt[i], rt[i - 1], 1, n + 1, a[i], i);
  }
  for (int i = 1; i <= n + 1; i++) v[i].push_back(n + 1);
  for (int i = 1; i <= n + 1; i++) {
    int ls = 0, fl = 0;
    for (int j = 0; j < v[i].size(); j++) {
      int h = v[i][j];
      if (h == 1) {
        ls = 1;
        continue;
      }
      if (j && v[i][j - 1] + 1 == v[i][j]) continue;
      if (query(rt[h - 1], 1, n + 1, ls) == i) {
        fl = 1;
        break;
      }
      ls = h;
    }
    if (!fl) printf("%d\n", i), exit(0);
  }
  printf("%d", n + 2);
}
