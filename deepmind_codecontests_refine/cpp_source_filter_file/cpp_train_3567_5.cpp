#include <bits/stdc++.h>
using namespace std;
int a[1000010];
long long x[1000010], y[1000010];
int n;
long long d, r1, r2, r3;
long long f[1000010][3];
int main() {
  scanf("%d %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    x[i] = r1 * a[i] + r3;
    y[i] = min((a[i] + 2) * r1, r2 + r1);
    x[i] += d;
    y[i] += 2 * d;
  }
  memset(f, 0x3f, sizeof(f));
  f[1][0] = x[1] - d;
  f[1][1] = y[1] - d;
  for (int i = 1; i < n; i++) {
    f[i + 1][0] = min(f[i + 1][0], f[i][0] + x[i + 1]);
    f[i + 1][1] = min(f[i + 1][1], f[i][0] + y[i + 1]);
    f[i + 1][0] = min(f[i + 1][0], f[i][1] + x[i + 1] + d);
    f[i + 1][2] = min(f[i + 1][2], f[i][1] + y[i + 1]);
    f[i + 1][0] = min(f[i + 1][0], f[i][2] + x[i + 1]);
    f[i + 1][2] = min(f[i + 1][2], f[i][2] + y[i + 1]);
  }
  printf("%lld\n",
         min(f[n - 1][1] + x[n], min(f[n][0], min(f[n][1] + d, f[n][2]))));
  return 0;
}
