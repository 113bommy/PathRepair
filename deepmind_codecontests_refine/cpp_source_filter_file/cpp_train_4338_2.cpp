#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 47;
int n, m, nl, ne, v, q;
int l[maxn], e[maxn];
int tot, ans;
int main() {
  scanf("%d%d%d%d%d", &n, &m, &nl, &ne, &v);
  for (int i = 1; i <= nl; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= ne; i++) scanf("%d", &e[i]);
  sort(l + 1, l + nl + 1);
  sort(e + 1, e + ne + 1);
  scanf("%d", &q);
  while (q--) {
    ans = 0x3f3f3f3f;
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int k1 = lower_bound(l + 1, l + nl + 1, y1) - l;
    int k2 = lower_bound(e + 1, e + ne + 1, y1) - e;
    if (nl != 0) {
      if (k1 == 1)
        ans = min(ans, abs(x2 - x1) + abs(y1 - l[k1]) + abs(y2 - l[k1]));
      else if (k1 > 1 && k1 <= n)
        ans = min(
            ans, abs(x2 - x1) + min(abs(y1 - l[k1]) + abs(y2 - l[k1]),
                                    abs(y1 - l[k1 - 1]) + abs(y2 - l[k1 - 1])));
      else
        ans =
            min(ans, abs(x2 - x1) + abs(y1 - l[k1 - 1]) + abs(y2 - l[k1 - 1]));
    }
    if (ne != 0) {
      if (k2 == 1)
        ans = min(ans, (abs(x2 - x1) - 1) / v + 1 + abs(y1 - e[k2]) +
                           abs(y2 - e[k2]));
      else if (k2 > 1 && k2 <= n)
        ans = min(ans, (abs(x2 - x1) - 1) / v + 1 +
                           min(abs(y1 - e[k2]) + abs(y2 - e[k2]),
                               abs(y1 - e[k2 - 1]) + abs(y2 - e[k2 - 1])));
      else
        ans = min(ans, (abs(x2 - x1) - 1) / v + 1 + abs(y1 - e[k2 - 1]) +
                           abs(y2 - e[k2 - 1]));
    }
    k1 = lower_bound(l + 1, l + nl + 1, y2) - l;
    k2 = lower_bound(e + 1, e + ne + 1, y2) - e;
    if (nl != 0) {
      if (k1 == 1)
        ans = min(ans, abs(x2 - x1) + abs(y1 - l[k1]) + abs(y2 - l[k1]));
      else if (k1 > 1 && k1 <= n)
        ans = min(
            ans, abs(x2 - x1) + min(abs(y1 - l[k1]) + abs(y2 - l[k1]),
                                    abs(y1 - l[k1 - 1]) + abs(y2 - l[k1 - 1])));
      else
        ans =
            min(ans, abs(x2 - x1) + abs(y1 - l[k1 - 1]) + abs(y2 - l[k1 - 1]));
    }
    if (ne != 0) {
      if (k2 == 1)
        ans = min(ans, (abs(x2 - x1) - 1) / v + 1 + abs(y1 - e[k2]) +
                           abs(y2 - e[k2]));
      else if (k2 > 1 && k2 <= n)
        ans = min(ans, (abs(x2 - x1) - 1) / v + 1 +
                           min(abs(y1 - e[k2]) + abs(y2 - e[k2]),
                               abs(y1 - e[k2 - 1]) + abs(y2 - e[k2 - 1])));
      else
        ans = min(ans, (abs(x2 - x1) - 1) / v + 1 + abs(y1 - e[k2 - 1]) +
                           abs(y2 - e[k2 - 1]));
    }
    if (x1 == x2) ans = min(ans, abs(y2 - y1));
    printf("%d\n", ans);
  }
}
