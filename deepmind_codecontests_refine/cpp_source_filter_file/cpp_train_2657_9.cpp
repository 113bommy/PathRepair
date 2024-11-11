#include <bits/stdc++.h>
const int N = 200010;
int d, n, m, t, g[N], s[N];
long long ans;
struct T {
  int x, p;
} a[N];
bool cmp(T x, T y) { return x.x < y.x; }
int main() {
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &a[i].x, &a[i].p);
  std::sort(a + 1, a + m + 1, cmp);
  a[++m].x = d;
  for (int i = m; ~i; --i) {
    while (t && a[i].p < a[s[t]].p) --t;
    g[i] = s[t];
    s[++t] = i;
  }
  for (int x, i = 0; i <= m; ++i) {
    d = std::max(std::min(a[g[i]].x - a[i].x, n) - x, 0);
    ans += 1LL * d * a[i].p;
    x -= a[i + 1].x - a[i].x - d;
    if (x < 0) {
      ans = -1;
      break;
    }
  }
  printf("%lld", ans);
}
