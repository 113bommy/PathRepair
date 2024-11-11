#include <bits/stdc++.h>
int main() {
  char test[101];
  char out[201] = {'.'};
  scanf("%s", test);
  int i = strlen(test);
  int j;
  int k;
  k = 0;
  for (j = 0; j <= i; j++) {
    switch (test[j]) {
      case 'b':
      case 'B':
        out[k] = '.';
        out[k + 1] = 'b';
        k = k + 2;
        break;
      case 'c':
      case 'C':
        out[k] = '.';
        out[k + 1] = 'c';
        k = k + 2;
        break;
      case 'd':
      case 'D':
        out[k] = '.';
        out[k + 1] = 'd';
        k = k + 2;
        break;
      case 'f':
      case 'F':
        out[k] = '.';
        out[k + 1] = 'f';
        k = k + 2;
        break;
      case 'g':
      case 'G':
        out[k] = '.';
        out[k + 1] = 'G';
        k = k + 2;
        break;
      case 'h':
      case 'H':
        out[k] = '.';
        out[k + 1] = 'h';
        k = k + 2;
        break;
      case 'j':
      case 'J':
        out[k] = '.';
        out[k + 1] = 'b';
        k = k + 2;
        break;
      case 'k':
      case 'K':
        out[k] = '.';
        out[k + 1] = 'k';
        k = k + 2;
        break;
      case 'l':
      case 'L':
        out[k] = '.';
        out[k + 1] = 'l';
        k = k + 2;
        break;
      case 'm':
      case 'M':
        out[k] = '.';
        out[k + 1] = 'm';
        k = k + 2;
        break;
      case 'n':
      case 'N':
        out[k] = '.';
        out[k + 1] = 'n';
        k = k + 2;
        break;
      case 'p':
      case 'P':
        out[k] = '.';
        out[k + 1] = 'p';
        k = k + 2;
        break;
      case 'q':
      case 'Q':
        out[k] = '.';
        out[k + 1] = 'q';
        k = k + 2;
        break;
      case 'r':
      case 'R':
        out[k] = '.';
        out[k + 1] = 'r';
        k = k + 2;
        break;
      case 's':
      case 'S':
        out[k] = '.';
        out[k + 1] = 's';
        k = k + 2;
        break;
      case 't':
      case 'T':
        out[k] = '.';
        out[k + 1] = 't';
        k = k + 2;
        break;
      case 'v':
      case 'V':
        out[k] = '.';
        out[k + 1] = 'v';
        k = k + 2;
        break;
      case 'w':
      case 'W':
        out[k] = '.';
        out[k + 1] = 'w';
        k = k + 2;
        break;
      case 'x':
      case 'X':
        out[k] = '.';
        out[k + 1] = 'x';
        k = k + 2;
        break;
      case 'z':
      case 'Z':
        out[k] = '.';
        out[k + 1] = 'z';
        k = k + 2;
        break;
      default: {
        out[k] = ' ';
      }
    }
  }
  printf("%s", out);
  return 0;
}
