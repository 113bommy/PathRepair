#include <bits/stdc++.h>
using namespace std;
int tab[200007];
int main() {
  int q, i, j, n, k, ln;
  scanf("%d", &q);
  for (j = 0; j < q; j++) {
    ln = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
      scanf("%d", &tab[ln]);
      if (tab[ln] % 2 == 1) {
        tab[ln] = i + 1;
        ln++;
      }
    }
    if ((ln >= k) && ((ln - k) % 2 == 0)) {
      printf("YES\n");
      for (i = (ln - k) / 2; i < ln - 1; i++) {
        printf("%d ", tab[i]);
      }
      printf("%d", n);
    } else {
      printf("NO");
    }
    printf("\n");
  }
  return 0;
}
