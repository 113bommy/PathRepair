#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d\n", (6 * n - 1) * k);
  int a = 1, b = 2;
  for (int i = 1; i <= n; i++) {
    printf("%d %d %d %d\n", a * k, (a + 2) * k, (a + 4) * k, b * k);
    b += 6;
    a += 6;
  }
  return 0;
}
