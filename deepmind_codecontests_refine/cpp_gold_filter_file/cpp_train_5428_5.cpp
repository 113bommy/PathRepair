#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int sum = n * m;
  if (n > m) swap(n, m);
  if (n == 1) printf("%d\n", sum - (m + 2) / 3);
  if (n == 2) printf("%d\n", sum - m / 2 - 1);
  if (n == 3) {
    int num = 0;
    if (m % 4 == 0) num = 1;
    printf("%d\n", sum - m / 4 * 3 - (m % 4) - num);
  }
  if (n == 4) {
    int num2 = 0;
    if (m == 6 || m == 5 || m == 9) num2 = 1;
    printf("%d\n", sum - m - num2);
  }
  if (n == 5) {
    if (m == 8)
      printf("29\n");
    else
      printf("%d\n", sum - m - 2);
  }
  if (n == 6) printf("26\n");
  return 0;
}
