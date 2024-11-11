#include <bits/stdc++.h>
int main() {
  char name[1001];
  int leng;
  scanf("%d", &leng);
  memset(name, 'o', leng);
  name[leng] = 0;
  int u1 = 1, u2 = 1, temp;
  while (u2 < 1000) {
    name[u2 - 1] = 'O';
    temp = u1 + u2;
    u1 = u2;
    u2 = temp;
  }
  printf("%s\n", name);
}
