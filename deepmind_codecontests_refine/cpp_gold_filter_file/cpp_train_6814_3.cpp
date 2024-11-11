#include <bits/stdc++.h>
using namespace std;
unsigned long long a;
unsigned long long fm(unsigned long long x, unsigned long long y) {
  x %= a, y %= a;
  unsigned long long ret = 0;
  while (y) {
    if (y & 1) ret = (ret + x) % a;
    x = (x + x) % a;
    y >>= 1;
  }
  return ret;
}
int main() {
  scanf("%llu", &a);
  unsigned long long t = 1, s = 0;
  for (int i = 0; i < 19; i++) t *= 10;
  s = fm(t / 10, 19 * 45) + 1;
  s = a - s % a;
  printf("%llu %llu", 1 + s, t + s);
  return 0;
}
