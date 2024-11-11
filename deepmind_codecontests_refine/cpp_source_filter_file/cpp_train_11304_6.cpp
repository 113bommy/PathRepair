#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
int main() {
  int t = readInt<long long>();
  while (t--) {
    double a = readInt<long long>(), b = readInt<long long>();
    if (a == 0 && b == 0) {
      cout << "1\n";
      continue;
    } else if (a == 0) {
      cout << "0.5\n";
    } else if (b == 0) {
      cout << "1\n";
    } else {
      if (a / 4 <= b) {
        double ans = a * b + ((0.5) * a * a) / 4;
        printf("%.9lf\n", ans / (2 * a * b));
      } else {
        double ans = 2 * a * b - ((0.5) * (4 * b) * (b)) / 4;
        printf("%.9lf\n", ans / (2 * a * b));
      }
    }
  }
}
