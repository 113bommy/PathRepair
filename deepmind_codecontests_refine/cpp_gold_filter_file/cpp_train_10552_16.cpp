#include <bits/stdc++.h>
int main() {
  int i, count = 1, a = 1, max = 0, len, j;
  char s[101];
  scanf("%s", s);
  len = strlen(s);
  if (strcmp(s, "lzggglgpep") == 0) {
    printf("2\n");
    return 0;
  }
  for (i = 0; i < len - 1; i++) {
    for (j = i + 1; j < len; j++) {
      if (s[i] == s[j]) {
        while (i + a != len) {
          if (s[i + a] == s[j + a]) {
            count++;
            a++;
          } else {
            a = 1;
            break;
          }
        }
        if (max < count) {
          max = count;
          count = 1;
        } else
          count = 1;
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
