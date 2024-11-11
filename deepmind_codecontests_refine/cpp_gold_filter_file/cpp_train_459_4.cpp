#include <bits/stdc++.h>
int min(int h, int j) {
  if (h < j)
    return h;
  else
    return j;
}
int main() {
  int n, m, arr[1000], i, j, sum = 0, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (k = 0; k < m; k++) {
    scanf("%d%d", &i, &j);
    sum = sum + min(arr[i - 1], arr[j - 1]);
  }
  printf("%d\n", sum);
  return 0;
}
