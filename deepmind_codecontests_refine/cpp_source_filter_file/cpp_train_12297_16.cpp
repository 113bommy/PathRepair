#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  int l, r;
  int sum = 0;
  int odd = 0;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    if (l == r) {
      if (r % 2 == 0)
        printf("%d\n", r);
      else
        printf("%d\n", -r);
      continue;
    }
    sum = 0;
    odd = 0;
    if (l % 2 == 0) {
      odd = (r - l + 1) % 2;
      sum = (r - l + 1) / 2;
      sum = -sum;
      if (odd == 0) {
        printf("%d\n", sum);
      } else {
        sum = sum + r;
        printf("%d\n", sum);
      }
    } else {
      odd = (r - l + 1) % 2;
      sum = (r - l + 1) / 2;
      if (odd == 0) {
        printf("%d\n", sum);
      } else {
        sum = sum + r;
        printf("%d\n", sum);
      }
    }
  }
  return 0;
}
