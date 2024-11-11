#include <bits/stdc++.h>
int main() {
  int n, k, a[100005] = {0};
  scanf("%d %d", &n, &k);
  int i, j;
  for (i = 1, j = k + 1; j > i; i++) {
    printf("%d %d ", i, j);
    a[i]++;
    a[j]++;
    j--;
    i++;
  }
  for (i = 1; i <= n; i++)
    if (a[i] == 0) printf("%d ", i);
  return 0;
}
