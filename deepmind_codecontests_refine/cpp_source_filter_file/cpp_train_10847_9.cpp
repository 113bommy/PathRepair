#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  T fg = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x), read(args...);
}
template <typename T>
inline void write(T x) {
  int len = 0;
  char c[21];
  if (x < 0) putchar('-'), x = -x;
  do {
    ++len;
    c[len] = x % 10 + '0';
  } while (x /= 10);
  for (int i = len; i >= 1; i--) putchar(c[i]);
}
template <typename T, typename... Args>
inline void write(T x, Args... args) {
  write(x), write(args...);
}
long long h(long long x, long long n) {
  if (x & (n - (n & -n))) return 0;
  long long res = (n & -n), tmpx = x;
  for (; tmpx && (tmpx & -tmpx) < (n & -n); tmpx -= (tmpx & -tmpx)) res /= 2;
  return res;
}
long long g(long long x, long long n) {
  long long res = 0, tmpn = n;
  for (; tmpn; tmpn -= (tmpn & -tmpn)) res += h(x, tmpn);
  return res;
}
long long f(long long l, long long r) {
  if (l == 0) {
    return 2 * r + 1 + f(1, r);
  }
  if (l == r) return 0;
  if (l & 1) {
    return f(l + 1, r) + 2 * (g(l, r) - g(l, l));
  } else if (r & 1) {
    return f(l, r - 1) + 2 * (g(r - 1, r) - g(r - 1, l));
  }
  return 3 * f(l / 2, r / 2);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    read(l, r);
    long long ans = f(l, r + 1);
    write(ans), putchar('\n');
  }
  return 0;
}
