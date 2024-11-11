#include <bits/stdc++.h>
int a[100010], s[100010], n;
int find(int idx, int limit) {
  int l = idx, r = n, m, sum, ans = 0;
  if (a[idx] > limit) return 0;
  if (s[r] - s[l - 1] <= limit) return r - l + 1;
  l = idx, r = n;
  while (l < r) {
    m = (l + r) >> 1;
    sum = s[m] - s[idx - 1];
    if (sum > limit)
      r = m;
    else
      l = m + 1;
  }
  return l - idx;
}
int main() {
  int m, i, ans, buff;
  while (~scanf("%d%d", &n, &m)) {
    s[0] = 0;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = a[i] + s[i - 1];
    ans = 0;
    for (i = 1; i <= n; i++)
      if ((buff = find(i, m)) > ans) ans = buff;
    printf("%d\n", ans);
  }
  return 0;
}
