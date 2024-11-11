#include <bits/stdc++.h>
int main() {
  char buf[101];
  char result[110];
  scanf("%s", buf);
  int i = 0;
  int j = 0;
  int count = 0;
  for (int k = 0; buf[k] != '\0'; k++) count++;
  bool flag = false;
  while (i < count) {
    if (i > 0 && i < count - 2 && flag == false) {
      if (buf[i] == 'a' && buf[i + 1] == 't') {
        result[j] = '@';
        printf("@");
        flag = true;
        j++;
        i += 2;
        continue;
      }
    }
    if (i > 0 && i < count - 3) {
      if (buf[i] == 'd' && buf[i + 1] == 'o' && buf[i + 2] == 't') {
        result[j] = '.';
        printf(".");
        j++;
        i += 3;
        continue;
      }
    }
    result[j++] = buf[i++];
    printf("%c", result[j - 1]);
  }
  printf("\n");
  return 0;
}
