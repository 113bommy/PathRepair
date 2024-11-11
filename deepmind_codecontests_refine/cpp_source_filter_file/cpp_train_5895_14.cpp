#include <bits/stdc++.h>
using namespace std;
const int NN = 272727;
int a[NN], ca[NN], l[NN], r[NN];
int main() {
  int n, q, m;
  scanf("%d%d%d", &n, &q, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= q; i++) scanf("%d%d%d", ca + i, l + i, r + i);
  for (int i = 1; i <= m; i++) {
    int u;
    scanf("%d", &u);
    for (int j = n; j; j--) {
      if (u >= l[j] and u <= r[j]) {
        if (ca[j] == 1)
          u--;
        else
          u = l[j] + r[j] - u;
        if (u < l[j]) u = r[j];
      }
    }
    printf("%d ", a[u]);
  }
  return 0;
}
