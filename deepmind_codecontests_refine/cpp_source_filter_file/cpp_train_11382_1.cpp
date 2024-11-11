#include <bits/stdc++.h>
int main() {
  char s1[2001], s2[2001];
  int count, mix, i, j, l, l1;
  while (scanf("%s", s1) != EOF) {
    scanf("%s", s2);
    l = strlen(s1);
    l1 = strlen(s2);
    mix = 1000000;
    for (i = -l1; i < l; i++) {
      count = 0;
      for (j = 0; j < strlen(s2); j++) {
        if (s2[j] != s1[j + i] || i < 0 || j + i >= l) {
          count++;
        }
      }
      if (count < mix) {
        mix = count;
      }
    }
    printf("%d\n", mix);
  }
}
