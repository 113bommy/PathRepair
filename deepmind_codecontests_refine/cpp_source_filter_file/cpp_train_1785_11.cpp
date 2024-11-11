#include <bits/stdc++.h>
int fact[1000010];
int inv[1000010];
int s[1010];
int pow(int x, int times) {
  if (x == 0) return 0;
  int res = 1;
  while (times) {
    if (times & 1) res = (long long)res * x % 1000000007;
    x = (long long)x * x % 1000000007;
    times >>= 1;
  }
  return res;
}
int comb(int n, int m) {
  if (n < m) return 0;
  return (long long)fact[n] * inv[m] % 1000000007 * inv[n - m] % 1000000007;
}
int main() {
  fact[0] = inv[0] = fact[1] = inv[1] = 1;
  for (int i = 2; i <= 1000000; ++i) {
    fact[i] = (long long)fact[i - 1] * i % 1000000007;
    inv[i] = (long long)inv[i - 1] * pow(i, 1000000007 - 2) % 1000000007;
  }
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int res = 0;
  if (m == 1) {
    res = pow(k, n);
  } else {
    for (int i = 1; i <= n; ++i) {
      s[i] = 0;
      for (int j = 0; j <= i; ++j) {
        if (j % 2 == 0)
          s[i] = (s[i] + (long long)comb(i, j) * pow(i - j, n)) % 1000000007;
        else
          s[i] = ((s[i] - (long long)comb(i, j) * pow(i - j, n)) % 1000000007 +
                  1000000007) %
                 1000000007;
      }
    }
    for (int a = 0; a <= n; ++a)
      for (int b = 0; b + a <= n; ++b) {
        int t1 = (long long)comb(k, a) * comb(k - a, a) % 1000000007 *
                 comb(k - 2 * a, b) % 1000000007;
        int t2 = s[a + b];
        int t3;
        if (m == 2)
          t3 = 1;
        else
          t3 = pow(b, (n - 2) * m);
        int t =
            (long long)t1 * t2 % 1000000007 * t2 % 1000000007 * t3 % 1000000007;
        res = (res + t) % 1000000007;
      }
  }
  printf("%d\n", res);
  return 0;
}
