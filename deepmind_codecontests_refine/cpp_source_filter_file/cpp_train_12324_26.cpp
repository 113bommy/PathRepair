#include <bits/stdc++.h>
int main() {
  int i, j;
  char array[10];
  int n;
  int count = 0;
  int co = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", array);
    if ((strcmp(array, "++x") == 0) || (strcmp(array, "x++") == 0)) {
      count++;
    }
    if ((strcmp(array, "--x") == 0) || (strcmp(array, "x--") == 0)) {
      co--;
    }
  }
  printf("%d", count + co);
}
