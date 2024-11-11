#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool f = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = 1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return f ? -x : x;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  putchar('\n');
}
void writep(long long x) {
  write(x);
  putchar(' ');
}
long long const N = 5e5 + 3;
long long n, a[N], v[N];
bool check(double t) {
  double mx = -2e9;
  for (long long i = 1; i <= n; i++)
    if (v[i] > 0)
      mx = max(mx, a[i] + v[i] * t);
    else if (mx >= a[i] + v[i] * t)
      return 1;
  return 0;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read(), v[i] = read();
  double l = 0, r = 1e9;
  long long t = 100, flag = 0;
  while (t--) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      flag = 1, r = mid;
    else
      l = mid;
  }
  if (!flag)
    puts("-1");
  else
    printf("%.20lf\n", r);
  return 0;
}
