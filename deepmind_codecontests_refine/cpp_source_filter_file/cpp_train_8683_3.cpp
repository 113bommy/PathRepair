#include <bits/stdc++.h>
const int N = 150000 + 9;
const long long INF = 9999999999999999LL;
int n, m;
long long c[N], f[N], d;
int Max(int x) {
  long long res = -INF;
  for (; x; x -= x & -x) res = std::max(res, c[x]);
  return res;
}
void update(int x, long long y) {
  for (; x <= n; x += x & -x) c[x] = std::max(c[x], y);
}
int main() {
  scanf("%d%d%I64d", &n, &m, &d);
  int past_time = 1, a, b, t;
  while (m--) {
    scanf("%d%d%d", &a, &b, &t);
    for (int i = 1; i <= n; ++i) c[i] = -INF;
    for (int i = n, p = n, x, l, r; i; --i) {
      x = b - abs(a - i);
      l = std::max(1LL, i - d * (t - past_time));
      r = std::min(n * 1LL, i + d * (t - past_time));
      while (p >= l) {
        update(p, f[p]);
        --p;
      }
      f[i] = Max(r) + x;
    }
    past_time = t;
  }
  long long ans = -INF;
  for (int i = 1; i <= n; ++i) ans = std::max(ans, f[i]);
  printf("%I64d\n", ans);
}
