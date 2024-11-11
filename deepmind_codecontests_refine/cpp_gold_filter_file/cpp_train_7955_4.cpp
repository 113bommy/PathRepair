#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5) {
    printf("1 2 3\n");
    printf("1 3 1\n");
    printf("2 4 2\n");
    printf("4 5 1\n");
    printf("3 4\n3 5\n");
    return 0;
  }
  for (int i = 0; i < n / 2; i++) printf("%d %d 1\n", i + 1, i + n / 2 + 1);
  for (int i = 0; i < n / 2 - 1; i++)
    printf("%d %d %d\n", i + n / 2 + 1, i + 1 + n / 2 + 1, 2 * i + 1);
  if (n % 2) printf("%d %d 1\n", n - 1, n);
  for (int i = 0; i < n / 2 - 1; i++) printf("%d %d\n", i + 1, i + 2);
  printf("1 3\n");
  return 0;
}
