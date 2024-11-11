#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
  int i, j, k;
  scanf("%d", &i);
  while (i--) {
    scanf("%d", &j);
    printf("%d\n", (j / 7) + (j % 7 != 0));
  }
  return 0;
}
