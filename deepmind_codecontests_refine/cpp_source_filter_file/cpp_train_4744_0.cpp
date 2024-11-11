#include <bits/stdc++.h>
using namespace std;
long long sum, now;
int a[200005], b[200005], c[200005], num[35];
int i, j, k, n;
bool vis[200005][35];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (i = 1; i <= n; i++) sum += b[i] + c[i];
  sum /= 2 * n;
  for (i = 1; i <= n; i++) a[i] = (b[i] + c[i] - sum) / n;
  for (i = 1; i <= n; i++)
    for (j = 0; (1 << j) <= a[i]; j++)
      if (a[i] & (1 << j)) num[j]++, vis[i][j] = 1;
  for (i = 1; i <= n; i++) {
    now = 0;
    for (j = 0; (1 << j) <= a[i]; j++)
      if (vis[i][j]) now += 1ll * (1 << j) * num[j];
    if (now != b[i]) {
      puts("-1");
      return 0;
    }
    now = 0;
    for (j = 0; (1 << j) <= 30; j++)
      if (vis[i][j])
        now += 1ll * (1 << j) * n;
      else
        now += 1ll * (1 << j) * num[j];
    if (now != c[i]) {
      puts("-1");
      return 0;
    }
  }
  for (i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
