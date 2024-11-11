#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, an = 0;
  int a[1111];
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1)
      m--;
    else if (a[i] == 2) {
      if (k > 0)
        k--;
      else
        m--;
    }
    if (m < 0) {
      m++;
      an++;
    }
    printf("%d\n", an);
  }
  return 0;
}
