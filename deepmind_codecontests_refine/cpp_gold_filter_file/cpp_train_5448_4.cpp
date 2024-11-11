#include <bits/stdc++.h>
const int maxn = 1000003;
int a[maxn * 2];
int b[maxn];
int c[maxn];
int d[maxn * 2];
int bin(int l, int r, int aim) {
  int mid, best = l - 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (c[a[mid]] < aim) {
      best = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return best;
}
int main() {
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i + n] = a[i];
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    c[b[i]] = i;
  }
  d[2 * n] = c[a[2 * n]] != 0;
  for (i = 2 * n - 1; i >= 1; i--) {
    if (c[a[i]] == 0) continue;
    if (c[a[i + 1]] == 0 || c[a[i]] >= c[a[i + 1]])
      d[i] = 1;
    else
      d[i] = d[i + 1] + 1;
  }
  int ans = 0;
  for (i = 1; i <= n; i++)
    if (d[i]) {
      j = i + d[i];
      int t = d[i] + bin(j, j + d[j] - 1, c[a[i]]) - j + 1;
      ans = ans > t ? ans : t;
    }
  printf("%d\n", ans);
  return 0;
}
