#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)4e5 + 10;
const long double PI = acosl(-1);
const long double EPS = 1e-18;
int n, c, d;
long long h[MAXN], f[MAXN], g[MAXN], s[MAXN];
long double P[MAXN];
int main() {
  scanf("%d%d%d", &n, &c, &d);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    P[i] = atan2l(y - d, x - c);
    if (P[i] < 0) P[i] += 2 * PI;
  }
  sort(P + 1, P + 1 + n);
  for (int i = 1; i <= n; ++i) {
    int l = i, r = n;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (abs(P[m] - P[i]) <= EPS) {
        h[i] = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    l = i;
    r = n;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (P[m] - P[i] < PI - EPS) {
        f[i] = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    l = i;
    r = n;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (P[m] - P[i] <= PI + EPS) {
        g[i] = m;
        l = m + 1;
      } else
        r = m - 1;
    }
  }
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + f[i] - i + 1;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long x = ans;
    ans += s[f[i]] - s[h[i]] + (h[i] + 1 + f[i]) * (f[i] - h[i]) / 2 -
           (f[i] - h[i]) * (g[i] + 1);
    assert(ans >= x);
  }
  printf("%I64d", ans);
  return 0;
}
