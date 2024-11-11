#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!(a % b))
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  int n, i, d, k, s = 0, g;
  scanf("%d", &n);
  for (i = 2; i <= n - 1; ++i) {
    d = n;
    while (d >= i) {
      s += (d % i);
      d /= i;
    }
    s += d;
  }
  g = gcd(s, n - 2);
  printf("%d/%d", s / g, n - 2 / g);
  return 0;
}
