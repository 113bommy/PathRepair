#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
int readint() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long n, p;
int main() {
  n = readint();
  p = readint();
  for (long long i = 1;; i++) {
    n -= p;
    if (n <= 0) return printf("-1\n"), 0;
    if (n < i) continue;
    if (__builtin_popcountll(n) <= i) return printf("%lld\n", i), 0;
  }
  printf("-1\n");
  return 0;
}
