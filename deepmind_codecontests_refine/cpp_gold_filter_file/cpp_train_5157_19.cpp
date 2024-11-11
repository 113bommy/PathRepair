#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
struct Node {
  int x, y;
} f[1100];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n + 1; i++) {
      scanf("%d%d", &f[i].x, &f[i].y);
    }
    f[n + 1].x = f[1].x;
    f[n + 1].y = f[1].y;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x = f[i + 1].x - f[i].x;
      int y = f[i + 1].y - f[i].y;
      int x1 = f[i + 2].x - f[i + 1].x;
      int y1 = f[i + 2].y - f[i + 1].y;
      if (x == 0) {
        if (y * x1 > 0) ans++;
      } else {
        if (x * y1 < 0) ans++;
      }
    }
    printf("%d\n", min(ans, n - ans));
  }
  return 0;
}
