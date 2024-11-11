#include <bits/stdc++.h>
using namespace std;
int n, k, a[200005], g[200005], f[200005];
bitset<200005> d, ans;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), g[a[i]] = i;
  int t = 1, x = 0;
  d[0] = 1;
  d[n + 1] = 1;
  for (int i = n; i >= 1; i--) {
    if (d[g[i]]) continue;
    x++;
    d[g[i]] = 1;
    if (x % 2 == t)
      ans[g[i]] = 0;
    else
      ans[g[i]] = 1;
    int v = 0, j = g[i] + 1;
    while (v < k && j <= n) {
      if (d[j]) {
        j = f[j];
        continue;
      }
      v++;
      d[j] = 1;
      if (x % 2 == t)
        ans[j] = 0;
      else
        ans[j] = 1;
      j++;
    }
    int u = j;
    v = 0;
    j = g[i] - 1;
    while (v < k && j >= 1) {
      if (d[j]) {
        j = f[j];
      } else {
        v++;
        d[j] = 1;
        if (x % 2 == t)
          ans[j] = 0;
        else
          ans[j] = 1;
        j--;
      }
    }
    f[u - 1] = j;
    f[j + 1] = u;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] + 1;
  return 0;
}
