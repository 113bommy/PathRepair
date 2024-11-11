#include <bits/stdc++.h>
int main() {
  int count = 0, comb;
  char c;
  while ((c = getchar()) != EOF) {
    ++count;
  }
  comb = (count * 25) + 26;
  printf("%d", comb);
  return 0;
}
