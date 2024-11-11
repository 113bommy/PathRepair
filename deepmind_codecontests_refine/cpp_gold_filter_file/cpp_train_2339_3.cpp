#include <bits/stdc++.h>
char str[3][11], name[4] = "FMS";
bool judge(char *s, char *t) {
  if (!strcmp(s, "rock") && !strcmp(t, "scissors")) return true;
  if (!strcmp(s, "scissors") && !strcmp(t, "paper")) return true;
  if (!strcmp(s, "paper") && !strcmp(t, "rock")) return true;
  return false;
}
int main() {
  int i, j;
  for (i = 0; i < 3; i++) scanf("%s", str[i]);
  for (i = 0; i < 3; i++) {
    int cnt = 0;
    for (j = 0; j < 3; j++) {
      if (i != j && judge(str[i], str[j])) cnt++;
    }
    if (cnt == 2) {
      printf("%c\n", name[i]);
      return 0;
    }
  }
  printf("?\n");
  return 0;
}
