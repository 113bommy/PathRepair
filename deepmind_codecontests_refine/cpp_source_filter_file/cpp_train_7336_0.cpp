#include <bits/stdc++.h>
int main() {
  char s[101], t[101];
  scanf("%s %s", s, t);
  int x = strlen(s);
  int y = strlen(t);
  s[x - 1]++;
  for (int i = x - 1; i >= 0; i--) {
    if (s[i] == 'z' + 1) {
      s[i] == 'a';
      s[i - 1]++;
    }
  }
  if (strcmp(s, t) == 0) {
    printf("No such string\n");
  } else {
    printf("%s\n", s);
  }
  return 0;
}
