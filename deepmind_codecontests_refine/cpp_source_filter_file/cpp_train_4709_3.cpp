#include <bits/stdc++.h>
int main() {
  int l = 0, u = 0;
  char input[120];
  scanf("%s", &input);
  for (int i = 0; i < strlen(input); i++) {
    if (islower(input[i]) != 0)
      l++;
    else
      u++;
  }
  if (l && !u)
    printf("%c", toupper(input[0]));
  else if (l == 1 && u > l && islower(input[0]))
    for (int j = 0; j < strlen(input); j++) {
      if (islower(input[j]) != 0)
        printf("%c", toupper(input[j]));
      else
        printf("%c", tolower(input[j]));
    }
  else if (!l)
    for (int j = 0; j < strlen(input); j++) {
      printf("%c", tolower(input[j]));
    }
  else
    printf("%s", input);
  return 0;
}
