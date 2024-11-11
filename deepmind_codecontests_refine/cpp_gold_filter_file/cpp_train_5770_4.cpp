#include <bits/stdc++.h>
int main() {
  int n, k, l, r, sa, sk;
  int i, j;
  int num[1010];
  int temp;
  while (scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sa, &sk) == 6) {
    j = 1;
    temp = sk / k;
    for (i = 1; i <= sk - sk / k * k; i++) {
      num[j++] = temp + 1;
    }
    for (; i <= k; i++) {
      num[j++] = temp;
    }
    if (k < n) {
      temp = (sa - sk) / (n - k);
      for (i = 1; i <= (sa - sk) - temp * (n - k); i++) {
        num[j++] = temp + 1;
      }
      for (; i <= n - k; i++) {
        num[j++] = temp;
      }
    }
    for (i = 1; i <= n; i++) {
      printf("%d ", num[i]);
    }
    printf("\n");
  }
  return 0;
}
