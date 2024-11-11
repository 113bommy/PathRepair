#include <bits/stdc++.h>
int a, b, c, d, e, f, ans = 0;
inline int Max(int p, int q) { return p > q ? p : q; }
inline int Min(int p, int q) { return p < q ? p : q; }
signed main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  for (int i = 0; i <= b && i <= c && i <= d; i++) {
    ans = Max(ans, f * i + e * Min(d - i, a));
  }
  printf("%d", ans);
}
