#include <bits/stdc++.h>
using namespace std;
int n, s[200010], g[200010];
long long ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &s[i], &g[i]);
    g[i] += s[i];
  }
  for (int i = 2; i <= n; i++) g[i] = min(g[i], g[i - 1] + 1);
  for (int i = 1; i < n; i++) g[i] = min(g[i], g[i + 1] + 1);
  for (int i = 1; i <= n; i++) {
    if (g[i] < s[i]) {
      puts("-1");
      return 0;
    }
    ans += g[i] - s[i];
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) printf("%d ", g[i]);
  return 0;
}
