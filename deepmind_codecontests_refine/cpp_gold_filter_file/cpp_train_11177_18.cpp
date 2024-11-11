#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
long long ans;
int a[1005][1005], T[1005 * 1005], cnt[1005 * 1005 << 2], sum[1005 * 1005 << 2];
int ql, qr, tmp, n, i, j, x, y, t1, t2, t3, t4;
void Update(int k, int l, int r, int v) {
  if (ql <= l && r <= qr) {
    cnt[k] = max(cnt[k], v);
    sum[k] = max(sum[k], cnt[k]);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) Update(k << 1, l, mid, v);
  if (qr > mid) Update(k << 1 | 1, mid + 1, r, v);
  sum[k] = max(cnt[k], min(sum[k << 1], sum[k << 1 | 1]));
}
int Query(int k, int l, int r) {
  if (ql <= l && r <= qr) return sum[k];
  int mid = (l + r) >> 1, res = INF;
  if (ql <= mid) res = min(res, Query(k << 1, l, mid));
  if (qr > mid) res = min(res, Query(k << 1 | 1, mid + 1, r));
  return max(res, cnt[k]);
}
int cross(int x2, int y2) { return x * y2 - x2 * y; }
int find(int x) { return lower_bound(T + 1, T + *T + 1, x) - T; }
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= n - 1; j++) scanf("%d", &a[i][j]);
  if (y < 0)
    for (i = 0; i <= n - 1; i++)
      for (j = 0; j <= n - 1; j++)
        if (j < n / 2) swap(a[i][j], a[i][n - 1 - j]);
  if (x < 0)
    for (i = 0; i <= n - 1; i++)
      for (j = 0; j <= n - 1; j++)
        if (i < n / 2) swap(a[i][j], a[n - 1 - i][j]);
  x = abs(x);
  y = abs(y);
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) T[++*T] = cross(i, j);
  sort(T + 1, T + *T + 1);
  *T = unique(T + 1, T + *T + 1) - (T + 1);
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= n - 1; j++) {
      ql = find(cross(i + 1, j));
      qr = find(cross(i, j + 1)) - 1;
      if (ql <= qr) tmp = Query(1, 1, *T);
      if (tmp <= a[i][j]) ans += a[i][j] - tmp;
      Update(1, 1, *T, a[i][j]);
    }
  printf("%I64d\n", ans);
}
