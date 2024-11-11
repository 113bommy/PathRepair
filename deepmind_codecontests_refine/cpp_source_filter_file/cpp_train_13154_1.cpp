#include <bits/stdc++.h>
int main() {
  char ch[100];
  int i, n, s = 0, j;
  scanf("%s", ch);
  n = strlen(ch);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (ch[j] == ch[i]) {
        s += 1;
        break;
      }
    }
  }
  if (((n - s) % 2) == 0)
    printf("CHAT WITH HER!");
  else
    printf("IGNORE HIM !");
  return 0;
}
