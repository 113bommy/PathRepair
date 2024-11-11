#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, a[2005];
int f[2005], g[2005], h[2005], k[2005], w[2005], v[2005][2005], l[2005][2005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    f[i] = f[i - 1] + (a[i] == 1);
    g[i] = g[i - 1] + (a[i] == 2);
    w[i] = g[i] - f[i];
  }
  for (int i = 1; i < n; ++i) {
    v[i][i] = 0;
    for (int j = i + 1; j <= n; ++j) {
      v[i][j] = max(v[i][j - 1], w[j - 1]);
    }
  }
  int ans = max(f[n], g[n]);
  for (int i = 1; i < n; ++i) ans = max(ans, f[i] + g[n] - g[i]);
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      l[i][j] = v[i][j] - g[i - 1] + f[j];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans = max(ans, f[i - 1] + g[n] - g[j] + l[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
