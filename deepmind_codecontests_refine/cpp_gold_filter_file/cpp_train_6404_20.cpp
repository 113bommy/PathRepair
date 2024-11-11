#include <bits/stdc++.h>
int main() {
  int binary1[100];
  int binary2[100];
  char ch;
  int i = 0, n = 0;
  while ((ch = getchar()) != '\n') {
    binary1[i++] = ch - '0';
    n++;
  }
  i = 0;
  while ((ch = getchar()) != '\n') {
    binary2[i++] = ch - '0';
  }
  i = 0;
  while (n--) {
    if (binary1[i] != binary2[i])
      printf("1");
    else
      printf("0");
    ++i;
  }
}
