#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  long long n, m, k, f, a, b, kx;
  scanf("%I64d %I64d %I64d", &n, &m, &k);
  kx = k;
  if (m * 2 * n % k == 0) {
    printf("YES\n");
    printf("0 0\n");
    if (k % 2 == 0) kx /= 2;
    a = n / gcd(n, kx);
    b = m / gcd(m, kx);
    if (kx == k)
      if (a * 2 <= n)
        a *= 2;
      else
        b *= 2;
    printf("%I64d 0\n", a);
    printf("0 %I64d\n", b);
  } else
    printf("NO");
}
