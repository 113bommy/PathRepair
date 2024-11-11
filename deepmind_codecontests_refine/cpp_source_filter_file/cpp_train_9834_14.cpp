#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  char x = 'O', y = '.';
  char s1[11];
  char s2[11];
  char s3[11];
  char s5[11];
  scanf("%d", &n);
  for (i = 0; i < 11; i++) {
    s1[i] = '#';
    s2[i] = '#';
    s3[i] = '#';
    s5[i] = '.';
  }
  if (n > 2)
    s5[0] = 'O';
  else
    s5[0] = '#';
  int q = 1, w = 2, e = 4, r, f = 0, f1 = 0, f2 = 0, nn = n;
  for (i = 0; i < 11; i++) {
    if (n >= q) {
      s1[i] = x;
      if (f == 0) {
        q += 4;
        f = 1;
      } else {
        q += 3;
      }
    } else
      break;
  }
  for (i = 0; i < 11; i++) {
    if (n >= w) {
      s2[i] = x;
      if (f1 == 0) {
        w += 4;
        f1 = 1;
      } else {
        w += 3;
      }
    } else
      break;
  }
  for (i = 0; i < 11; i++) {
    if (n >= e) {
      s3[i] = x;
      e += 3;
    } else
      break;
  }
  printf("+------------------------+\n");
  printf("|");
  for (i = 0; i < 11; i++) printf("%c.", s1[i]);
  printf("|D|)\n");
  printf("|");
  for (i = 0; i < 11; i++) printf("%c.", s2[i]);
  printf("|D|\n");
  printf("|");
  for (i = 0; i < 11; i++) printf("%c.", s5[i]);
  printf("|D|\n");
  printf("|");
  for (i = 0; i < 11; i++) printf("%c.", s3[i]);
  printf("|D|)\n");
  printf("+------------------------+\n");
  return 0;
}
