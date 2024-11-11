#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k >= n * (n - 1) / 2)
    printf("no solution\n");
  else {
    int x = 2000, y = 0;
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", x, y);
      x--;
      y += i;
    }
  }
  return 0;
}
