#include <bits/stdc++.h>
int a[1000];
int main() {
  int n, m;
  scanf("%d", &n);
  m = n * 2 - 1;
  int ans = 0, tmp = 1000;
  int num = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", a + i);
    if (a[i] < 0) {
      a[i] = -a[i];
      ++num;
    }
    ans += a[i];
    if (a[i] < tmp) tmp = a[i];
  }
  if (n & 1 || num % 2 == 0)
    printf("%d\n", ans);
  else
    printf("%d\n", ans - tmp - tmp);
  return 0;
}
