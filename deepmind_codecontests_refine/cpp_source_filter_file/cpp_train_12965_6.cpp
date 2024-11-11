#include <bits/stdc++.h>
int main() {
  int i, k = 0, f, j;
  int pri[101];
  char s[11];
  for (i = 2; i <= 50; i++) {
    f = 1;
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        f = 0;
        break;
      }
    }
    if (f == 1) pri[k++] = i;
  }
  pri[k++] = 4;
  pri[k++] = 9;
  pri[k++] = 25;
  pri[k++] = 49;
  int cn = 0;
  for (i = 0; i < 20; i++) {
    printf("%d\n", pri[i]);
    fflush(stdout);
    scanf("%s", s);
    if (strcmp(s, "yes") == 0) {
      cn++;
    }
    if (cn >= 2) break;
  }
  if (cn >= 2)
    printf("composite\n");
  else
    printf("prime\n");
  fflush(stdout);
  return 0;
}
