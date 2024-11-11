#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, h, m, sum = 0;
  scanf("%d %d %d", &x, &h, &m);
  while (1) {
    if (h / 10 == 7 || h % 10 == 7 || m / 10 == 7 || m % 10 == 7) {
      break;
    }
    if (m >= x) {
      m -= x;
    } else {
      m += 60;
      m -= x;
      h--;
      if (h < 0) h += 24;
    }
    sum++;
  }
  printf("%d\n", sum);
}
