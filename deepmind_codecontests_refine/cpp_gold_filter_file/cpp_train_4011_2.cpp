#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline char gc() {
  static const int L = 1000;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) return EOF;
  }
  return *sss++;
}
inline int read(int& x) {
  x = 0;
  char c = getchar();
  bool f = false;
  for (; !isdigit(c); c = getchar()) {
    if (c == EOF) return -1;
    if (c == '-') f = true;
  }
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return 1;
}
long long z, c, s, x, n;
int main() {
  while (scanf("%lld%lld", &s, &x) == 2) {
    n = (s - x) / 2;
    if (x > s || n * 2 + x != s || (x & n) != 0) {
      puts("0");
      continue;
    }
    c = 0;
    while (x) {
      if (x & 1) c++;
      x >>= 1;
    }
    z = 1ll << c;
    if (!n) z -= 2;
    printf("%lld\n", z);
  }
  return 0;
}
