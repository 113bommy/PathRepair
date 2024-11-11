#include <bits/stdc++.h>
char store[1048576];
int main() {
  char input;
  int count_space = 0, flag = 0, i, c = 0;
  while (~scanf("%c", &input)) {
    if (input == ' ' && flag == 0) {
      count_space++;
    } else if (input == '#' && flag == 0) {
      if (c != 0) {
        store[c] = '\0';
        printf("%s", store);
        c = 0;
      }
      for (i = 0; i < count_space; i++) {
        printf(" ");
      }
      printf("#");
      while (~scanf("%c", &input)) {
        if (input != '\n') {
          printf("%c", input);
        } else {
          printf("\n");
          break;
        }
      }
      count_space = 0;
    } else {
      flag = 1;
      count_space = 0;
      if (store[c - 1] == '\n') {
        c--;
      }
      if (input == ' ') {
        ;
      } else if (input == '\n') {
        store[c++] = input;
        flag = 0;
      } else {
        store[c++] = input;
      }
    }
  }
  store[c] = '\0';
  if (c != 0) {
    printf("%s\n", store);
  }
  scanf(" ");
  return 0;
}
