#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char c = getchar();
  bool f = 0;
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 1) + (x << 3) + c - '0', c = getchar())
    ;
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
template <class T>
bool Enlarge(T &a, T const &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
bool Reduce(T &a, T const &b) {
  return a > b ? a = b, 1 : 0;
}
long long n, l, r, k, m;
void work1() {
  long long x = n - m;
  for (long long i = 2 * n; i >= n; --i) {
    long long t = (k - 1) % i + 1;
    if (m <= t && t <= m * 2)
      if ((t - x <= i && i <= 2 * x + t) ||
          ((t + 1 - x <= i && i <= 2 * x + t + 1))) {
        write(i - n);
        puts("");
        return;
      }
  }
  puts("-1");
}
void work2() {
  long long res = -n, x = n - m;
  if (m <= k && k <= 2 * m) {
    write(min(k - m + 1 + x, n));
    puts("");
    return;
  }
  for (long long i = 1, lim = k / n; i <= lim; ++i) {
    long long L = (k - 2 * m + i - 1) / i, R = (k - m) / i;
    Enlarge(L, n);
    Reduce(R, 2 * n);
    Enlarge(L, (k - x + i) / (i + 1));
    Reduce(R, (2 * x + k + 1) / (i + 1));
    if (L <= R) Enlarge(res, R);
  }
  write(res < 0 ? -1 : res - n), puts("");
}
int main() {
  n = read(), l = read(), r = read(), k = read();
  m = r - l + 1;
  if (m < 0) m += n;
  if (n <= k / n)
    work1();
  else
    work2();
}
