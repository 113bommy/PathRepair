#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, b, r;
  int sum = 0;
  int minV;
  scanf("%d %d %d", &y, &b, &r);
  for (int i = 100; i > 3; i--) {
    if (r >= i && b >= i - 1 && y >= i - 2) {
      printf("%d\n", i * 3 - 3);
      break;
    }
  }
  return 0;
}
