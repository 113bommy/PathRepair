#include <bits/stdc++.h>
using namespace std;
int n, t;
int a[1000005], g[1000005];
int main(void) {
  int i;
  scanf("%d", &n);
  int cur = 0, sum = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &g[i]);
    if (sum + a[i] <= 500) {
      putchar('A');
      sum += a[i];
    } else {
      putchar('G');
      sum -= g[i];
    }
  }
  printf("\n");
  return 0;
}
