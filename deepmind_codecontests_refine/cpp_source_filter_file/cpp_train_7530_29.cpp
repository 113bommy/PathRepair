#include <bits/stdc++.h>
int main(void) {
  char str[100002], c = 'a' - 1, bet[32] = "abcdefghijklmnopqrstuvwxwz";
  int i, j, maxnum, l, count, start;
  scanf("%s%*c", str);
  l = strlen(str);
  for (i = 0; i < l; i++) {
    if (str[i] > c) {
      c = str[i];
    }
  }
  start = 0;
  for (i = c - 'a'; i >= 0; i--, c--) {
    count = 0;
    for (j = start; j < l; j++)
      if (str[j] == bet[i]) {
        count++;
        start = j;
      }
    for (j = 0; j < count; j++) putchar(c);
  }
  putchar('\n');
  return 0;
}
