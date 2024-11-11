#include <bits/stdc++.h>
int main() {
  char nlog[50], log[50];
  int i, j, n;
  scanf("%s", nlog);
  for (i = 0; nlog[i] != '\0'; i++) {
    if (nlog[i] == 'o' || nlog[i] == 'O') {
      nlog[i] = '0';
    } else if (nlog[i] == 'L' || nlog[i] == 'I' || nlog[i] == 'i' ||
               nlog[i] == 'l') {
      nlog[i] = '1';
    }
  }
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", log);
    for (j = 0; log[j] != '\0'; j++) {
      if (log[j] == 'o' || log[j] == 'O') {
        log[j] = '0';
      } else if (log[j] == 'L' || log[j] == 'I' || log[j] == 'i' ||
                 log[j] == 'l') {
        log[j] = '1';
      }
    }
    if (strcasecmp(nlog, log) == 0) {
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
}
