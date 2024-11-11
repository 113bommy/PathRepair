#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, h, s;
  scanf("%d%d", &r, &h);
  if (h * 2 / r > 0 && 1.0 * h * 2 / r - h * 2 / r > 0.7)
    s = h * 2 / r + 1;
  else
    s = h * 2 / r;
  printf("%d\n", 1 + s);
  return 0;
}
