#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, y, d;
    scanf("%d %d %d %d", &n, &x, &y, &d);
    int a = abs(x - y);
    int ans = INT_MAX;
    if (a % d == 0) {
      ans = a / d;
    } else {
      int b = INT_MAX, c = INT_MAX;
      if (((y - 1) % d == 0)) {
        b = ceil((double)(x - 1) / d) + (n - y) / d;
      }
      if ((n - y) % d == 0) {
        c = ceil((double)(n - x) / d) + (n - y) / d;
      }
      ans = min(b, c);
    }
    if (ans != INT_MAX) {
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
  }
}
