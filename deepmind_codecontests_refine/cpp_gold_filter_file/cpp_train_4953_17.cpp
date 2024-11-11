#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  if (m == 1 || m >= 4 || n < 4) {
    printf("-1");
    return (0);
  }
  if (m == 2 && n == 4) {
    printf("-1");
    return (0);
  }
  if (m == 2) {
    printf("%d\n", n - 1);
    for (int i = 1; i < n; i++) printf("%d %d\n", i, i + 1);
    return (0);
  }
  printf("%d\n", n - 1);
  for (int i = 2; i < n; i++) {
    printf("%d %d\n", 1, i);
  }
  printf("%d %d", 2, n);
}
