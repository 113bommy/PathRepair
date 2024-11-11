#include <bits/stdc++.h>
int main() {
  int sum = 0;
  for (int i = 0; i < 7; i++) {
    char ch = getchar();
    switch (ch) {
      case 'A':
        sum += 1;
        break;
      case '1':
        sum += 10;
        break;
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '0':
        sum += ch - '0';
        break;
    }
  }
  printf("%d\n", sum);
}
