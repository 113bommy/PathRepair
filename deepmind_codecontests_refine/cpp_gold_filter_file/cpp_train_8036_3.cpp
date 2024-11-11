#include <bits/stdc++.h>
inline int in();
inline void wr(int);
inline int gcd(int, int);
int main(int argc, char** argv) {
  register int T = in();
  while (T--) {
    register int p1 = in(), p2 = in(), k = in();
    if (p1 > p2) p1 ^= p2 ^= p1 ^= p2;
    if (k == 1) {
      puts("REBEL");
      continue;
    }
    register int g = gcd(p1, p2);
    p1 /= g, p2 /= g;
    if ((k - 1) * 1ll * p1 + 1 < p2)
      puts("REBEL");
    else
      puts("OBEY");
  }
}
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
inline int in() {
  register char c = getchar();
  register int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c & 15);
  return x * f;
}
inline void wr(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) wr(x / 10);
  putchar(x % 10 + '0');
}
