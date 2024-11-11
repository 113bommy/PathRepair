#include <bits/stdc++.h>
int main() {
  char a[105][30];
  int i, j = 0, k, m, n, s[30] = {0}, x[30] = {0}, sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
    j = a[i][0] - 97;
    s[j]++;
  }
  for (i = 0; i < 26; i++) {
    if (s[i] >= 2) {
      x[i] += s[i] / 2;
      s[i] -= x[i];
    }
  }
  for (i = 0; i < 26; i++) {
    if (s[i] > 0) {
      sum += (s[i] - 1) * s[i] / 2;
    }
    if (x[i] > 0) {
      sum += (x[i] - 1) * x[i] / 2;
    }
  }
  printf("%d\n", sum);
}
