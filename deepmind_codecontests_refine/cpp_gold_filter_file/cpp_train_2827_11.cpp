#include <bits/stdc++.h>
using namespace std;
int n, maxx, ans, minor, dp[200100], f[200100];
vector<int> r1, r2;
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), f[x]++, maxx = max(maxx, x);
  for (int i = maxx; i >= 1; i--) {
    dp[i] = f[i] + (f[i + 1] >= 2 ? dp[i + 1] : f[i + 1]);
    if (ans < dp[i]) ans = dp[i], minor = i;
  }
  if (ans == 0) {
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) printf("%d ", maxx);
    return 0;
  }
  printf("%d\n", ans);
  for (int i = minor;; i++) {
    int aux = f[i];
    if (f[i]) r1.push_back(i), f[i]--;
    while (f[i]--) r2.push_back(i);
    if (aux < 2 && i != minor) break;
  }
  reverse(r2.begin(), r2.end());
  for (auto u : r1) printf("%d ", u);
  for (auto u : r2) printf("%d ", u);
}
