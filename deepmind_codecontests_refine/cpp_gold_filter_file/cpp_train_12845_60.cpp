#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int stst = 0, stx = 2000;
  scanf("%d%d", &n, &k);
  if (k >= n * (n - 1) / 2) {
    printf("no solution\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    printf("0 %d\n", stst);
    stst++;
    stx--;
  }
  return 0;
}
