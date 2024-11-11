#include <bits/stdc++.h>
int main(void) {
  int t;
  scanf("%d", &t);
  int el[] = {1, 2, 3, 4, 6, 12};
  int a[6];
  int count;
  int sum;
  size_t j, k, m, n;
  for (size_t i = 0; i < t; i++) {
    char s[13];
    scanf("%s", s);
    count = 0;
    for (j = 0; j < 6; j++) {
      n = 12 / el[j];
      for (k = 0; k < n; k++) {
        sum = 0;
        for (m = k; m < 12; m += n) sum += s[m] == 'X';
        if (sum >= el[j]) {
          a[count++] = el[j];
          goto label;
        }
      }
    label:;
    }
    printf("%d ", count);
    for (j = 0; j < count; j++) printf("%dx%d ", a[j], 12 / a[j]);
    putchar('\n');
  }
  return 0;
}
