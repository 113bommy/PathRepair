#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, s = 0, aj = 1, as = 1;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &a);
    if (a > s) {
      if (as != 1) aj = 0;
    } else if (a == s) {
      if (as == 1)
        as = 2;
      else if (as == 3)
        aj = 0;
    } else if (as < 3)
      as = 3;
    s = a;
  }
  if (aj)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
