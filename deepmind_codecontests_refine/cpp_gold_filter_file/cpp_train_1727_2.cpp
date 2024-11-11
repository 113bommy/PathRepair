#include <bits/stdc++.h>
char b[3][32], c[12];
int i, j, n;
int main() {
  gets(c + 1);
  n = strlen(c + 1);
  for (i = 1; i <= n; i++) switch (c[i] - 48) {
      case 1:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 0, b[2][2 * i - 1] = 0,
                     b[2][2 * i] = 0;
        break;
      case 2:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 0, b[2][2 * i - 1] = 1,
                     b[2][2 * i] = 0;
        break;
      case 3:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 1, b[2][2 * i - 1] = 0,
                     b[2][2 * i] = 0;
        break;
      case 4:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 1, b[2][2 * i - 1] = 0,
                     b[2][2 * i] = 1;
        break;
      case 5:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 0, b[2][2 * i - 1] = 0,
                     b[2][2 * i] = 1;
        break;
      case 6:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 1, b[2][2 * i - 1] = 1,
                     b[2][2 * i] = 0;
        break;
      case 7:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 1, b[2][2 * i - 1] = 1,
                     b[2][2 * i] = 1;
        break;
      case 8:
        b[1][2 * i - 1] = 1, b[1][2 * i] = 0, b[2][2 * i - 1] = 1,
                     b[2][2 * i] = 1;
        break;
      case 9:
        b[1][2 * i - 1] = 0, b[1][2 * i] = 1, b[2][2 * i - 1] = 1,
                     b[2][2 * i] = 0;
        break;
      case 0:
        b[1][2 * i - 1] = 0, b[1][2 * i] = 1, b[2][2 * i - 1] = 1,
                     b[2][2 * i] = 1;
        break;
    }
  for (i = 1; i <= 2; i++)
    for (j = 1; j <= 2 * n; j++)
      if (b[i][j] != b[i][2 * n - j + 1]) {
        puts("No");
        return 0;
      }
  puts("Yes");
  return 0;
}
