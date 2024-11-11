#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, k, a[2], b[2];
  scanf("%d %d", &n, &k);
  scanf("%d %d %d %d", &a[0], &a[1], &b[0], &b[1]);
  if (n <= 4) {
    printf("-1");
  } else if (n + 2 > k)
    printf("-1");
  else {
    printf("%d %d ", a[0], b[0]);
    for (i = 1; i <= n; i++)
      if (i != a[0] && i != b[0] && i != a[1] && i != b[1]) printf("%d ", i);
    printf("%d %d", b[1], a[1]);
    printf("\n");
    printf("%d %d ", b[0], a[0]);
    for (i = 1; i <= n; i++)
      if (i != a[0] && i != b[0] && i != a[1] && i != b[1]) printf("%d ", i);
    printf("%d %d", a[1], b[1]);
  }
  return 0;
}
