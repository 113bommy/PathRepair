#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, m;
long long x, k, y;
long long a[200010], b[200010];
long long lft[200010], rgt[200010];
long long pos[200010];
long long cnt;
long long ans;
signed main() {
  n = read(), m = read();
  x = read(), k = read(), y = read();
  for (long long i = 1; i <= n; ++i) a[i] = read(), pos[a[i]] = i;
  for (long long i = 1; i <= m; ++i) b[i] = read();
  long long lst = 0;
  for (long long i = 1; i <= m; ++i) {
    if (pos[b[i]] > lst) {
      lft[++cnt] = lst + 1;
      rgt[cnt] = pos[b[i]] - 1;
      if (lft[cnt] == rgt[cnt]) --cnt;
      lst = pos[b[i]];
    } else {
      printf("-1\n");
      return 0;
    }
  }
  if (lst < n) lft[++cnt] = lst + 1, rgt[cnt] = n;
  for (long long i = 1; i <= cnt; ++i) {
    long long maxn = 0, l = a[lft[i] - 1], r = a[rgt[i] + 1],
              len = rgt[i] - lft[i] + 1;
    for (long long j = lft[i]; j <= rgt[i]; ++j) maxn = max(maxn, a[j]);
    if (len < k && l < maxn && r < maxn) {
      printf("-1\n");
      return 0;
    }
    if (x <= y * k)
      ans = ans + (len / k) * x + (len % k) * y;
    else {
      if (l > maxn || r > maxn)
        ans = ans + y * len;
      else {
        ans = ans + y * (len - k) + x;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
