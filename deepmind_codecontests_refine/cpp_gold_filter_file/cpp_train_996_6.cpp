#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
    int ans = -1;
    for (int i = 0; i < 10000; i++) {
      int x = d - b;
      int y = a * i - x;
      if (y >= 0 && y % c == 0) {
        ans = a * i + b;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
