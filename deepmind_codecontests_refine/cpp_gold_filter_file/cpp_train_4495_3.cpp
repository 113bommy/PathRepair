#include <bits/stdc++.h>
int main() {
  int len, i;
  char input[100];
  scanf("%s", input);
  len = strlen(input);
  for (i = 0; i < len; i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] = input[i] - 'A' + 'a';
    }
  }
  for (i = 0; i < len; i++) {
    if (input[i] == 'a' || input[i] == 'y' || input[i] == 'o' ||
        input[i] == 'e' || input[i] == 'u' || input[i] == 'i') {
      input[i] = ',';
    }
  }
  for (i = 0; i < len; i++) {
    if (input[i] != ',') {
      printf(".%c", input[i]);
    }
  }
}
