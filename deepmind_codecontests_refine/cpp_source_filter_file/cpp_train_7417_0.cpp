#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char s[1001];
    scanf("%s", s);
    if (strlen(s) == 2) {
      printf("%s", s);
      printf("\n");
    } else {
      for (int i = 0; i <= strlen(s) - 2; i = i + 2) {
        printf("%c", s[i]);
      }
      printf("%c", s[strlen(s) - 1]);
      printf("/n");
    }
  }
}
