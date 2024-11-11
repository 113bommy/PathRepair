#include <bits/stdc++.h>
struct aa {
  int x, num;
} a[300000];
int n, k, b[300000], cnt, ansnum[300000];
bool cmp(aa a, aa b) { return a.num > b.num; }
bool solve(int x) {
  int sum = 0;
  for (int i = 1; i <= cnt; i++) {
    sum += a[i].num / x;
    if (a[i].num < x) break;
  }
  return sum >= k;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  std::sort(b + 1, b + n + 1);
  b[0] = -100000;
  for (int i = 1; i <= n; i++) {
    if (b[i] != b[i - 1]) {
      ++cnt;
      a[cnt].x = b[i];
      a[cnt].num = 1;
    } else
      ++a[cnt].num;
  }
  std::sort(a + 1, a + 1 + cnt, cmp);
  int l = 1;
  int r = n;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (solve(mid)) {
      ans = mid;
      ansnum[0] = 0;
      for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= a[i].num / ans; j++) ansnum[++ansnum[0]] = a[i].x;
      }
      l = mid + 1;
    } else
      r = mid - 1;
  }
  for (int i = 1; i <= k; i++) printf("%d ", ansnum[i]);
  return 0;
}
