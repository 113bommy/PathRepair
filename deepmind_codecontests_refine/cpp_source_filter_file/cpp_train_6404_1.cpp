#include <bits/stdc++.h>
int main() {
  char s1[100], s2[100];
  scanf("%s", s1);
  scanf("%s", s2);
  for (int i = 0; i < strlen(s1); i++) {
    if (s1[i] == s2[i])
      printf("0");
    else
      printf("1");
  }
  return 0;
}
