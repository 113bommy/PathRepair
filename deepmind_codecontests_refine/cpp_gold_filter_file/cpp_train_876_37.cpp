#include <bits/stdc++.h>
using namespace std;
int n, m, sum[200010], f[200010], g[200010], a[100010], b[2010], l[100010],
    r[100010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[0] = -1e9;
  a[n + 1] = 1e9;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]), ++sum[b[i]];
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1] + 1)
      l[i] = l[i - 1];
    else
      l[i] = i;
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] == a[i + 1] - 1)
      r[i] = r[i + 1];
    else
      r[i] = i;
  }
  for (int i = 1; i <= 200000; i++) sum[i] += sum[i - 1];
  for (int i = 1; i <= n; i++) {
    f[i] = max(f[i], f[i - 1] + sum[a[i]] - sum[a[i] - 1]);
    g[i] = max(g[i], f[i - 1] + sum[a[i]] - sum[a[i] - 1]);
    for (int j = 1; j <= m; j++) {
      int len = a[i] - b[j];
      if (len <= 0) break;
      if (len < i)
        g[i] = max(g[i], f[l[i - len] - 1] + sum[a[i]] - sum[b[j] - 1]);
    }
    f[i] = max(f[i], g[i]);
    for (int j = m; j >= 1; j--) {
      int len = b[j] - a[i];
      if (len < 0) break;
      if (len <= n - i)
        f[r[i + len]] = max(f[r[i + len]], g[i] + sum[b[j]] - sum[a[i]]);
    }
  }
  printf("%d\n", f[n]);
  return 0;
}
