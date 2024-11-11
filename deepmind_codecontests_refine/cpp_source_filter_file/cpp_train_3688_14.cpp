#include <bits/stdc++.h>
int main() {
  int n, d[110], i, a, b, sum;
  while (scanf("%d", &n) != EOF) {
    sum = 0;
    for (i = 0; i < n - 1; i++) {
      scanf("%d", &d[i]);
    }
    scanf("%d%d", &a, &b);
    for (i = 0; i < b - a; i++) {
      sum = sum + d[i];
    }
    printf("%d\n", sum);
  }
  return 0;
}
