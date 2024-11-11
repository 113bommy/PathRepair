#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c < a || c > b)
      printf("%d\n", c);
    else
      printf("%d\n", (b / c + 1) * c);
  }
  return 0;
}
