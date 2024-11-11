#include <bits/stdc++.h>
using namespace std;
int o[100100];
int ans[6000100];
int main() {
  int i, j, n;
  int e = 0;
  long long x, y;
  long long m, tmp, st, ed, mid;
  scanf("%d %I64d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &o[i]);
  sort(o + 1, o + n + 1);
  o[0] = 0;
  o[n + 1] = 1000000001;
  for (i = 0; i <= n; i++) {
    x = o[i] + 1;
    y = o[i + 1] - 1;
    if (x <= y) {
      tmp = ((x + y) * (y - x + 1)) >> 1;
      if (m - tmp >= 0) {
        m -= tmp;
        for (j = x; j <= y; j++) ans[e++] = j;
      } else {
        st = x;
        ed = y;
        while (st < ed) {
          mid = (st + ed) >> 1;
          tmp = ((x + mid) * (mid - x + 1)) >> 1;
          if (tmp <= m)
            st = mid + 1;
          else
            ed = mid;
        }
        st--;
        tmp = 0;
        if (x <= st) {
          tmp = ((x + st) * (st - x + 1)) >> 1;
          m -= tmp;
          for (j = x; j <= st; j++) ans[e++] = j;
        }
      }
    }
  }
  printf("%d\n", e);
  for (i = 0; i < e; i++) printf("%d ", ans[i]);
  return 0;
}
