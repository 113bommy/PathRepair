#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, t = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') t = -1;
    c = getchar();
  }
  while (isdigit(c)) s = s * 10 + c - 48, c = getchar();
  return s * t;
}
const int N = 1e5 + 5;
int n, a[N], b[N], p, q;
double l = 0, r = 1, y, m1, m2;
inline double F(double x) {
  y = 1;
  for (register int i = 1; i <= n; i++) y = min(y, (1 - a[i] * x) / b[i]);
  return x * p + q * y;
}
int main() {
  n = read(), p = read(), q = read();
  for (register int i = 1; i <= n; i++)
    a[i] = read(), b[i] = read(), r = min(r, 1.0 / a[i]);
  while (r - l > 1e-15) {
    m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (F(m1) > F(m2))
      r = m2;
    else
      l = m1;
  }
  printf("%.8lf\n", F((l + r) / 2));
  return 0;
}
