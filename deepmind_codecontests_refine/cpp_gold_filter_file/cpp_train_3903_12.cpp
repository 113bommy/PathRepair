#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100];
  scanf("%s", s);
  int n = strlen(s);
  int r = 0, i, x, q = 0;
  for (i = n - 1, x = 1, r = 0; i >= 0; i--, x *= 2) {
    r += (s[i] == '4') ? 0 : x;
  }
  int p = 0;
  while (--n) {
    p = p + (1 << n);
  }
  printf("%d", p + r + 1);
}
