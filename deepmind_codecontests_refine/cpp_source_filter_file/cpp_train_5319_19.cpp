#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
const int N = 6666;
const double eps = 1e-9;
int n, m, a[N], b[N];
void Get(long double &x, int y) { x = x * (y - 1) / y; }
int main() {
  read(n);
  read(m);
  for (register int i = 1; i <= n; i++) read(a[i]);
  for (register int i = 1; i <= n; i++) read(b[i]);
  double l = 0, r = 1e9, res = 2e9;
  for (register int t = 70; t >= 1; t--) {
    double mid = (l + r) / 2;
    long double now = m + mid;
    for (register int i = 1; i <= n; i++)
      Get(now, a[i]), Get(now, b[i < n ? i + 1 : 1]);
    if (now >= m)
      res = mid, r = mid;
    else
      l = mid;
  }
  if (res > 1e9 + eps)
    puts("-1");
  else
    printf("%.9lf", res);
  return 0;
}
