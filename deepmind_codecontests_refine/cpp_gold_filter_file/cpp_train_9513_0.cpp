#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  int n, m;
  scanf("%d%d", &n, &m);
  if (m == 3) {
    switch (n) {
      case 3:
        printf("0 0\n");
        printf("3 0\n");
        printf("0 3\n");
        break;
      case 4:
        printf("0 0\n");
        printf("3 0\n");
        printf("0 3\n");
        printf("1 1\n");
        break;
      case 5:
      case 6:
        printf("-1\n");
        break;
    }
  } else {
    k = 10000000;
    for (i = 0; i < m; i++) printf("%d %d\n", i, k + i * i);
    for (i = 0; i < n - m; i++) printf("%d %d\n", i, -k - i * i);
  }
  return 0;
}
