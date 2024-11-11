#include <bits/stdc++.h>
void reverse(char s[100]) {
  int i, l = strlen(s);
  char temp;
  for (i = 0; i < l / 2; i++) {
    temp = s[i];
    s[i] = s[l - 1 - i];
    s[l - 1 - i] = temp;
  }
}
int main() {
  char ber[107], bir[107];
  scanf("%s", &ber);
  getchar();
  scanf("%s", &bir);
  reverse(ber);
  if (strcmp(ber, bir) == 0)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
