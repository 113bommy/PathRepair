#include <bits/stdc++.h>
using namespace std;
const int maxn = 5;
int a[maxn];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  switch (n) {
    case 0:
      printf("YES\n1\n1\n3\n3\n");
      break;
    case 1:
      printf("YES\n%d\n%d\n%d\n", a[1], 3 * a[1], 3 * a[1]);
      break;
    case 2:
      if (a[2] > 3 * a[1])
        printf("NO\n");
      else
        printf("YES\n%d\n%d\n", 3 * a[1], 4 * a[1] - a[2]);
      break;
    case 3:
      if (a[3] < 3 * a[1] && a[2] + a[3] == 4 * a[1])
        printf("YES\n%d\n", 3 * a[1]);
      else if (a[3] == 3 * a[1])
        printf("YES\n%d\n", 4 * a[1] - a[2]);
      else if (a[3] % 3 == 0 && a[2] + a[1] == 4 * a[3] / 3)
        printf("YES\n%d\n", a[3] / 3);
      else
        printf("NO\n");
      break;
    default:
      if (a[4] == 3 * a[1] && a[2] + a[3] == 4 * a[1])
        printf("YES\n");
      else
        printf("NO\n");
  }
  return 0;
}
