#include <bits/stdc++.h>
int main() {
  char s[110];
  while (scanf("%s", s) != EOF) {
    int l = strlen(s);
    if (l < 3 || l == 3 && strcmp(s, "127") <= 0 || strcmp(s, "-128") <= 0)
      printf("byte\n");
    else if (l < 5 || l == 5 && strcmp(s, "32767") <= 0 ||
             strcmp(s, "-32768") <= 0)
      printf("short\n");
    else if (l < 9 || l == 9 && strcmp(s, "2147483647") <= 0 ||
             strcmp(s, "-2147483648") <= 0)
      printf("int\n");
    else if (l < 19 || l == 19 && strcmp(s, "9223372036854775807") <= 0 ||
             strcmp(s, "-9223372036854775808") <= 0)
      printf("long\n");
    else
      printf("BigInteger\n");
  }
  return 0;
}
