#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, k;
int main() {
  scanf("%d", &k);
  if (k == 1) {
    printf("YES\n2 1\n1 2\n");
    return 0;
  }
  if (k % 2 == 0) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  printf("%d %d\n", 2 * (k + 2), k * (k + 2));
  n = k + 2;
  for (int i = 2; i < n - 1; i++) printf("1 %d\n", i);
  for (int i = 2; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (i % 2 == 0 && j == i + 1) continue;
      printf("%d %d\n", i, j);
    }
  printf("%d %d\n", n - 1, n);
  for (int i = 2; i < n - 1; i++) printf("1 %d\n", i + n);
  for (int i = 2; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (i % 2 == 0 && j == i + 1) continue;
      printf("%d %d\n", n + i, n + j);
    }
  printf("%d %d\n", n + n - 1, n + n);
  printf("%d %d\n", 1, n + 1);
  return 0;
}
