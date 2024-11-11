#include <bits/stdc++.h>
int main() {
  char c = '0';
  int sum = 1, i = 0;
  for (i = 0; i < 2; i++) {
    scanf(" %c", &c);
    switch (c) {
      case '1':
        sum *= 7;
        break;
      case '2':
        sum *= 2;
        break;
      case '3':
        sum *= 3;
        break;
      case '4':
        sum *= 3;
        break;
      case '5':
        sum *= 3;
        break;
      case '6':
        sum *= 2;
        break;
      case '7':
        sum *= 5;
        break;
      case '8':
        sum *= 1;
        break;
      case '9':
        sum *= 2;
        break;
      case '0':
        sum *= 2;
        break;
      default:
        break;
    }
  }
  printf("%d\n", sum);
  return 0;
}
