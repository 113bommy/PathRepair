#include <bits/stdc++.h>
int main() {
  int a = 0, b;
  char c[1001], d[1001];
  gets(c);
  while (c[a] != '.') {
    d[a] = c[a];
    a++;
  }
  d[a] = '\0';
  if (c[a - 1] == '9')
    printf("GOTO Vasilisa.\n");
  else if (c[a + 1] < '5')
    puts(d);
  else {
    d[a - 1] += 1;
    puts(d);
  }
  return 0;
}
