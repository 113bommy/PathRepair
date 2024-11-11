#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m) {
  if (m == 0) return n;
  return gcd(m, n % m);
}
int main() {
  int n, m, k;
  long long x1, y1, x2, y2, x3, y3;
  scanf("%d%d%d", &n, &m, &k);
  if (2LL * n * m % k)
    printf("NO\n");
  else {
    int d = gcd(n, k);
    int n0 = n / d;
    int k0 = k / d;
    if (2 * m / k0 <= m) {
      printf("YES\n");
      printf("0 0\n");
      printf("%d 0\n", n0);
      printf("%d %d\n", n0, 2 * m / k0);
    } else if (2 * n0 <= n) {
      printf("YES\n");
      printf("%d %d\n", 0, 0);
      printf("%d 0\n", 2 * n0);
      printf("%d %d\n", 2 * n0, m / k0);
    } else
      printf("NO\n");
  }
  return 0;
}
