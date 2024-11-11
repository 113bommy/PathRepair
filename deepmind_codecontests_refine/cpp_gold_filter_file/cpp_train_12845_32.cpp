#include <bits/stdc++.h>
using namespace std;
FILE *f, *g;
int i, n, k, s;
int main() {
  scanf("%d%d", &n, &k);
  s = (n - 1) * (n) / 2;
  if (k >= s) {
    printf("no solution");
    return 0;
  }
  for (i = 1; i <= n; i++) printf("%d %d\n", 0, i);
  return 0;
}
