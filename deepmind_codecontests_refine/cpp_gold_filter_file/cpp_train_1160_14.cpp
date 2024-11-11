#include <bits/stdc++.h>
using namespace std;
long long n, a[100003], ans;
template <typename Tp>
void read(Tp &x) {
  x = 0;
  char ch = 1;
  long long fh;
  while (ch != '-' && (ch > '9' || ch < '0')) ch = getchar();
  if (ch == '-') {
    ch = getchar();
    fh = -1;
  } else
    fh = 1;
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  x *= fh;
}
signed main() {
  read(n);
  for (register long long i = 1; i <= n; i++) read(a[i]);
  for (register long long i = 1; i < n; i++) {
    ans += (a[i + 1] - a[i]) * a[i] * (a[i + 1] > a[i]) +
           (a[i] - a[i + 1]) * (n - a[i] + 1) * (a[i + 1] <= a[i]);
  }
  ans += a[n] * (n - a[n] + 1);
  printf("%lld\n", ans);
  return 0;
}
