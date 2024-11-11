#include <bits/stdc++.h>
int main() {
  char ch[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'},
       arr[101], c;
  int i, len = 0, j;
  for (i = 0; i < 100; i++) arr[i] = '1';
  i = 0;
  while ((c = getchar()) != '\n') {
    arr[i++] = c;
    len++;
  }
  i = len - 1;
  while (i != 0) {
    if (arr[i] != ' ' && arr[i] != '?') {
      for (j = 0; j < 12; j++) {
        if (arr[i] == ch[j]) {
          printf("YES");
          return 0;
        }
      }
      printf("NO");
      return 0;
    }
    i--;
  }
  return 0;
}
