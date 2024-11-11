#include <bits/stdc++.h>
int main() {
  int l, a, p;
  scanf("%d %d %d", &l, &a, &p);
  int tot;
  p = p - (p % 4);
  int t = 0;
  while (t == 0) {
    if (p / 2 <= a && p / 4 <= l) {
      printf("%d", 7 * (p / 4));
      return 0;
    } else {
      p = p - 4;
    }
  }
}
