#include <bits/stdc++.h>
int main() {
  int i, j, flag = 0;
  char ch1[101], ch2[101];
  scanf("%s %s", ch1, ch2);
  for (i = 0, j = strlen(ch1) - 1; i < strlen(ch1); i++, j--) {
    if (ch1[i] != ch2[j]) flag = 1;
  }
  if (flag == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
