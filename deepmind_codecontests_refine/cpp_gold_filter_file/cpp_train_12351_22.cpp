#include <bits/stdc++.h>
using namespace std;
const long long P = 998244353;
int n;
long long p;
long long c[2010][2010], s[2010], f[2010], p0[2010], p1[2010];
inline long long pm(long long x, long long y) {
  long long z = 1;
  while (y) {
    if (y & 1) z = z * x % P;
    x = x * x % P, y >>= 1;
  }
  return z;
}
int main() {
  scanf("%d", &n);
  int i, j, a, b;
  scanf("%d%d", &a, &b), p = a * pm(b, P - 2) % P;
  f[0] = f[1] = 0, s[1] = 1;
  for (p0[0] = p1[0] = 1, i = 1; i <= n; i++)
    p0[i] = p0[i - 1] * p % P, p1[i] = p1[i - 1] * (1 - p) % P;
  for (i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] * p1[j] + c[i - 1][j - 1] * p0[i - j]) % P;
  }
  for (i = 1; i <= n; i++) {
    s[i] = 1;
    for (j = 1; j < i; j++) s[i] = (s[i] - s[j] * c[i][j]) % P;
  }
  for (i = 2; i <= n; i++) {
    long long tmp = 0;
    for (j = 1; j < i; j++)
      tmp = (tmp + s[j] * c[i][j] % P *
                       (f[j] + f[i - j] + j * (j - 1) / 2 + j * (i - j))) %
            P;
    tmp = (tmp + s[i] * (i * (i - 1) / 2)) % P;
    f[i] = tmp * pm(1 - s[i], P - 2) % P;
  }
  printf("%lld", (f[n] + P) % P);
  return 0;
}
