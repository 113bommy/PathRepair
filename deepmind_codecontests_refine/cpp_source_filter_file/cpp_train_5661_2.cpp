#include <bits/stdc++.h>
using namespace std;
int main() {
  char c, cOld;
  bool drop = false, first = true, was = false;
  while (scanf("%c", &c) == 1) {
    if (!(c == '0' || c == '1')) break;
    if (drop) {
      drop = false;
      cOld = c;
      continue;
    }
    if (c == '0' && !was) {
      drop = true;
      was = true;
    }
    if (!first) {
      printf("%c", cOld);
    }
    first = false;
    cOld = c;
  }
  if (was) {
    printf("%c", cOld);
  }
  return 0;
}
