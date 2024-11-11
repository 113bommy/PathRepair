#include <bits/stdc++.h>
using namespace std;
unsigned n, h, st, x, y;
char s[2222];
map<unsigned, unsigned> a, b;
double p, q;
int main() {
  scanf("%u%u", &h, &st);
  n = (1 << h) - 1;
  for (; st--;) {
    scanf("%s", s);
    if (s[0] == 'a') {
      scanf("%u%u", &x, &y);
      b[x] += y;
      while (x) {
        a[x] += y;
        x >>= 1;
      }
    } else {
      p = 0;
      q = 0.5;
      double other = 0.;
      x = 1;
      for (int i = 0; i <= h; ++i) {
        if (a[x * 2] > a[x * 2 + 1]) {
          if (b[x] + a[x * 2] < other) {
            p += other * q * 2;
            break;
          }
          p += (b[x] + a[x * 2]) * q;
          other = max(other, (double)b[x] + a[x * 2 + 1]);
          x *= 2;
        } else {
          if (b[x] + a[x * 2 + 1] < other) {
            p += other * q * 2;
            break;
          }
          p += (b[x] + a[x * 2 + 1]) * q;
          other = max(other, (double)b[x] + a[x * 2]);
          x *= 2;
          ++x;
        }
        if (i == h) p += q * b[x / 2];
        q /= 2;
      }
      printf("%.8lf\n", p);
    }
  }
  return 0;
}
