#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
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
inline void wrote(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) wrote(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  wrote(x);
  puts("");
}
const long long maxn = 111;
double p[maxn], win, tim;
long long n, a[maxn];
int main() {
  n = read();
  win = 1;
  for (long long i = 1; i <= n; ++i) {
    p[i] = (a[i] = read()) * 0.01;
    win *= p[i];
  }
  tim = n;
  for (long long it = 0; ((1 - win) > 1e-10) && (it <= 500000); it++) {
    tim += 1 - win;
    long long cho = 0;
    double cho_v = 0;
    for (long long i = 1; i <= n; ++i) {
      double now_v = (1 - p[i]) * a[i] * 0.01 / p[i];
      if (now_v > cho_v) cho_v = now_v, cho = i;
    }
    win = 1;
    p[cho] = 1 - (1 - p[cho]) * a[cho] * 0.01;
    for (long long i = 1; i <= n; ++i) win = win * p[i];
  }
  printf("%lf\n", tim);
}
