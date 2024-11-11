#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &m, &n);
  if (m == 3) {
    if (n == 3) {
      printf("0 0\n0 1\n1 0\n");
      return 0;
    }
    if (n == 4) {
      printf("0 0\n0 10\n10 0\n1 1\n");
      return 0;
    }
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= m; ++i) printf("%d %d\n", i, -(n - i) * (n - i));
  for (int i = 1; i <= n - m; ++i) printf("%d %d\n", -i, (n - i) * (n - i));
}
