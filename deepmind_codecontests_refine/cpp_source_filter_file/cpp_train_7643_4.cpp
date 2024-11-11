#include <bits/stdc++.h>
using namespace std;
bitset<2005> a[2005];
int main() {
  int n, i, j, fl2 = 0, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &k);
      a[i][j] = (k > 0);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (a[i][j]) {
        a[i] |= a[j];
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (!a[i][j]) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}
