#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  scanf("%d", &n);
  if (n % 4 == 0) {
    printf("0\n%d ", n / 2);
    for (i = 1; i <= n / 2; i += 2) printf("%d %d ", i, n - i + 1);
    return 0;
  }
  if (n % 4 == 1) {
    printf("1\n%d ", n / 2);
    for (i = 1; i <= n / 4; i++) printf("%d %d ", i * 2, n - i * 2 + 2);
    return 0;
  }
  if (n % 4 == 2) {
    printf("1\n%d ", n / 2);
    for (i = 1; i <= n / 4; i++) printf("%d %d ", 2 * i - 1, n - i * 2 + 2);
    printf("%d", n / 2);
    return 0;
  }
  if (n % 4 == 3) {
    printf("0\n%d ", n / 2);
    for (i = 1; i <= n / 4; i++) printf("%d %d ", i * 2, n - i * 2 + 2);
    printf("%d", n / 2 + 2);
    return 0;
  }
}
