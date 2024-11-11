#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, k;
  scanf("%d%d", &n, &k);
  int x = n * 3 * 2 - 1;
  printf("%d\n", x * k);
  x = 1;
  for (int i = 1; i <= n; i++) {
    printf("%d", i * 2 * k);
    for (int j = 0; j < 3; j++) {
      printf(" %d", (x * 2 - 1) * k);
      x++;
    }
    printf("\n");
  }
  return 0;
}
