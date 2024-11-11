#include <bits/stdc++.h>
int main() {
  int blocks, i = 0;
  scanf("%d", &blocks);
  while (i * i <= blocks) {
    ++i;
  }
  --i;
  int szeleszama = 4 * i;
  if (blocks - i * i > i) {
    szeleszama += 4;
  } else if (blocks == i * i) {
  } else {
    szeleszama += 2;
  }
  printf("%d", szeleszama);
  return 0;
}
