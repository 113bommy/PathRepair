#include <bits/stdc++.h>
int main() {
  int a[100005];
  int c[100005][2] = {0};
  int i, j;
  int ans = 0;
  int n;
  int k;
  int x;
  scanf("%d %d", &n, &k);
  memset(a, 1, sizeof(a));
  for (i = 1; i <= n; i++) {
    c[i][0] = k + 1;
  }
  a[0] = 0;
  a[n] = 0;
  for (i = 1; i <= k; i++) {
    scanf("%d", &x);
    a[x] = 0;
    c[x][1] = i;
    if (i < c[x][0]) {
      c[x][0] = i;
    }
  }
  for (i = 1; i <= n; i++) {
    if (a[i]) {
      ans++;
      if (i - 1 >= 1) {
        ans++;
      }
      if (i + 1 <= n) {
        ans++;
      }
    } else {
      if (c[i - 1][1] < c[i][0] && i - 1 >= 1) {
        ans++;
      }
      if (c[i + 1][1] < c[i][0] && i + 1 <= n) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
