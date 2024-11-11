#include <bits/stdc++.h>
using namespace std;
namespace fast_io {
char buf[1 << 12], *p1 = buf, *p2 = buf, sr[1 << 23], z[23], nc;
int C = -1, Z = 0, Bi = 0, ny;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  ny = 1;
  while (nc = gc(), (nc < 48 || nc > 57) && nc != EOF)
    if (nc == 45) ny = -1;
  Bi = 1;
  if (nc < 0) return nc;
  x = nc - 48;
  while (nc = gc(), 47 < nc && nc < 58 && nc != EOF)
    x = (x << 3) + (x << 1) + (nc ^ 48), Bi++;
  return x * ny;
}
inline double gf() {
  int a = read(), y = ny, b = (nc != '.') ? 0 : read();
  return (b ? a + (double)b / pow(10, Bi) * y : a);
}
inline int gs(char *s) {
  char c, *t = s;
  while (c = gc(), c <= 32)
    ;
  *s++ = c;
  while (c = gc(), c > 32) *s++ = c;
  return s - t;
}
inline void ot() {
  fwrite(sr, 1, C + 1, stdout);
  C = -1;
}
inline void flush() {
  if (C > 1 << 22) ot();
}
template <typename T>
inline void write(T x, char t) {
  int y = 0;
  if (x < 0) y = 1, x = -x;
  while (z[++Z] = x % 10 + 48, x /= 10)
    ;
  if (y) z[++Z] = '-';
  while (sr[++C] = z[Z], --Z)
    ;
  sr[++C] = t;
  flush();
}
inline void write(char *s) {
  int l = strlen(s);
  for (int i = 0; i < l; i++) sr[++C] = *s++;
  sr[++C] = '\n';
  flush();
}
};  // namespace fast_io
using namespace fast_io;
const int p = 998244353, r[16] = {0,   4,  8,   -1, 16,  -10, 4,  -12,
                                  -48, 26, -44, 15, -16, -4,  -4, -1};
int n, a[16] = {0,    0,    0,     24,    4,      240,    204,     1316,
                2988, 6720, 26200, 50248, 174280, 436904, 1140888, 3436404};
inline void M(int &x) {
  x -= p;
  x += x >> 31 & p;
}
int main() {
  n = read();
  for (int i = 16; i <= n; i++) {
    int x = 0;
    for (int j = 0; j < 16; j++) M(x += 1ll * a[j] * r[(i - j - 1) & 15] % p);
    a[i & 15] = x;
  }
  write((a[n & 15] + p) % p, '\n');
  return ot(), 0;
}
