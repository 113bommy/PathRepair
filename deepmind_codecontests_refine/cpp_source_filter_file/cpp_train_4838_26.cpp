#include <bits/stdc++.h>
using namespace std;
char a[100005], b[100005];
long long int n, m, h1[100005], h2[100005], h3[100005], h, hh, hhh;
long long int c[200005];
long long int d[100005];
long long int d1[100005];
long long int powmod(long long int a, long long int b) {
  long long int an = 1;
  while (b > 0) {
    if (b & 1) an = (an * a) % 1000000007;
    b >>= 1;
    a = (a * a) % 1000000007;
  }
  return an;
}
int main() {
  scanf("%s\n", a);
  scanf("%s", b);
  n = strlen(a);
  m = strlen(b);
  for (int i = 1; i <= n; i++) {
    h1[i] = (powmod(101, i) * a[i - 1]) % 1000000007;
    h2[i] = (powmod(41, i) * a[i - 1]) % 1000000007;
    h3[i] = (powmod(29, i) * a[i - 1]) % 1000000007;
  }
  for (int i = 1; i <= n; i++)
    h1[i] = (h1[i] + h1[i - 1]) % 1000000007,
    h2[i] = (h2[i] + h2[i - 1]) % 1000000007,
    h3[i] = (h3[i] + h3[i - 1]) % 1000000007;
  for (int i = 1; i <= m; i++)
    h = (h + powmod(101, i) * b[i - 1]) % 1000000007,
    hh = (hh + powmod(41, i) * b[i - 1]) % 1000000007,
    hhh = (hhh + powmod(29, i) * b[i - 1]) % 1000000007;
  for (int i = 1; i <= n; i++) {
    if (i + m - 1 <= n) {
      long long int x = (h1[i + m - 1] - h1[i - 1] + 1000000007) % 1000000007;
      x = (x * powmod(powmod(101, i - 1), 1000000007 - 2)) % 1000000007;
      long long int y = (h2[i + m - 1] - h2[i - 1] + 1000000007) % 1000000007;
      y = (y * powmod(powmod(41, i - 1), 1000000007 - 2)) % 1000000007;
      long long int z = (h3[i + m - 1] - h3[i - 1] + 1000000007) % 1000000007;
      z = (z * powmod(powmod(29, i - 1), 1000000007 - 2)) % 1000000007;
      if (x == h && y == hh && z == hhh) c[i + m - 2] = 1;
    }
  }
  d[n] = 1;
  d1[n] = 1;
  long long int m1 = 2 * n + 1;
  long long int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (c[i + m - 1]) m1 = i + m - 1;
    ans = (ans + d1[m1 + 1]) % 1000000007;
    d[i] = (d[i + 1] + d1[m1 + 1]) % 1000000007;
    d1[i] = (d[i] + d1[i + 1]) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
