#include <bits/stdc++.h>
int main() {
  char s1[100], s2[100];
  int i, n;
  scanf("%s", s1);
  scanf("%s", s2);
  n = strlen(s1);
  for (i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      printf("0");
    } else {
      printf("1");
    }
  }
  return 0;
}
