#include <bits/stdc++.h>
int main() {
  int n;
  int i;
  char word[102];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", &word);
    if (strlen(word) > 10) {
      printf("%c%d%c", word[0], strlen(word) - 2, word[strlen(word) - 1]);
    } else
      printf("%s", word);
  }
  return 0;
}
