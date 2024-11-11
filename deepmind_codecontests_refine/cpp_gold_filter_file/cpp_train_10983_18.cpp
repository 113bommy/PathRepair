#include <bits/stdc++.h>
int main() {
  char s[100];
  gets(s);
  int i, no_up = 0, no_low = 0, len = strlen(s);
  for (i = 0; i < len; i++) {
    if (s[i] >= 65 && s[i] <= 90) {
      no_up++;
    } else {
      no_low++;
    }
  }
  if (no_up > no_low) {
    for (i = 0; i < len; i++) {
      if (s[i] >= 97 && s[i] <= 122) {
        s[i] = s[i] - 32;
      }
      printf("%c", s[i]);
    }
  } else {
    for (i = 0; i < len; i++) {
      if (s[i] >= 65 && s[i] <= 90) {
        s[i] = s[i] + 32;
      }
      printf("%c", s[i]);
    }
  }
  printf("\n");
  return 0;
}
