#include <bits/stdc++.h>
using namespace std;
int n, a[500010], f[500010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) f[i] = -1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  f[1] = a[1];
  f[n] = a[n];
  int ans = 0;
  for (int i = 2; i < n; i++)
    if (a[i] == a[i - 1] || a[i] == a[i + 1]) f[i] = a[i];
  for (int i = 1, j; i <= n; i = j) {
    while (i <= n && f[i] != -1) i++;
    if (i > n) break;
    j = i + 1;
    while (j <= n && f[j] == -1) j++;
    int tmp = j - i;
    if (tmp % 2 == 0) {
      for (int k = i; k <= i + tmp - 1; k++) f[k] = f[i - 1];
      for (int k = i + tmp; k < j; k++) f[k] = f[j];
    } else
      for (int k = i; k < j; k++) f[k] = f[j];
    ans = max(ans, (tmp + 1) / 2);
  }
  printf("%d\n", ans);
  for (int i = 1; i < n; i++) printf("%d ", f[i]);
  printf("%d", f[n]);
  return 0;
}
