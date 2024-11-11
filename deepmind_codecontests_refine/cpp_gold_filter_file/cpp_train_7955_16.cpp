#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n;
int main() {
  int i, j, k;
  scanf("%d", &n);
  if (n == 5) {
    printf("1 3 1\n1 2 2\n2 4 1\n4 5 1\n3 4\n3 5");
  } else {
    for (i = 1; i <= (n - 1) / 2; i++)
      printf("%d %d %d\n", n / 2 + i, n / 2 + i + 1, i * 2 - 1);
    for (i = 1; i <= n / 2; i++) printf("%d %d %d\n", i, i + n / 2, 1);
    for (i = 1; i < n / 2; i++) printf("%d %d\n", i, i + 1);
    printf("1 3");
  }
  return 0;
}
