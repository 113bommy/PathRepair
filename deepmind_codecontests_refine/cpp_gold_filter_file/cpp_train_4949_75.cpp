#include <bits/stdc++.h>
int main() {
  char s1[1001], s2[1001];
  int a;
  scanf("%s %s", s1, s2);
  a = strcmp(s1, s2);
  if (a == 0) {
    printf(s1);
  } else {
    printf("1\n");
  }
}
