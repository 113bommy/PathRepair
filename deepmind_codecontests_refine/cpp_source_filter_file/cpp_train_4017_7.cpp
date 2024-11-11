#include <bits/stdc++.h>
int main(void) {
  char str1[100006], str2[100006];
  scanf("%s%s", str1, str2);
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if (len1 != len2) {
    if (len1 > len2)
      printf("%d\n", len1);
    else
      printf("%d\n", len2);
  } else if (strcmp(str1, str2) == 1)
    printf("%d\n", len1);
  else if (strcmp(str1, str2) == 0)
    printf("-1\n");
}
