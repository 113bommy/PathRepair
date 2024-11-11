#include <bits/stdc++.h>
int check(int g, int b) {
  if (b == g)
    return 1;
  else if (b < g) {
    if (b = g - 1)
      return 1;
    else
      return 0;
  } else {
    if (2 * g + 2 >= b)
      return 1;
    else
      return 0;
  }
}
int main() {
  int gl, gr, bl, br;
  scanf("%d%d%d%d", &gl, &gr, &bl, &br);
  if (check(gl, br) == 1 || check(gr, bl) == 1)
    printf("YES\n");
  else
    printf("NO");
  return 0;
}
