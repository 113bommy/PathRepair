#include <bits/stdc++.h>
using namespace std;
int n, x, y, a[10005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x, &y);
    if (!x && !y) {
      printf("YES\n");
      continue;
    }
    if (!x || !y) {
      printf("NO\n");
      continue;
    }
    if (y / x > 2 || x / y > 2) {
      printf("NO\n");
      continue;
    }
    if ((x + y) % 3 == 0) {
      printf("YES\n");
      continue;
    }
    printf("NO\n");
  }
  return 0;
}
