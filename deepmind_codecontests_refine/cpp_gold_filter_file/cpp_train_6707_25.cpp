#include <bits/stdc++.h>
int min(int a, int b) { return (a > b) ? b : a; }
int main() {
  int n, i, e, t;
  char c;
  n = i = e = t = 0;
  while (1) {
    c = '1';
    scanf("%c", &c);
    if (c == '1' || c == '\n') break;
    if (c == 'n') n++;
    if (c == 'i') i++;
    if (c == 'e') e++;
    if (c == 't') t++;
  }
  n = (n - 1) / 2;
  e = e / 3;
  printf("%d", min(min(n, i), min(e, t)));
}
