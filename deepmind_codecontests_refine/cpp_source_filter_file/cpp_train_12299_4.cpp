#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, c, d, ans, t[M], p[M];
char s[10];
signed main() {
  n = read();
  c = read();
  d = read();
  for (long long i = 1; i <= n; i++) {
    t[i] = read();
    scanf("%s", s);
    if (s[0] == 'P') p[i] = 1;
  }
  t[n + 1] = read();
  ans = 1e18;
  for (long long i = n, l = 0, r = 0; i >= 1; i--) {
    if (i < n && p[i] == p[i + 1])
      r += min(d, (l - t[i + 1]) * c);
    else
      l = t[i + 1];
    ans = min(ans, (i - 1) * d + r + (t[n + 1] - t[i]) * c);
  }
  printf("%lld\n", ans);
}
