#include <bits/stdc++.h>
using namespace std;
int n, i, ans, nn, a[200010], f[200010], vis[200010], j, now, cnt;
int main() {
  scanf("%d", &n);
  nn = n;
  ans = 1;
  f[0] = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    f[i] = f[i - 1] * 2 % 1000000007;
  }
  for (i = 1; i <= n; i++)
    if (!vis[i]) {
      now = cnt;
      for (j = i; !vis[j]; j = a[j]) vis[j] = ++cnt;
      if (vis[j] > now) {
        nn -= cnt - vis[j] + 1;
        ans = ans * (f[cnt - vis[j] + 1] - 2) % 1000000007;
        if (ans < 0) ans += 1000000007;
      }
    }
  ans = 1 * ans * f[nn] % 1000000007;
  printf("%d\n", ans);
}
