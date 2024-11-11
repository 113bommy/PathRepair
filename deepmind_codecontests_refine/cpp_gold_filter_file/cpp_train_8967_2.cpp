#include <bits/stdc++.h>
using namespace std;
int n = 10;
long long a[15], f[15][15];
long long inv(long long x) {
  long long ret = 1, k = 1000003 - 2;
  for (; k; k >>= 1, x = x * x % 1000003)
    if (k & 1) ret = ret * x % 1000003;
  return ret;
}
void Gauss() {
  for (int i = 0, p; i <= n; i++) {
    for (p = i; p <= n; p++)
      if (f[p][i]) break;
    swap(f[i], f[p]);
    for (int j = 0; j <= n; j++)
      if (i ^ j) {
        long long fac = f[j][i] * inv(f[i][i]) % 1000003;
        for (int k = i; k <= n + 1; k++)
          f[j][k] += 1000003 - fac * f[i][k] % 1000003;
      }
  }
  for (int i = 0; i <= n; i++) a[i] = f[i][n + 1] * inv(f[i][i]) % 1000003;
}
long long calc(long long x) {
  long long ret = 0, c = 1;
  for (int i = 0; i <= n; i++)
    ret = (ret + a[i] * c % 1000003) % 1000003, c = c * x % 1000003;
  return ret;
}
int main() {
  for (int i = 0; i <= n; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= n; j++) f[i][j] = f[i][j - 1] * i % 1000003;
    printf("? %d\n", i), fflush(stdout);
    scanf("%lld", &f[i][n + 1]);
  }
  Gauss();
  for (int i = 0; i < 1000003; i++)
    if (!calc(i)) return printf("! %d\n", i), 0;
  return puts("! -1"), 0;
}
