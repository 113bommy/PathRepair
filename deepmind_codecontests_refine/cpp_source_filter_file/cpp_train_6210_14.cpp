#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
using namespace std;
int n, l[maxn], r[maxn], sum[maxn], m, a[maxn];
int f[maxn], ans, g[maxn];
int mx[maxn << 2];
void modify(int x, int v) {
  for (; x <= m; x += x & (-x)) sum[x] += v;
}
int query(int x) {
  int ans = 0;
  for (; x; x -= x & (-x)) ans += sum[x];
  return ans;
}
void Modify(int p, int l, int r, int x, int v) {
  if (l == r) {
    mx[p] = max(mx[p], v);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    Modify(p << 1, l, mid, x, v);
  else
    Modify(p << 1 | 1, mid + 1, r, x, v);
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}
int Query(int p, int l, int r, int sl, int sr) {
  if (sl <= l && r <= sr) return mx[p];
  int mid = (l + r) >> 1, res = 0;
  if (sl <= mid) res = Query(p << 1, l, mid, sl, sr);
  if (mid < sr) res = max(res, Query(p << 1 | 1, mid + 1, r, sl, sr));
  return res;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &l[i], &r[i]), modify(l[i], 1), modify(r[i] + 1, -1);
  for (int i = 1; i <= m; i++) a[i] = query(i);
  Modify(1, 0, m, a[1], 1);
  f[1] = 1;
  for (int i = 2; i <= m; i++) {
    f[i] = Query(1, 0, m, 0, a[i]) + 1;
    Modify(1, 0, m, a[i], f[i]);
  }
  memset(mx, 0, sizeof(mx));
  Modify(1, 0, m, a[m], 1);
  g[m] = 1;
  for (int i = m - 1; i >= 1; i--) {
    g[i] = Query(1, 0, m, 0, a[i]) + 1;
    Modify(1, 0, m, a[i], g[i]);
  }
  for (int i = 1; i <= m; i++) ans = max(ans, f[i] + g[i] - 1);
  printf("%d\n", ans);
  return 0;
}
