#include <bits/stdc++.h>
int main() {
  long long max1[2001] = {0}, max2[2001] = {0};
  long long a[2001], b[2001], res = 0;
  int i, j;
  int n, m;
  a[0] = 0;
  b[0] = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    a[i] += a[i - 1];
    for (j = i; j > 0; j--) {
      if (max1[i - j + 1] == 0 || max1[i - j + 1] > a[i] - a[j - 1]) {
        max1[i - j + 1] = a[i] - a[j - 1];
      }
    }
  }
  for (i = 1; i <= n; i++) {
    scanf("%lld", b + i);
    b[i] += b[i - 1];
    for (j = i; j > 0; j--) {
      if (max2[i - j + 1] == 0 || max2[i - j + 1] > b[i] - b[j - 1]) {
        max2[i - j + 1] = b[i] - b[j - 1];
      }
    }
  }
  int x;
  scanf("%d", &x);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (max1[i] * max2[j] <= x && (i * j) > res) res = i * j;
    }
  }
  printf("%lld", res);
}
