#include <bits/stdc++.h>
using namespace std;
const int q = 998244353;
int n, a[1000010], b[1000010], p;
inline int power(int a, long long b) {
  if (!b) return 1;
  int c = power(a, b >> 1);
  c = (long long)c * c % q;
  if (b & 1) c = (long long)c * a % q;
  return c;
}
inline int C(int n, int m) { return (long long)a[n] * b[m] % q * b[n - m] % q; }
int main() {
  int i, j;
  scanf("%d", &n);
  a[0] = b[0] = 1;
  for (i = 1; i <= n; i++) {
    a[i] = (long long)a[i - 1] * i % q;
    b[i] = power(a[i], q - 2);
  }
  for (i = 1, j = 1; i <= n; i++, j = -j)
    p = (p + (long long)j * C(n, i) * power(3, (long long)(n - i) * n + i)) % q;
  for (i = 1, j = 1; i <= n; i++, j = -j)
    p = (p + (long long)j * C(n, i) * 3 * power(power(3, n - i) - 1, n) +
         (long long)j * C(n, i) * (power(3, i) - 3) % q *
             power(3, (long long)(n - i) * n)) %
        q;
  p = (p + q) % q;
  printf("%d\n", p);
  return 0;
}
