#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, k, n, x, i;
  scanf("%d%d", &n, &k);
  n--;
  x = (n * (n + 1)) / 2;
  if (x > k) {
    for (i = 1; i <= n + 1; i++) printf("0 %d\n", i);
  } else
    printf("no solution\n");
}
