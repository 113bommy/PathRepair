#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5) {
    printf("1 4 1\n");
    printf("2 5 1\n");
    printf("3 4 2\n");
    printf("2 3 2\n");
    printf("1 2\n");
    printf("4 5\n");
    return 0;
  }
  for (int i = 1; i <= n / 2; i++) printf("%d %d 1\n", i, i + n / 2);
  for (int i = 1; i <= n - n / 2 - 1; i++)
    printf("%d %d %d\n", i + n / 2, i + n / 2 + 1, 2 * i - 1);
  for (int i = 1; i <= n / 2 - 1; i++) printf("%d %d\n", i, i + 1);
  printf("1 3\n");
  return 0;
}
