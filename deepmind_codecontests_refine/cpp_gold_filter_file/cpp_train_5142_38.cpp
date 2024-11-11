#include <bits/stdc++.h>
int main() {
  int i;
  for (i = 0; i <= 8; i++) printf("%d\?\?<>%d\n", i, i + 1);
  printf("9\?\?>>\?\?0\n");
  printf("\?\?<>1\n");
  for (i = 0; i <= 9; i++) printf("\?%d>>%d\?\n", i, i);
  for (i = 0; i <= 8; i++) printf("%d\?<>%d\n", i, i + 1);
  printf("9\?>>\?\?0\n");
  for (i = 0; i <= 9; i++) printf("%d>>%d\?\n", i, i);
  return 0;
}
