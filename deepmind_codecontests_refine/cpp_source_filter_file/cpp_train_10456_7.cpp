#include <bits/stdc++.h>
int main(void) {
  int n, m;
  char mi[100][110];
  scanf("%i %i\n", &n, &m);
  int i, j;
  for (i = 0; i < n; i++) fgets(mi[i], 100, stdin);
  if ((n % 2) == 1) {
    printf("%i\n", n);
    return 0;
  }
  for (i = 1; i < n; i++)
    if (strcmp(mi[i], mi[0])) break;
  if (i == n) {
    int k = 1;
    for (k = 1; k <= 10; k++)
      if (pow(2, k) == n) {
        printf("1\n");
        return 0;
      }
  }
  while ((n % 2) == 0) {
    for (i = 0, j = n - 1; i < j; i++, j--)
      if (strcmp(mi[i], mi[j])) {
        printf("%i\n", n);
        return 0;
      }
    n /= 2;
  }
  printf("%i\n", n);
  return 0;
}
