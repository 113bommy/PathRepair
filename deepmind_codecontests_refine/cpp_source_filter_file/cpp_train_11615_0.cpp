#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j;
  int f, h, m;
  scanf("%d", &f);
  scanf("%d:%d", &h, &m);
  if (f == 12) {
    if (m > 59) {
      if (m % 10 == 0)
        m = 0;
      else
        m = m % 10;
    }
    if (h > 12) {
      if (h % 10 == 0)
        h /= 10;
      else
        h %= 10;
    } else if (h == 0)
      h = 1;
  } else {
    if (m > 59) {
      if (m % 10 == 0)
        m = 0;
      else
        m = m % 10;
    }
    if (h > 23) {
      h %= 10;
    }
  }
  printf("%02d:%02d\n", h, m);
  return 0;
}
