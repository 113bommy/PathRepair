#include <bits/stdc++.h>
using namespace std;
const unsigned long long mo = 1ll << 32;
int sl[145];
unsigned long long C[145];
void rd(int &l) {
  l = 0;
  int f = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    l = l * 10 + (ch ^ 48);
    ch = getchar();
  }
  if (f) l = -l;
}
int mn(int x, int y) { return x < y ? x : y; }
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
unsigned long long dit(unsigned long long x) { return x >= mo ? x - mo : x; }
int main() {
  int n, q, p, x, y, z;
  unsigned long long ans, uns, rns;
  rd(n);
  rd(q);
  rd(p);
  x = mn(n - 1, q);
  C[0] = 1;
  for (int i = 1; i <= x; ++i) {
    ans = 1;
    for (int j = 1; j <= i; ++j) sl[j] = j;
    for (int j = 0; j < i; ++j) {
      y = n - j;
      for (int k = 1; k <= i; ++k) {
        z = gcd(y, sl[k]);
        y /= z;
        sl[k] /= z;
      }
      ans = ans * y % mo;
    }
    C[i] = ans;
  }
  ans = 0;
  for (int i = 1; i <= p; ++i) {
    uns = 0;
    rns = 1;
    for (int j = 0; j <= x; ++j, rns = rns * i % mo)
      uns = dit(uns + C[j] * rns % mo);
    uns = uns * i % mo;
    ans ^= uns;
  }
  printf("%llu\n", ans);
  return 0;
}
