#include <bits/stdc++.h>
using namespace std;
int n, m, a[3005];
int ans = 0;
int dfs(int u) {
  if (u >= 1 << n) return a[u];
  int l = dfs(u << 1);
  int r = dfs(u << 1 | 1);
  ans += abs(l - r);
  return max(l, r);
}
int main() {
  scanf("%d", &n);
  m = (1 << (n + 1)) - 1;
  for (int i = 2; i <= m; ++i) scanf("%d", a + i);
  for (int i = 1 << n; i <= m; ++i) {
    for (int j = i >> 1; j; j >>= 1) {
      a[i] += a[j];
    }
  }
  dfs(1);
  printf("%d\n", ans);
  return 0;
}
