#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    if (m == 3) {
      if (n == 3)
        printf("0 0\n1 0\n0 1\n");
      else if (n == 4)
        printf("0 0\n3 0\n0 3\n1 1\n");
      else
        printf("-1\n");
      continue;
    }
    for (int i = 1; i <= m; i++) {
      printf("%d %d\n", i, 10000 + i * i);
    }
    for (int i = 1; i <= n - m; i++) {
      printf("%d %d\n", i + m, -10000 + i * i);
    }
  }
  return 0;
}
