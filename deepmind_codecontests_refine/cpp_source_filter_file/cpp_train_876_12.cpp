#include <bits/stdc++.h>
using namespace std;
int n, m, l, G, tot, f[200010], a[200010], b[200010], num[200010];
inline void Init() {
  scanf("%d%d%d", &n, &m, &l);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) scanf("%d", b + i);
}
int main() {
  Init();
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  for (int i = tot = 1; i <= n; i++) {
    if (i > 1)
      num[i] = a[i] == a[i - 1] + 1 ? num[i - 1] : i;
    else
      num[1] = 1;
    while (tot <= m && b[tot] <= a[i]) ++tot;
    G = f[num[i] - 1];
    for (int j = tot - 1; j > 0 && a[i] - b[j] < i; j--)
      G = max(G, f[num[i + b[j] - a[i]] - 1] + tot - j);
    f[i] = max(G, max(f[i], f[i - 1]));
    for (int j = tot; j <= m && i + b[j] - a[i] <= n; j++)
      f[i + b[j] - a[i]] = max(f[i + b[j] - a[i]], G + j - tot + 1);
  }
  printf("%d", f[n]);
}
