#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  char str[n][100];
  char abreviation[5] = {0};
  for (int i = 0; i < n; i++) scanf("%s", str[i]);
  for (int i = 0; i < n; i++) {
    if (strlen(str[i]) > 10) {
      abreviation[0] = str[i][0];
      char num[3] = {0};
      sprintf(num, "%d", strlen(str[i]) - 2);
      strcat(abreviation, num);
      strncat(abreviation, &str[i][strlen(str[i]) - 1], 1);
      printf("%s\n", abreviation);
    } else
      printf("%s\n", str[i]);
    memset(abreviation, 0, sizeof(abreviation));
  }
  return 0;
}
