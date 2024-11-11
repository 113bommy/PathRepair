#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[1100000], l[1100000], r[1100000];
long long d[1100000];
double ans[1100000];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  a[0] = a[n + 1] = -(1 << 50);
  for (long long i = 1; i <= n; i++) {
    long long tmp = i;
    while (a[i] <= a[tmp - 1]) tmp = l[tmp - 1];
    l[i] = tmp;
  }
  for (long long i = n; i; i--) {
    long long tmp = i;
    while (a[i] < a[tmp + 1]) tmp = r[tmp + 1];
    r[i] = tmp;
  }
  for (long long i = 1; i <= n; i++) {
    long long x = i - l[i] + 1, y = r[i] - i + 1;
    if (x < y) swap(x, y);
    d[x + 1] -= a[i], d[x + y + 1] += a[i];
    d[1] += a[i], d[y + 1] -= a[i];
  }
  long long sum = 0, dd = 0;
  for (long long i = 1; i <= n; i++) {
    dd += d[i];
    sum += dd;
    ans[i] = (double)sum / (double)(n - i + 1);
  }
  long long q = read();
  for (long long i = 1; i <= q; i++) printf("%lf\n", ans[read()]);
  return 0;
}
