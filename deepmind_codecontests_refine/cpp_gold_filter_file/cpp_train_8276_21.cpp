#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m, a, sum;
  char mid;
  scanf("%d%c%d", &h, &mid, &m);
  scanf("%d", &a);
  sum = a + m;
  h += sum / 60;
  if (h > 23) {
    h %= 24;
  }
  m = sum % 60;
  printf("%02d:%02d\n", h, m);
  return 0;
}
