#include <bits/stdc++.h>
using namespace std;
int n, m, x, a[200005];
int b[200005];
int t[200005];
int f[200005], g[200005];
int l[200005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    t[b[i]]++;
  }
  for (int i = 1; i < 200005; i++) t[i] += t[i - 1];
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    l[i] = (a[i - 1] == a[i] - 1 ? l[i - 1] : i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    g[i] = max(g[i - 1], g[i]);
    for (int j = 1; j <= m; j++) {
      if (b[j] > a[i]) continue;
      int tmp = a[i] - b[j];
      if (i - tmp >= 1)
        f[i] = max(f[i], g[l[i - tmp] - 1] + t[a[i]] - t[b[j] - 1]);
    }
    g[i] = max(g[i], f[i]);
    f[i] = max(f[i], g[l[i] - 1] + t[a[i]] - t[a[l[i]] - 1]);
    for (int j = 1; j <= m; j++) {
      if (b[j] < a[i]) continue;
      int tmp = b[j] - a[i];
      if (i + tmp <= n) g[i + tmp] = max(g[i + tmp], f[i] + t[b[j]] - t[a[i]]);
    }
    ans = max(ans, f[i]);
    ans = max(ans, g[i]);
  }
  printf("%d", ans);
  return 0;
}
