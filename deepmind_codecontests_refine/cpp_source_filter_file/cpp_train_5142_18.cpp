#include <bits/stdc++.h>
int main() {
  printf("9\?\?>>\?\?0\n");
  for (int i = 0; i < 9; i++) printf("%d\?\?<>%d\n", i, i + 1);
  printf("\?\?>>1\n");
  for (int i = 0; i < 10; i++) printf("\?%d>>%d\?\n", i, i);
  for (int i = 0; i < 9; i++) printf("%d?<>%d\n", i, i + 1);
  printf("9\?>>\?\?0\n");
  for (int i = 0; i < 10; i++) printf("%d>>\?%d\n", i, i);
  return 0;
}
