#include <bits/stdc++.h>
int main() {
  char s1[100];
  char s2[100];
  int i = 0, d = 0;
  gets(s1);
  gets(s2);
  for (i = 0; s1[i] != '\0'; i++) {
    if (s1[i] == s2[i])
      printf("0");
    else if (s1[i] != s2[i])
      printf("1");
  }
}
