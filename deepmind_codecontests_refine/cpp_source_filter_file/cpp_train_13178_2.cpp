#include <bits/stdc++.h>
const int n = 6000000, x = 103;
char str[n];
int ans[n];
int main() {
  int i = 0, l = 0, r = 0, t = 1, an = 0;
  for (gets(str); str[i]; i++) {
    l = l * x + str[i];
    r += str[i] * t;
    t *= x;
    ans[i + 1] = (l == r) ? ans[i / 2] + 1 : 0;
    an += ans[i + 1];
  }
  printf("%d\n", an);
}
