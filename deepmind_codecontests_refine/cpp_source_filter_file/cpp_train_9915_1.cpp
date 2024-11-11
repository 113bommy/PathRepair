#include <bits/stdc++.h>
int _, n, m, ans1, ans2, a[200005], sum[200005];
bool vis[200005];
int main() {
  int i;
  for (scanf("%d", &_); _; _--) {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) {
      vis[i] = bool(a[i] > a[i - 1] && a[i] > a[i + 1]);
      sum[i] = sum[i - 1] + vis[i];
    }
    ans1 = ans2 = 0;
    for (i = m; i <= n; i++)
      if (sum[i] - sum[i - m] - vis[i - m + 1] - vis[i] > ans1)
        ans1 = sum[i] - sum[i - m] - vis[i - m + 1] - vis[i], ans2 = i - m + 1;
    printf("%d %d\n", ans1 + 1, ans2);
  }
  return 0;
}
