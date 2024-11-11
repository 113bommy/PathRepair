#include <bits/stdc++.h>
int syllable() {
  int a;
  int res = 0;
  while ((a = getchar()) != '\n') {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') res++;
  }
  return res;
}
int main() {
  if (syllable() != 5) {
    printf("NO\n");
    return 0;
  }
  if (syllable() != 7) {
    printf("NO\n");
    return 0;
  }
  if (syllable() != 5) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  return 0;
}
