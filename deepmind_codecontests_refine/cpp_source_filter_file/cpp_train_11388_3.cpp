#include <bits/stdc++.h>
int sum[1005];
int main(void) {
  int n, i, x;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    sum[x]++;
  }
  for (i = 0; i <= 1000; i++) {
    if (sum[x] > (n + 1) / 2) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
