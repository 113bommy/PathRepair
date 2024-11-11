#include <bits/stdc++.h>
int main(void) {
  int n, kb = 0, kc, k, cur, i = 0;
  int a[1000000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  while (a[i] == a[0]) i++;
  cur = a[0];
  int j = i;
  while (j < n) {
    if ((n - j) % i != 0) {
      printf("NO");
      return 0;
    }
    for (int k = j; k < j + i; k++)
      if (a[k] != (cur + 1) % 2) {
        printf("NO1");
        return 0;
      }
    j += i;
    cur = (cur + 1) % 2;
  }
  printf("YES");
  return 0;
}
