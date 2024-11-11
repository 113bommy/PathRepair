#include <bits/stdc++.h>
char c_num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char int2char(int num) { return c_num[num]; }
int main(int argc, char *argv[]) {
  char ec_string[81];
  char code[10][10];
  char answer[8] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
  int i;
  for (i = 0; i <= 10; i++) {
    if (i == 0) {
      scanf("%s", ec_string);
    } else {
      scanf("%s", code[i - 1]);
    }
  }
  int j, k;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 8; j++) {
      if (answer[j] == 'a') {
        int credit = 0;
        for (k = 0; k < 10; k++) {
          if (ec_string[j * 10 + k] == code[i][k]) {
            credit++;
          }
        }
        if (credit == 10) {
          answer[j] = int2char(i);
        }
      }
    }
  }
  for (i = 0; i < 8; i++) {
    printf("%c", answer[i]);
  }
  return 0;
}
