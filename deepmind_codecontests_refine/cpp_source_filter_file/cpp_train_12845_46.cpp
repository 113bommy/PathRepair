#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  srand(time(NULL));
  const int x = rand();
  scanf("%d%d", &n, &k);
  if (n * (n - 1) / 2 - 1 < k) {
    printf("no solution\n");
    return 0;
  }
  for (register int i = 1; i <= n; i++) {
    printf("%d %d\n", x, rand());
  }
  return 0;
}
