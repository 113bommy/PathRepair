#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
int main() {
  int n, m;
  int a = 0, b = 0;
  int powa = 0, powb = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n + 1; ++i) {
    int t;
    scanf("%d", &t);
    if (a == 0) {
      a = t;
      powa = n - i;
    }
  }
  for (int i = 0; i < m + 1; ++i) {
    int t;
    scanf("%d", &t);
    if (b == 0) {
      b = t;
      powb = m - i;
    }
  }
  if (powa == powb) {
    int z = (a * b > 0 ? 1 : -1);
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    int d = gcd(a, b);
    if (z == -1)
      printf("-%d/%d\n", a / d, b / d);
    else
      printf("%d/%d\n", a / d, b / d);
  } else {
    if (powa > powb) {
      if (a * b < 0) {
        printf("-Infinity\n");
      } else {
        printf("Infinity\n");
      }
    } else {
      printf("0/1\n");
    }
  }
  return 0;
}
