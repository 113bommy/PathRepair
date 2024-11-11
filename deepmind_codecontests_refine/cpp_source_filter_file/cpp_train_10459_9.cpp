#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, x, y, k, ans = 0;
  scanf("%d%d", &x, &y);
  if (x <= y)
    printf("infinity\n");
  else {
    k = x - y;
    for (i = 1; i <= sqrt(k); i++) {
      if (k % i == 0) {
        if (i > y) ans++;
        if (k / i > y && i != k / i) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
