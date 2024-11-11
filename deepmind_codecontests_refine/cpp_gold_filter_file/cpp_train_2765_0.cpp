#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 2e5 + 10;
long long s[N], n, f[N], maxn;
signed main() {
  n = read();
  for (register long long i = 1; i <= n; ++i) s[i] = s[i - 1] + read();
  maxn = s[n];
  for (register long long i = n - 1; i >= 1; --i)
    f[i] = maxn, maxn = max(maxn, s[i] - f[i]);
  cout << f[1];
  return 0;
}
