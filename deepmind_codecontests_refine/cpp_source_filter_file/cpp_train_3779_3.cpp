#include <bits/stdc++.h>
int main() {
  char s1[100], s2[100];
  scanf("%s%s", s1, s2);
  int b1 = 0, b2 = 0, l = strlen(s1);
  for (int i = 0; i < l; i++) {
    if (s1[i] < s2[i])
      b1++;
    else if (s1[i] > s2[i])
      b2++;
  }
  int min = b1, max = b2;
  if (min > b2) {
    min = b2;
    max = b1;
  }
  printf("%i", max);
}
