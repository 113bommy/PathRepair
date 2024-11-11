#include <bits/stdc++.h>
int main() {
  char s1[100], i, a, count = 0, len;
  gets(s1);
  len = strlen(s1);
  for (i = 0; i < len; i++) {
    if (s1[i] == 'a') {
      count++;
    }
  }
  if (!(len & 1)) {
    if (count == 1) {
      printf("1");
      return 0;
    }
    if (count < (len / 2)) {
      printf("%d", count * 2 + 1);
    } else if (count == len / 2) {
      printf("%d", len - 1);
    } else {
      printf("%d", len);
    }
  } else {
    if (count > len / 2) {
      printf("%d", len);
    } else {
      printf("%d", (2 * count) - 1);
    }
  }
  return 0;
  return 0;
}
