#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010], b[200010], s[200010 * 2], l[200010], r[200010],
    f[200010 * 2], g[200010 * 2];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    s[b[i]]++;
  }
  for (int i = 1; i < 200010; i++) s[i] += s[i - 1];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  a[0] = a[n + 1] = 1e9;
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1] + 1)
      l[i] = i;
    else
      l[i] = l[i - 1];
  }
  for (int i = n; i; i--) {
    if (a[i] != a[i + 1] - 1)
      r[i] = i;
    else
      r[i] = r[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    f[i] = max(f[i], f[i - 1] + s[a[i]] - s[a[i] - 1]);
    g[i] = max(g[i], g[i - 1] + s[a[i]] - s[a[i] - 1]);
    for (int j = 1; j <= m && b[j] <= a[i]; j++)
      if (a[i] - b[j] < i)
        g[i] = max(g[i], f[l[i - a[i] + b[j]] - 1] + s[a[i]] - s[b[j] - 1]);
    f[i] = max(f[i], g[i]);
    for (int j = m; j && b[j] >= a[i]; j--)
      if (b[j] - a[i] <= n - i)
        f[r[i + b[j] - a[i]]] =
            max(f[r[i + b[j] - a[i]]], g[i] + s[b[j]] - s[a[i]]);
  }
  cout << f[n];
}
