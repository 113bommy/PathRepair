#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, h2;
  int a, b;
  scanf("%d%d", &h1, &h2);
  scanf("%d%d", &a, &b);
  int ret = 0;
  if (a <= b) {
    if (h2 - h1 > 8 * a)
      puts("-1");
    else
      puts("0");
  } else {
    h1 += 8 * a;
    while (h1 < h2) {
      h1 = h1 - 12 * b;
      h1 += 12 * a;
      ret++;
    }
    printf("%d\n", ret);
  }
  return 0;
}
