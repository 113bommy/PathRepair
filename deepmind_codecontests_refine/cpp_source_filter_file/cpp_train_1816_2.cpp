#include <bits/stdc++.h>
int main() {
  char input[100001];
  int i, len, flag = 0;
  scanf("%s", input);
  len = strlen(input);
  for (i = 0; i < len / 2; i++) {
    if (input[i] != input[len - i]) {
      flag = 1;
      break;
    }
    if (!(input[i] == 'A' || input[i] == 'H' || input[i] == 'I' ||
          input[i] == 'M' || input[i] == 'O' || input[i] == 'T' ||
          input[i] == 'U' || input[i] == 'V' || input[i] == 'W' ||
          input[i] == 'X' || input[i] == 'Y')) {
      flag = 1;
      break;
    }
  }
  i = len / 2;
  if (len % 2 == 1 &&
      !((input[i] == 'A' || input[i] == 'H' || input[i] == 'I' ||
         input[i] == 'M' || input[i] == 'O' || input[i] == 'T' ||
         input[i] == 'U' || input[i] == 'V' || input[i] == 'W' ||
         input[i] == 'X' || input[i] == 'Y')))
    flag = 1;
  if (flag == 1)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
