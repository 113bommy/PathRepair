#include <bits/stdc++.h>
int a[300010];
int main() {
  int n, c, k;
  scanf("%d", &n);
  printf("1 ");
  k = n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c);
    a[c]++;
    for (int j = k; j >= 1; --j) {
      if (a[j] == 0) {
        k = j;
        break;
      }
    }
    if (i != n)
      printf("%d ", i - n + k + 1);
    else
      printf("1\n");
  }
}
