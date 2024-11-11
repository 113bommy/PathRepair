#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1 || n == 3) {
    printf("-1\n");
    return 0;
  }
  int output[102] = {0}, i, j;
  for (i = 1, j = 1; i <= n;) {
    if (i == j) {
      output[++j] = i;
      output[j - 1] = ++i;
      j++;
    } else
      output[j] = i++;
  }
  for (i = 1; i <= n; i++)
    if (output[i] != 0) printf("%d ", output[i]);
}
