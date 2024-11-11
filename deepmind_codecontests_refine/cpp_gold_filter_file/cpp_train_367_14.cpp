#include <bits/stdc++.h>
long long f[1001][11][1001], p, v[20];
int n, d;
long long q(long long a, int t) {
  long long x = 1;
  while (t) {
    if (t & 1) x = x * a % p;
    a = a * a % p;
    t >>= 1;
  }
  return x;
}
long long c(long long a, long long b) {
  long long x = 1;
  for (int i = a - b + 1; i <= a; i++) x = x * i % p;
  for (int i = 1; i <= b; i++) x = x * v[i] % p;
  return x;
}
long long ff(int i, int j, int k) {
  if (k == 0) f[i][j][k] = 0;
  if (i == 1 && j == 0 && k == 0) f[i][j][k] = 1;
  if (i == j + 1 && k == 1) f[i][j][k] = 1;
  if (f[i][j][k] != -1)
    return f[i][j][k];
  else
    f[i][j][k] = 0;
  for (int t = 0; t <= j && t * k <= i; t++) {
    f[i][j][k] +=
        ff(i - t * k, j - t, k - 1) * c(ff(k, d - 1, k - 1) + t - 1, t);
    f[i][j][k] %= p;
  }
  return f[i][j][k];
}
int main() {
  int i, j, k, t;
  long long s, r;
  scanf("%d%d%I64d", &n, &d, &p);
  if (n <= 2) {
    printf("1");
    return 0;
  }
  if ((n - 2) % (d - 1)) {
    printf("0");
    return 0;
  }
  for (i = 1; i <= d; i++) v[i] = q(i, p - 2);
  memset(f, 0xFF, sizeof(f));
  s = ff(n, d, (n - 1) / 2);
  r = ff(n / 2, d - 1, n / 2 - 1);
  if (n % 2 == 0) s += r * (r + 1) / 2, s %= p;
  printf("%I64d", s);
  return 0;
}
