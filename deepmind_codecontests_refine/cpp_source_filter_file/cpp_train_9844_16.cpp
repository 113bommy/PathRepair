#include <bits/stdc++.h>
using namespace std;
int n, a[3030], b[3030];
long long f[3030][3030], g[3030][3030];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i] - i;
  sort(b + 1, b + n + 1);
  *b = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(b + 1, b + *b + 1, a[i] - i) - b;
  memset(g, 60, sizeof g);
  memset(g[0], 0, sizeof g[0]);
  memset(f, 60, sizeof f);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= *b; j++) {
      f[i][j] = g[i - 1][j] + abs(b[j] - b[a[i]]);
      g[i][j] = min(f[i][j], g[i][j - 1]);
    }
  }
  long long ans = 1e9;
  for (int i = 1; i <= *b; i++) ans = min(ans, f[n][i]);
  printf("%lld\n", ans);
}
