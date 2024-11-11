#include <bits/stdc++.h>
using namespace std;
const int N = 300010, inf = 1000000000;
int n, m;
int a[N];
int s[N << 2], ans[N];
vector<int> d[N << 2];
void build(int l, int r, int k) {
  for (int i = l; i <= r; i++) d[k].push_back(a[i]);
  s[k] = inf;
  sort(d[k].begin(), d[k].end());
  if (l == r) return;
  int mid = l + r >> 1;
  build(l, mid, k << 1);
  build(mid + 1, r, k << 1 | 1);
}
struct qu {
  int l, r, id;
  bool operator<(const qu a) const { return r < a.r; }
} q[N];
int mi;
void modify(int l, int r, int p, int x, int k) {
  if (r <= p) {
    vector<int>::iterator it = upper_bound(d[k].begin(), d[k].end(), x);
    if (it != d[k].end()) s[k] = min(s[k], *it - x);
    if (it != d[k].begin()) s[k] = min(s[k], x - *(it - 1));
    if (mi <= s[k]) return;
    if (l == r) {
      mi = min(mi, s[k]);
      return;
    }
  }
  int mid = l + r >> 1;
  if (p > mid) modify(mid + 1, r, p, x, k << 1 | 1);
  modify(l, mid, p, x, k << 1);
  s[k] = min(s[k], min(s[k << 1], s[k << 1 | 1]));
  mi = min(mi, s[k]);
}
int query(int L, int R, int l, int r, int k) {
  if (l <= L && R <= r) return s[k];
  int mid = L + R >> 1, res = inf;
  if (l <= mid) res = query(L, mid, l, r, k << 1);
  if (r > mid) res = min(query(mid + 1, R, l, r, k << 1 | 1), res);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, n, 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
  sort(q + 1, q + m + 1);
  for (int i = 2, j = 1; i <= n; i++) {
    mi = inf;
    modify(1, n, i - 1, a[i], 1);
    while (j <= m && q[j].r <= i)
      ans[q[j].id] = query(1, n, q[j].l, q[j].r, 1), j++;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
