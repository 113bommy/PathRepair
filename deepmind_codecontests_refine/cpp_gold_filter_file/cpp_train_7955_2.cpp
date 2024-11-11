#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n == 5) {
    printf("1 3 1\n");
    printf("1 2 2\n");
    printf("2 4 1\n");
    printf("4 5 1\n");
    printf("3 4\n");
    printf("3 5\n");
  } else {
    for (int i = 1; i <= n / 2; ++i) printf("%d %d 1\n", i, i + n / 2);
    for (int i = n / 2 + 1; i < n; ++i)
      printf("%d %d %d\n", i, i + 1, 2 * (i - n / 2) - 1);
    for (int i = 1; i < n / 2; ++i) printf("%d %d\n", i, i + 1);
    printf("1 3\n");
  }
}
