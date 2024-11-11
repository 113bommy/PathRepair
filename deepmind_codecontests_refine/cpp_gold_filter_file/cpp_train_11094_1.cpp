#include <bits/stdc++.h>
using namespace std;
int n, l[300005 * 4], r[300005 * 4], b[300005 * 4], d[300005];
long long a[300005];
int sign(long long x) {
  if (x > 0) return 1;
  return -1;
}
void update(int pos, int L, int R, int seg, int val) {
  if (L == 2 && R == 1) return;
  if (L == 6 && R == 5) return;
  if (L == R) {
    a[pos] += val;
    if (a[pos])
      l[seg] = 1, r[seg] = 1, b[seg] = 1;
    else
      l[seg] = 0, r[seg] = 0, b[seg] = 0;
    return;
  }
  int mid = (L + R) / 2;
  if (pos <= mid)
    update(pos, L, mid, 2 * seg, val);
  else
    update(pos, mid + 1, R, 2 * seg + 1, val);
  b[seg] = max(b[seg * 2], b[seg * 2 + 1]);
  l[seg] = l[seg * 2];
  r[seg] = r[seg * 2 + 1];
  if (sign(a[mid]) >= sign(a[mid + 1])) {
    b[seg] = max(r[seg * 2] + l[seg * 2 + 1], b[seg]);
    if (l[seg * 2] == mid - L + 1) l[seg] = b[seg * 2] + l[seg * 2 + 1];
    if (r[seg * 2 + 1] == R - mid) r[seg] = b[seg * 2 + 1] + r[seg * 2];
  }
}
int main() {
  int i, j, L, R, e, q;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", d + i);
  for (i = 1; i < n; i++) d[i] = d[i + 1] - d[i];
  for (i = 1; i < n; i++) update(i, 1, n - 1, 1, d[i]);
  for (scanf("%d", &q); q--;) {
    scanf("%d %d %d", &L, &R, &e);
    if (L > 1) update(L - 1, 1, n - 1, 1, e);
    if (R < n) update(R, 1, n - 1, 1, -e);
    printf("%d\n", b[1] + 1);
  }
}
