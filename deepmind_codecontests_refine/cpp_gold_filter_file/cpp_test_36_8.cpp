#include <bits/stdc++.h>
using namespace std;
int tot1, tot2, s1[105], s2[105];
int main() {
  int T, n, Sum, a, t;
  bool Prime;
  cin >> T;
  while (T--) {
    scanf("%d", &n);
    Sum = tot1 = tot2 = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a);
      Sum += a;
      if (a % 2)
        s1[++tot1] = i;
      else
        s2[++tot2] = i;
    }
    Prime = 1;
    t = sqrt(Sum);
    for (int i = 2; i <= t; i++)
      if (Sum % i == 0) {
        Prime = 0;
        break;
      }
    if (!Prime) {
      printf("%d\n", n);
      for (int i = 1; i <= n; i++) printf("%d ", i);
      printf("\n");
    } else {
      printf("%d\n", n - 1);
      for (int i = 1; i <= tot2; i++) printf("%d ", s2[i]);
      for (int i = 1; i < tot1; i++) printf("%d ", s1[i]);
      printf("\n");
    }
  }
  return 0;
}
