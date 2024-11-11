#include <bits/stdc++.h>
int main() {
  char deepdarkfantasy[][4] = {"05", "08", "17", "02", "20", "11"};
  int athatsgood;
  scanf("%d", &athatsgood);
  if (athatsgood < 3)
    puts("-1");
  else if (athatsgood == 3)
    puts("210");
  else {
    printf("1");
    for (int i = 0; i < athatsgood - 3; i++) printf("0");
    printf("%s0\n", deepdarkfantasy[(athatsgood - 4) % 6]);
  }
  return 0;
}
