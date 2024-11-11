#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1000005], b[1000005];
int mi[1 << 20], mx[1 << 20], p[30], cs1[30], cs2[30], dp1[1 << 20],
    dp2[1 << 20], cs = 0;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) scanf("%1d", &cs1[i]);
  for (int i = 1; i <= k; ++i) scanf("%1d", &cs2[i]);
  for (int i = 1; i <= k; ++i) cs -= cs1[i] + cs2[i];
  cs += k;
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
  memset(mi, 63, sizeof(mi));
  memset(mx, -63, sizeof(mx));
  for (int i = 1; i <= k; ++i) p[i] = i;
  int tp = 0;
  for (int i = 1; i <= k; ++i) tp |= cs2[i] << (i - 1);
  mx[tp] = max(mx[tp], n + 1);
  for (int i = n; i >= 1; --i) {
    int p1 = 0, p2 = 0;
    for (int j = 1; j <= k; ++j)
      if (p[j] == a[i] || p[j] == b[i]) p2 = p1, p1 = j;
    swap(p[p1], p[p2]);
    int w1 = 0, w2 = 0;
    for (int j = 1; j <= k; ++j)
      w1 |= cs1[p[j]] << (j - 1), w2 |= cs2[p[j]] << (j - 1);
    mi[w1] = min(mi[w1], i);
    mx[w2] = max(mx[w2], i);
  }
  int len = 1 << k, ans = 0, l = 0, r = 0;
  for (int i = len - 1; i >= 0; --i) {
    dp1[i] = mi[i];
    dp2[i] = mx[i];
    int sz = 0;
    for (int j = 0; j < k; ++j) {
      if (!((1 << j) & i))
        ((dp1[i] > dp1[i | (1 << j)]) && (dp1[i] = dp1[i | (1 << j)])),
            ((dp2[i] < dp2[i | (1 << j)]) && (dp2[i] = dp2[i | (1 << j)]));
      else
        ++sz;
    }
    if (dp2[i] - dp1[i] >= m && 2 * sz + cs >= ans)
      ans = 2 * sz + cs, l = dp1[i], r = dp2[i] - 1;
  }
  printf("%d\n", ans);
  printf("%d %d\n", l, r);
}
