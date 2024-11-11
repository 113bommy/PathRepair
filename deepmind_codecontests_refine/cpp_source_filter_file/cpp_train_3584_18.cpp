#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  int t = n / 2;
  if (n == 5) {
    printf("1 2 2\n2 4 1\n4 5 1\n3 1 1\n3 4\n3 5\n");
    return 0;
  }
  for (int i = 1; i <= t; i++) printf("%d %d %d\n", i, i + t, 1);
  for (int i = t + 1; i <= n - 1; i++)
    printf("%d %d %d\n", i, i + 1, 2 * (i - t) - 1);
  for (int i = 1; i <= t - 1; i++) printf("%d %d\n", i, i + 1);
  printf("1 3\n");
}
