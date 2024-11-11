#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d", &n);
  if (n == 5) {
    printf("3 2 1\n");
    printf("2 1 3\n");
    printf("1 4 1\n");
    printf("4 5 2\n");
    printf("3 4\n 3 5\n");
  } else {
    m = n >> 1;
    for (int i = 1; i <= m; ++i) printf("%d %d 1\n", i, i + m);
    printf("%d %d 1\n", m + 1, m + 2);
    for (int i = 2; i < m; ++i) printf("%d %d %d\n", m + i, m + i + 1, i + 1);
    if (n & 1) printf("%d %d 1\n", n - 1, n);
    for (int i = 2; i <= m; ++i) printf("1 %d\n", i);
    printf("2 3\n");
  }
  return 0;
}
