#include <bits/stdc++.h>
namespace fast_IO {
const int IN_LEN = 10000000, OUT_LEN = 10000000;
char ibuf[IN_LEN], obuf[OUT_LEN], *ih = ibuf + IN_LEN, *oh = obuf;
char *lastin = ibuf + IN_LEN;
const char *lastout = ibuf + OUT_LEN - 1;
inline char getchar_() {
  if (ih == lastin) lastin = ibuf + fread(ibuf, 1, IN_LEN, stdin), ih = ibuf;
  return (*ih++);
}
inline void putchar_(const char x) {
  if (ih == lastout) fwrite(obuf, 1, oh - obuf, stdout), oh = obuf;
  *oh++ = x;
}
inline void flush() { fwrite(obuf, 1, oh - obuf, stdout); }
}  // namespace fast_IO
using namespace fast_IO;
template <typename T>
inline T max(const T a, const T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(const T a, const T b) {
  return a < b ? a : b;
}
template <typename T>
inline T abs(const T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline void swap(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}
template <typename T>
inline T gcd(const T a, const T b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
template <typename T>
inline T square(const T x) {
  return x * x;
};
template <typename T>
inline void read(T &x) {
  char cu = getchar();
  x = 0;
  bool fla = 0;
  while (!isdigit(cu)) {
    if (cu == '-') fla = 1;
    cu = getchar();
  }
  while (isdigit(cu)) x = x * 10 + cu - '0', cu = getchar();
  if (fla) x = -x;
}
template <typename T>
void printe(const T x) {
  if (x >= 10) printe(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void print(const T x) {
  if (x < 0)
    putchar('-'), printe(-x);
  else
    printe(x);
}
inline void judge() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
long long p, k;
long long xs[1000001], top = -1;
std::set<long long> Hash;
int main() {
  read(p), read(k);
  while (p) {
    register long long newp = -p / k;
    p %= k;
    if (p < 0) p += k, newp++;
    xs[++top] = p;
    if (Hash.find(newp) != Hash.end()) {
      puts("-1");
      return flush(), 0;
    } else
      Hash.insert(newp);
    p = newp;
  }
  print(top + 1), putchar('\n');
  print(xs[0]);
  for (register int i = 1; i <= top; i++) putchar(' '), print(xs[i]);
  return flush(), 0;
}
