#include <bits/stdc++.h>
using namespace std;
long long m, n, a, b, c, d, x, y;
char ANS[1000000];
char temp[100];
char *p;
int main(void) {
  while (~scanf("%I64d%I64d", &m, &n)) {
    ANS[0] = 0;
    p = ANS;
    a = 1, b = 0;
    c = 0, d = 1;
    x = 1, y = 1;
    while (x < m || y < n) {
      if (y * m == x * n) break;
      if (m * y <= n * x) {
        long long k = (a * n - b * m - 1) / (d * m - c * n);
        sprintf(temp, "%I64dB", k);
        a += k * c;
        b += k * d;
      } else {
        long long k = (d * m - c * n - 1) / (a * n - b * m);
        sprintf(temp, "%I64dA", k);
        c += k * a;
        d += k * b;
      }
      x = a + c;
      y = b + d;
      strcat(p, temp);
      while (!*p) p++;
    }
    if (x == m && y == n)
      printf("%s\n", ANS);
    else
      printf("Impossible\n");
  }
  return 0;
}
