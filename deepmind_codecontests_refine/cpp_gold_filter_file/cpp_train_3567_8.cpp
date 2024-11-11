#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000005], f[1000005][3], r1, r2, r3, d, more[1000005];
int main() {
  scanf("%d%lld%lld%lld%lld\n", &n, &r1, &r2, &r3, &d);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  f[1][0] = r1 * a[1] + r3;
  f[1][1] = r1 * a[1] + r3;
  more[1] = min(min(r2, r1 * (a[1] + 1)) + r1, r1 * a[1] + r3);
  for (int i = 2; i <= n; i++) {
    more[i] = min(min(r2, r1 * (a[i] + 1)) + r1, r1 * a[i] + r3);
    f[i][0] = f[i - 1][1] + d + r1 * a[i] + r3;
    f[i][1] = f[i - 1][1] + 3 * d + more[i];
    if (i == 2) f[i][1] = min(f[i][1], more[i] + more[i - 1] + 3 * d);
    if (i >= 2)
      f[i][1] = min(f[i][1], f[i - 2][1] + more[i] + more[i - 1] + 4 * d);
    f[i][1] = min(f[i][1], f[i][0]);
  }
  printf("%lld",
         min(f[n][1], f[n - 2][0] + more[n - 1] + 3 * d + r1 * a[n] + r3));
  return 0;
}
