#include <bits/stdc++.h>
void king(char *integer, char *fractional) {
  int len = strlen(integer);
  if (integer[len - 1] == '9')
    printf("GOTO Vasilisa.");
  else if (fractional[0] >= '5') {
    integer[len - 1]++;
    printf("%s", integer);
  } else if (fractional[0] < '5')
    printf("%s", integer);
}
void read(char *integer, char *fractional) {
  int i = 0, j = 0;
  int c;
  while ((c = getchar()) != '.') integer[i++] = c;
  integer[i] = '\0';
  while ((c = getchar()) != '\0' && c != '\n') fractional[j++] = c;
  fractional[j] = '\0';
}
int main() {
  char integer[1000];
  char fractional[1000];
  read(integer, fractional);
  king(integer, fractional);
  return 0;
}
