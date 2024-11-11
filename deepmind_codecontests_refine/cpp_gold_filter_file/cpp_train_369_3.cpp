#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
const long long N = 1e5 + 5;
long long n, m, xm[N], xc[N], l[N], r[N], best[N], ans, x = 1;
signed main() {
  memset(best, 0x3f, sizeof(best));
  n = read(), m = read();
  read();
  read();
  for (long long i = 1; i <= n; i++) xm[i] = read();
  for (long long i = 1; i <= m; i++) xc[i] = read();
  xc[0] = INT_MIN;
  xc[m + 1] = INT_MAX;
  for (long long i = 1; i <= n; i++) {
    while (xc[x] < xm[i]) x++;
    l[i] = x - 1;
    r[i] = x;
  }
  for (long long i = 1; i <= n; i++) {
    long long dis1 = abs(xc[l[i]] - xm[i]), dis2 = abs(xc[r[i]] - xm[i]);
    long long dis = min(dis1, dis2), c = r[i];
    if (dis2 > dis1 || (dis1 == dis2 && (best[l[i]] == 0x3f3f3f3f3f3f3f3f ||
                                         best[l[i]] == dis)))
      c--;
    if (best[c] == dis || best[c] == 0x3f3f3f3f3f3f3f3f) ans++;
    best[c] = min(best[c], dis);
  }
  printf("%lld", n - ans);
  return 0;
}
