#include <bits/stdc++.h>
using namespace std;
int chh;
const int N = 105;
int n, m;
int a[N], b[N];
int gcd(int x, int y) { return x % y ? gcd(y, x % y) : y; }
int main() {
  int i, j, p, x, y, d, n1, n2;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = n; i >= 0; i--) scanf("%d", &a[i]);
    for (i = m; i >= 0; i--) scanf("%d", &b[i]);
    if (n != m) {
      if (n > m) {
        if (a[n] * b[m] < 0) {
          puts("-Infinity");
        } else
          puts("Infinity");
      } else {
        puts("0/1");
      }
    } else {
      n1 = abs(a[n]), n2 = abs(b[n]);
      d = gcd(n1, n2);
      x = n1 / d, y = n2 / d;
      if (a[n] * b[n] < 0)
        printf("-%d/%d\n", x, y);
      else
        printf("%d/%d\n", x, y);
    }
  }
  return 0;
}
