#include <bits/stdc++.h>
namespace io {
const char endl = '\n';
template <typename T>
inline void chkmin(T &a, T b) {
  a > b ? a = b : 0;
}
template <typename T>
inline void chkmax(T &a, T b) {
  a < b ? a = b : 0;
}
struct Stream {
  template <class T>
  Stream operator>>(T &x) {
    x = 0;
    register int f = 1;
    register char c;
    while (!isdigit(c = getchar()))
      if (c == '-') f = -1;
    while (x = (x << 1) + (x << 3) + (c ^ 48), isdigit(c = getchar()))
      ;
    return x *= f, *this;
  }
  Stream operator>>(char *str) { return scanf("%s", str), *this; }
  template <class T>
  Stream operator<<(T x) {
    static char out[35];
    static unsigned int top = 0;
    if (x < 0) x = -x, putchar('-');
    while (out[++top] = x % 10 ^ 48, x /= 10, x)
      ;
    while (putchar(out[top--]), top)
      ;
    return *this;
  }
  Stream operator<<(char *str) { return printf("%s", str), *this; }
  Stream operator<<(char ch) { return putchar(ch), *this; }
} cin, cout;
}  // namespace io
int n, m;
int main() {
  std::cin >> m >> n;
  long double ans = 0;
  for (register unsigned int i = 1, iend = m; i <= iend; ++i)
    ans += 1.0 * i * std::pow(1.0 * i / m, n) -
           1.0 * i * std::pow(1.0 * (i - 1) / m, n);
  printf("%.8Lf", ans);
  return 0;
}
