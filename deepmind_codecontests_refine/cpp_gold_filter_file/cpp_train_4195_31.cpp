#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &a) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  a = x * f;
}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
signed main() {
  long long t;
  read(t);
  while (t--) {
    long long a, b, c, d;
    read(a, b, c, d);
    if (a > b * c) {
      puts("-1");
      continue;
    }
    long long tmp = a / b - (a % b == 0);
    tmp /= d;
    long long ans = (tmp + 1) * a;
    ans -= b * d * tmp * (tmp + 1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
