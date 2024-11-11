#include <bits/stdc++.h>
int main() {
  char s[1000005];
  int i;
  int j;
  int count = 0;
  int prev[1000005];
  int cur = 0;
  int found;
  scanf("%s", s);
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == '<' || s[i] == '(' || s[i] == '{' || s[i] == '[') {
      prev[cur] = i;
      cur++;
    } else if (i > 0) {
      cur--;
      if (s[prev[cur]] == '<' && s[i] == '>')
        cur--;
      else if (s[prev[cur]] == '(' && s[i] == ')')
        cur--;
      else if (s[prev[cur]] == '{' && s[i] == '}')
        cur--;
      else if (s[prev[cur]] == '[' && s[i] == ']')
        cur--;
      else {
        cur--;
        count++;
      }
      cur++;
      s[prev[cur]] = 0;
      s[i] = 0;
      if (cur < 0) cur = 0;
    } else {
      printf("Impossible");
      return 0;
    }
  }
  i--;
  while (i >= 0) {
    if (s[i] != 0) {
      printf("Impossible");
      return 0;
    }
    i--;
  }
  printf("%d", count);
  return 0;
}
