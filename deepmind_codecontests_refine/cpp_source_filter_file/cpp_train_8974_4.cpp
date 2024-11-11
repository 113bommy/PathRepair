#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  int i, j;
  int n;
  int a[200005];
  int li[200005], ri[20005], m = 100000;
  int v;
  int ans;
  for (j = 0; j < t; j++) {
    scanf("%d", &n);
    for (i = 0; i < 2 * n; i++) scanf("%d", &a[i]);
    for (i = 0; i < 200005; i++) li[i] = ri[i] = -10;
    v = 0;
    li[m] = -1;
    for (i = 0; i < n; i++) {
      if (a[i] == 1)
        v++;
      else
        v--;
      li[v + m] = i;
    }
    v = 0;
    ri[m] = 2 * n;
    for (i = 2 * n - 1; i >= n; i--) {
      if (a[i] == 2)
        v++;
      else
        v--;
      ri[v + m] = i;
    }
    ans = 2 * n;
    for (i = 0; i < 200005; i++)
      if (li[i] >= -5 && ri[i] >= -5 && ans > ri[i] - li[i] - 1)
        ans = ri[i] - li[i] - 1;
    printf("%d\n", ans);
  }
  return 0;
}
