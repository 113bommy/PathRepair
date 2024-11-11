#include <bits/stdc++.h>
using namespace std;
int n, a[10], b[5], sol[5], advrg;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int x1 = 1; x1 <= 500; ++x1) {
    for (int v = 0; v <= x1; ++v) {
      b[1] = x1;
      b[2] = x1 + v;
      b[3] = 3 * x1 - v;
      b[4] = 3 * x1;
      int z = 1, advr = 1;
      for (int i = 1; i <= n; ++i) {
        while (z <= 4 && b[z] != a[i]) ++z;
        if (z == 5)
          advr = 0;
        else
          ++z;
      }
      if (advr == 1) {
        advrg = 1;
        sol[1] = b[1];
        sol[2] = b[2];
        sol[3] = b[3];
        sol[4] = b[4];
      }
    }
  }
  if (advrg == 1) {
    printf("YES\n");
    int z = 1;
    for (int i = 1; i <= 4; ++i) {
      if (sol[i] != a[z]) {
        printf("%d\n", sol[i]);
      } else
        ++z;
    }
  } else
    printf("NO");
  return 0;
}
