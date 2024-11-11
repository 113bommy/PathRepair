#include <bits/stdc++.h>
using namespace std;
template <class T>
void in(T &x) {
  x = 0;
  bool f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  if (f) x = -x;
}
long long n, m;
void print(long long x) {
  printf("%lld", x);
  exit(0);
}
signed main() {
  in(n), in(m);
  if (n > m) swap(n, m);
  if (n == 1) print(m - m % 6 + max(0ll, m % 6 - 3));
  if ((n & 1) == 0 && (m & 1) == 0) {
    if (n == 2 && m == 2)
      print(0);
    else
      print(n * m);
  }
  if ((n + m) & 1) {
    if (m & 1) swap(n, m);
    if (m == 2) {
      if (n == 3) print(4);
      if (n == 7) print(12);
    }
    print(n * m);
  } else
    print(n * m - 1);
  return 0;
}
