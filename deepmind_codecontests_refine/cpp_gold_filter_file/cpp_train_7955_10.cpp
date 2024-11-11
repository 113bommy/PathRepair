#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  scanf("%d", &n);
  if (n == 5) {
    printf("1 2 1\n2 4 1\n4 5 2\n3 5 2\n");
    printf("1 3\n2 3\n");
    return 0;
  }
  int m = n / 2;
  for (int i = 0; i < (m); ++i) printf("%d %d %d\n", i + 1, i + m + 1, 1);
  for (int i = m; i < n - 1; ++i)
    printf("%d %d %d\n", i + 1, i + 2, 2 * (i - m) + 1);
  for (int i = 0; i < (m - 1); ++i) printf("%d %d\n", i + 1, i + 2);
  printf("%d %d\n", 1, 3);
  return 0;
}
