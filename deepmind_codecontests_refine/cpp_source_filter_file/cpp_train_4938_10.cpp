#include <bits/stdc++.h>
int n, m, ans, tot, cnt, sum[10005], tmp, maxi, maxj;
std::pair<int, int> a[10005], b[10005];
inline bool cmp(std::pair<int, int>& x, std::pair<int, int>& y) {
  return x.first > y.first;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, op; i <= n; i++) {
    scanf("%d%d", &op, &x);
    if (--op)
      a[++tot] = std::make_pair(x, i);
    else
      b[++cnt] = std::make_pair(x, i);
  }
  std::sort(a + 1, a + tot + 1, cmp);
  std::sort(b + 1, b + cnt + 1, cmp);
  for (int i = 1; i <= tot; i++) sum[i] = sum[i - 1] + a[i].first;
  for (register int i = 0; i <= m && i <= cnt; i++) {
    int j = std::min(m - i >> 1, cnt);
    tmp += b[i].first;
    if (tmp + sum[j] > ans) {
      ans = tmp + sum[j];
      maxi = i;
      maxj = j;
    }
  }
  printf("%d\n", ans);
  for (register int i = 1; i <= maxi; i++) printf("%d ", b[i].second);
  for (register int i = 1; i <= maxj; i++) printf("%d ", a[i].second);
  return 0;
}
