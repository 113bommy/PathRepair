#include <bits/stdc++.h>
int main() {
  int i = 0;
  char c[100];
  gets(c);
  while (c[i] != '\0') {
    c[i] = tolower(c[i]);
    if (c[i] == 'a' || c[i] == 'y' || c[i] == 'o' || c[i] == 'e' ||
        c[i] == 'i' || c[i] == 'u') {
    } else {
      printf(".%c", c[i]);
    }
    i++;
  }
  return 0;
}
