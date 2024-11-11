#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050, maxm = 2050;
int n, m, a[maxn], b[maxm], ans;
int pre[maxn], nxt[maxn];
int f[maxn][2] = {0};
int main() {
  int i, j, cur;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (i = 1; i <= n; i++)
    pre[i] = (i > 1 && a[i] == a[i - 1] + 1 ? pre[i - 1] : i - 1);
  for (i = n; i; i--) nxt[i] = (i < n && a[i] == a[i + 1] - 1 ? nxt[i + 1] : i);
  for (i = cur = 1; i <= n; i++) {
    while (cur <= m && b[cur] <= a[i]) cur++;
    f[i][1] = f[i - 1][0];
    for (j = cur - 1; j && i - (a[i] - b[j]) > 0; j--) {
      int i0 = pre[i - (a[i] - b[j])];
      f[i][1] = max(f[i][1], f[i0][0] + cur - j);
    }
    for (j = cur; j <= m && i + (b[j] - a[i]) <= n; j++) {
      int i0 = nxt[i + (b[j] - a[i])];
      f[i0][0] = max(f[i0][0], f[i][1] + j - cur + 1);
    }
    ans = max(ans, f[i][0] = max(f[i][0], f[i][1]));
  }
  printf("%d\n", ans);
  return 0;
}
