#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, len, a[N], b[N], sum[N], l[N], r[N], f[N], g[N], x;
int main() {
  scanf("%d%d", &n, &m);
  len = 200000;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]), sum[b[i]]++;
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) l[i] = (a[i] == a[i - 1] + 1) ? l[i - 1] : i;
  for (int i = n; i >= 1; i--) r[i] = (a[i] == a[i + 1] - 1) ? r[i + 1] : i;
  for (int i = 1; i <= len; i++) sum[i] += sum[i - 1];
  for (int i = 1; i <= n; i++) {
    g[i] = max(g[i], max(g[i - 1], f[i - 1]) + sum[a[i]] - sum[a[i] - 1]);
    f[i] = max(f[i], max(g[i - 1], f[i - 1]) + sum[a[i]] - sum[a[i] - 1]);
    for (int j = 1; j <= m && b[j] <= a[i]; j++) {
      x = i - (a[i] - b[j]) - 1;
      if (x < 0) continue;
      g[i] = max(g[i], f[l[x + 1] - 1] + sum[a[i]] - sum[b[j] - 1]);
      f[i] = max(f[i], g[i]);
    }
    for (int j = m; j >= 1 && b[j] >= a[i]; j--) {
      x = i + (b[j] - a[i]) + 1;
      if (x > n + 1) continue;
      f[r[x - 1]] = max(f[r[x - 1]], g[i] + sum[b[j]] - sum[a[i]]);
    }
  }
  printf("%d\n", f[n]);
  return 0;
}
