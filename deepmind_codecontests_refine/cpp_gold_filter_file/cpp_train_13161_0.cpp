#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 1e6 + 5;
char str1[MAXLEN], str2[MAXLEN];
int main(void) {
  fgets(str1, MAXLEN, stdin);
  fgets(str2, MAXLEN, stdin);
  int len = strlen(str2);
  if (str1[0] != str2[0]) {
    bool b = 0;
    for (int i = 0; i < len; i++)
      if (str1[i + 1] != str2[i]) {
        b = 1;
        break;
      }
    if (b)
      putchar('0');
    else
      printf("1\n1");
    return 0;
  }
  int l = 0;
  int r;
  for (r = 1; r <= len; r++) {
    if (str1[r - 1] != str1[r]) l = r;
    if (str1[r] != str2[r]) break;
  }
  for (int i = r; i < len; i++)
    if (str1[i + 1] != str2[i]) {
      putchar('0');
      return 0;
    }
  printf("%d\n", r - l + 1);
  for (int i = l; i <= r; i++) printf("%d ", i + 1);
  return 0;
}
