#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
inline int read() {
  int x = 0;
  bool f = true;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = false;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
long long n, a[N], ans;
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  for (register int i = 1; i <= n - 1; ++i) {
    if (a[i] > a[i + 1])
      ans += (a[i] - a[i + 1]) * (n - a[i] + 1);
    else
      ans += a[i] * (a[i + 1] - a[i]);
  }
  printf("%lld", ans + a[n] * (n - a[n] + 1));
  return 0;
}
