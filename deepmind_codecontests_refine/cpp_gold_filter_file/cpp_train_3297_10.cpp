#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long w = 0, f = 1;
  char c = ' ';
  while (c < '0' || c > '9') c = getchar(), f = c == '-' ? -1 : f;
  while (c >= '0' && c <= '9') w = w * 10 + c - 48, c = getchar();
  return w * f;
}
long long n, a[100005], ans;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  long long x = 1e10;
  for (long long i = 1; i <= n; i++) {
    long long tmp = ((a[i] - i + n) / n) + 1;
    if (tmp < x) x = tmp, ans = i;
  }
  printf("%lld", ans);
  return 0;
}
