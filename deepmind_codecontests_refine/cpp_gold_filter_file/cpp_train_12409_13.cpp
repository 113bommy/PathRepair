#include <bits/stdc++.h>
using namespace std;
int digit[12];
int main() {
  int l, r, ans = 0, bkp;
  scanf("%d%d", &l, &r);
  for (int i = l; i <= r; i++) {
    bkp = 0;
    memset(digit, 0, sizeof(digit));
    for (int tmp = i; tmp > 0; tmp /= 10) {
      if (!digit[tmp % 10])
        digit[tmp % 10] = 1;
      else {
        bkp = 1;
        break;
      }
    }
    if (!bkp) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
