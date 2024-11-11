#include <bits/stdc++.h>
int d[5002], mx[5002];
int a[5002];
int id[5002], l[5002], r[5002], p[5002];
int main() {
  int n, m, i, j, Max;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) mx[i] = 1000000007;
  for (i = 0; i < m; i++) {
    scanf("%d %d %d %d", id + i, l + i, r + i, p + i);
    if (id[i] == 1) {
      for (j = l[i]; j <= r[i]; j++) d[j] += p[i];
    } else {
      for (j = l[i]; j <= r[i]; j++) {
        mx[j] = ((mx[j]) < (p[i] - d[j]) ? (mx[j]) : (p[i] - d[j]));
      }
    }
  }
  for (i = 1; i <= n; i++) a[i] = mx[i];
  for (i = 0; i < m; i++) {
    if (id[i] == 1) {
      for (j = l[i]; j <= r[i]; j++) a[j] += p[i];
    } else {
      Max = -1000000007;
      for (j = l[i]; j <= r[i]; j++) Max = ((a[j]) > (Max) ? (a[j]) : (Max));
      if (Max != p[i]) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for (i = 1; i <= n; i++) printf("%d%s", mx[i], (i == n) ? "\n" : " ");
}
