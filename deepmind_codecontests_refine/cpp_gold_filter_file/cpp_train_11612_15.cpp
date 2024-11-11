#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, h1, h2, pos;
  scanf("%d %d", &h1, &h2);
  scanf("%d %d", &a, &b);
  pos = h1;
  pos += a * 8;
  if (pos >= h2) {
    printf("0\n");
    return 0;
  }
  pos -= 12 * b;
  if (a <= b) {
    printf("-1\n");
    return 0;
  }
  int day = 1;
  while (pos < h2) {
    pos += 12 * a;
    if (pos >= h2) {
      break;
    }
    pos -= 12 * b;
    day++;
  }
  printf("%d\n", day);
  return 0;
}
