#include <bits/stdc++.h>
using namespace std;
int n, m, c, k, d, mi = 1, pu = 0;
int ans[10009];
int f = 0;
int main() {
  scanf("%d %d %d", &n, &m, &c);
  if (n % 2 == 1) f = 1;
  if (c * (n / 2 + f) - (n / 2) < m || (n / 2 + f) - (n / 2) * c > m) {
    printf("-1");
    return 0;
  }
  for (int h = 0; h < n; h++) ans[h] = 1;
  ans[1] += f;
  d = m;
  if (m > 0) {
    ans[1]--;
    d++;
  }
  if (m < 0) d *= -1;
  if (m > 0) {
    while (d != 0) {
      int an = ans[pu];
      if (d <= c - ans[pu]) {
        ans[pu] += d;
        d = 0;
      } else {
        ans[pu] += c - an;
        d -= (c - an);
      }
      pu += 2;
    }
  } else if (m != 0) {
    while (d != 0) {
      int an = ans[mi];
      if (d <= (c - ans[mi])) {
        ans[mi] += d;
        d = 0;
      } else {
        ans[mi] += (c - an);
        d -= (c - an);
      }
      mi += 2;
    }
  }
  for (int h = 0; h < n - 1; h++) printf("%d ", ans[h]);
  printf("%d", ans[n - 1]);
}
