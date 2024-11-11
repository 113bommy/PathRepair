#include <bits/stdc++.h>
using namespace std;
int a[100005], b, c, d, e, f[100005], g, h, i, j, k, l, m, n;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  k = 2e9;
  for (i = 0; i <= n; i++) {
    f[i] = min(k - (n - i + 1), a[i]);
    k = min(k, a[i] + n - i + 1);
  }
  k = 2e9;
  for (i = n + 1; i; i--) {
    f[i] = min(k - i, f[i]);
    k = min(k, a[i] + i);
  }
  for (i = 1; i <= n; i++) h = max(h, f[i]);
  printf("%d\n", h);
  return 0;
}
