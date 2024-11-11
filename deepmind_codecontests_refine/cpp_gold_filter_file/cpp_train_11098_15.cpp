#include <bits/stdc++.h>
void Set_C(char* c) {
  if (*c == '^')
    *c = 0;
  else if (*c == '>')
    *c = 1;
  else if (*c == 'v')
    *c = 2;
  else
    *c = 3;
}
int main(void) {
  int n, cnt = 0;
  char c1, c2;
  scanf(" %c %c", &c1, &c2);
  scanf("%d", &n);
  n = n % 4;
  Set_C(&c1);
  Set_C(&c2);
  if ((c1 + n) % 4 == c2) cnt = 2;
  if ((c1 + (4 - n)) % 4 == c2) {
    if (cnt == 2)
      cnt = 0;
    else
      cnt = 1;
  }
  if (cnt == 1)
    puts("ccw");
  else if (cnt == 2)
    puts("cw");
  else
    puts("undefined");
  return 0;
}
