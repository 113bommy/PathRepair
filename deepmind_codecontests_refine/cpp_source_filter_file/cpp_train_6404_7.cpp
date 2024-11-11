#include <bits/stdc++.h>
int main() {
  int i, j;
  char a[100];
  char b[100];
  scanf("%s", a);
  scanf("%s", b);
  for (i = 0; i < strlen(a); i++) {
    if (a[i] == b[i]) {
      printf("0");
    } else {
      printf("1");
    }
  }
  printf("\n");
  return 0;
}
