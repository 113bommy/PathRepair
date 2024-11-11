#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
long long sum[200005], f[200005][3];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    printf("%d", a[1]);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (i & 1)
      sum[i] = sum[i - 1] + a[i];
    else
      sum[i] = sum[i - 1] - a[i];
  f[1][1] = -a[1];
  f[1][0] = f[1][2] = -1e16;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 3; j++) f[i][j] = -1e16;
    if (i & 1)
      f[i][(i + 1) / 2 % 3] = sum[i - 1] - a[i];
    else
      f[i][(i - 1) / 2 % 3] = sum[i - 1] + a[i];
    for (int j = 0; j < 3; j++)
      f[i][j] =
          max(f[i][j], max(f[i - 1][j] + a[i], f[i - 1][(j - 1) % 3] - a[i]));
  }
  printf("%lld", f[n][(200005 - 3 - n) % 3]);
}
