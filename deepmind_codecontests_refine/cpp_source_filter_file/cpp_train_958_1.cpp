#include <bits/stdc++.h>
int main() {
  char a[12], m[12], c, r[12];
  int i, j, count = 0;
  gets(a);
  gets(m);
  for (i = 0; a[i + 1] != '\0'; i++) {
    for (j = i + 1; a[j] != '\0'; j++) {
      if (a[i] > a[j]) {
        c = a[i];
        a[i] = a[j];
        a[j] = c;
      }
    }
  }
  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] != 48) {
      goto proceed;
    }
  }
  if (strcmp(a, m) == 0) {
    printf("YES");
  } else {
    printf("WRONG_ANSWER");
  }
  goto end;
proceed:
  r[0] = a[i];
  for (j = 0; a[j] != '\0'; j++) {
    if (i == j) {
      count++;
    } else {
      if (count == 0) {
        r[j + 1] = a[j];
      } else {
        r[j] = a[j];
      }
    }
  }
  r[j] = '\0';
  if (strcmp(r, m) == 0) {
    printf("OK");
  } else {
    printf("WRONG_ANSWER");
  }
end:
  return (0);
}
