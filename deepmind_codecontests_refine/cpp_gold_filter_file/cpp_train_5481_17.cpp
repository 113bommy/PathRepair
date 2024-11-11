#include <bits/stdc++.h>
using namespace std;
int d1[2005], d2[2005], d3[2005], g[2005], a[2005], n, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1, t = 0; i <= n; i++) {
    int k = upper_bound(g + 1, g + t + 1, a[i]) - g;
    t = max(d1[i] = k, t);
    g[k] = a[i];
  }
  for (int i = n, t = 0; i > 0; i--) {
    int k = upper_bound(g + 1, g + t + 1, a[i], greater<int>()) - g;
    t = max(d2[i] = k, t);
    g[k] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i, t = 0; j <= n; j++) {
      int k = upper_bound(g + 1, g + t + 1, a[j], greater<int>()) - g;
      t = max(d3[j] = k, t);
      g[k] = a[j];
      ans = max(ans, d1[i - 1] + d2[j] + d3[j] - 1);
    }
    ans = max(ans, d1[i - 1] + *max_element(d3 + i, d3 + n + 1) - 1);
  }
  printf("%d", ans);
  return 0;
}
