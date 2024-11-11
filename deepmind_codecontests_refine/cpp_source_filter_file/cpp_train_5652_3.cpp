#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N] = {0};
int main() {
  int n;
  scanf("%d", &n);
  int flag = 1, sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum ^= a[i];
  }
  if (n % 2 == 1) {
    printf("YES\n");
    printf("%d\n", n - 1);
    for (int i = 1; i <= n / 2; ++i) {
      printf("1 %d %d\n", 2 * i, 2 * i + 1);
    }
    for (int i = 1; i <= n / 2; ++i) {
      printf("1 %d %d\n", 2 * i, 2 * i + 1);
    }
  } else {
    if (sum != 0) {
      printf("NO\n");
    } else {
      printf("YES\n");
      printf("%d\n", n - 2);
      for (int i = 1; i <= n / 2; ++i) {
        printf("%d %d %d\n", 2 * i - 1, 2 * i, 2 * i + 1);
      }
      for (int i = 1; i <= n / 2; ++i) {
        printf("%d %d %d\n", 2 * i - 1, 2 * i, n);
      }
    }
  }
  return 0;
}
