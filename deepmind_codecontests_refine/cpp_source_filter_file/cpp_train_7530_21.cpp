#include <bits/stdc++.h>
char str[100001];
char str1[100001];
int main() {
  int t = -1;
  int i;
  char c = 0;
  scanf("%s", str);
  int len = strlen(str);
  for (i = len; i >= 1; i--) {
    if (str[i] >= c) {
      str1[++t] = str[i];
      c = str[i];
    }
  }
  for (; t >= 1; t--) {
    printf("%c", str1[t]);
  }
  printf("\n");
  return 0;
}
