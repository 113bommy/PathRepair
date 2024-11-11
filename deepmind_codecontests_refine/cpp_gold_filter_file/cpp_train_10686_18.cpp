#include <bits/stdc++.h>
using namespace std;
long long n, q, t, x, sb;
inline void read(long long &x) {
  x = 0;
  static char c = getchar();
  while (!('0' <= c && c <= '9')) c = getchar();
  while ('0' <= c && c <= '9') x = x * 10 + c - 48, c = getchar();
}
int main() {
  read(n), read(q);
  while (q--) {
    read(x), sb = n, t = 0;
    while (sb > 1) {
      if (x & 1) {
        t = sb - (x >> 1);
        break;
      }
      x = (x >> 1) + (sb & 1), sb = sb + 1 >> 1;
    }
    if (!t) t = 1;
    printf("%lld\n", n + 1 - t);
  }
  return 0;
}
