#include <bits/stdc++.h>
int main() {
  int count = 0, comb;
  char c;
  while ((c = getchar()) != EOF) {
    ++count;
  }
  comb = ((count - 1) * 25) + 26;
  printf("%d", comb);
  return 0;
}
