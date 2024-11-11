#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int sa = 0, sb = 0;
  int ca, cb;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &ca, &cb);
    if (sb + cb > sa + 500) {
      sa = sa + ca;
      printf("A");
    } else {
      sb += cb;
      printf("G");
    }
  }
  printf("\n");
  return 0;
}
