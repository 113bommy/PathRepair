#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353;
int n;
long long a, b, c[2001][2001], h[2001], f[2001], p;
long long mul(long long x, long long y) {
  if (y == 0) return 1;
  long long now = mul(x, y / 2);
  now = now * now % mo;
  if (y % 2) return now * x % mo;
  return now;
}
void prework() {
  c[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j] * mul(p, j) % mo +
                   c[i - 1][j - 1] * mul(1 - p, i - j) % mo) %
                  mo;
    }
  h[1] = 1;
  for (int i = 2; i <= n; i++) {
    h[i] = 1;
    for (int j = 1; j < i; j++) h[i] = (h[i] - c[i][j] * h[j] % mo) % mo;
  }
}
void work() {
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    long long now = 0;
    for (int j = 1; j < i; j++)
      now = (now + c[i][j] * h[j] % mo *
                       (f[j] + j * (j - 1) / 2 + j * (i - j) + f[i - j]) % mo) %
            mo;
    f[i] = now + h[i] * (i * (i - 1) / 2) % mo;
    f[i] = f[i] * mul(1 - h[i], mo - 2) % mo;
  }
  f[n] = (f[n] + mo) % mo;
  printf("%lld\n", f[n]);
}
int main() {
  scanf("%d%lld%lld", &n, &a, &b);
  p = mul(b, mo - 2) * a % mo;
  prework();
  work();
  return 0;
}
