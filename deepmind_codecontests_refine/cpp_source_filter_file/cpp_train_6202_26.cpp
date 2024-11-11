#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& num) {
  num = 0;
  bool f = true;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = false;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num = num * 10 + ch - '0';
    ch = getchar();
  }
  num = f ? num : -num;
}
int out[100];
template <class T>
inline void write(T x, char ch) {
  if (x == 0) {
    putchar('0');
    putchar(ch);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int num = 0;
  while (x) {
    out[num++] = (x % 10);
    x = x / 10;
  }
  for (int i = (num - 1); i >= (0); i--) putchar(out[i] + '0');
  putchar(ch);
}
const double eps = 1e-8;
int ans, t1, t2, p, d;
int main() {
  int maxr, x1, x2;
  read(maxr);
  read(x1);
  read(x2);
  read(t1);
  read(t2);
  read(p);
  read(d);
  if (t2 <= t1) {
    write(abs(x1 - x2) * t2, '\n');
    return 0;
  }
  int ans = abs(x1 - x2) * t2;
  if (x1 <= x2) {
    if (d == 1) {
      if (p <= x1)
        ans = min(ans, (x2 - p) * t1);
      else
        ans = min(ans, t1 * (maxr + maxr - p + x2));
    } else {
      ans = min(ans, (p + x2) * t1);
    }
  } else {
    if (d == 1) {
      ans = min(ans, (maxr - p + maxr - x2) * t1);
    } else {
      if (p >= x1)
        ans = min(ans, (p - x1) * t1);
      else
        ans = min(ans, (p + maxr + maxr - x2) * t1);
    }
  }
  write(ans, '\n');
}
