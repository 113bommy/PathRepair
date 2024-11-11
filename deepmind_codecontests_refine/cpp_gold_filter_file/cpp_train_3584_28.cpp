#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5) {
    printf("1 2 3\n1 3 3\n 2 4 2\n4 5 1\n");
    printf("3 4\n3 5\n");
    return 0;
  }
  int as = n / 2;
  for (int i = 1; i <= as; i++) printf("%d %d %d\n", i, i + as, 1);
  for (int i = 1; i + as < n; i++) {
    printf("%d %d %d\n", i + as, i + as + 1, 2 * i - 1);
  }
  for (int i = 1; i < as; i++) printf("%d %d\n", i, i + 1);
  printf("1 3\n");
  return 0;
}
