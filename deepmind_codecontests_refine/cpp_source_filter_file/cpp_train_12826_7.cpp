#include <bits/stdc++.h>
using namespace std;
int n, pla, pla2, pla3, ans, k, tmp, tmp2, tmp3;
int main() {
  scanf("%d%d", &n, &k), printf("? ");
  for (int i = 1; i <= k; i++) printf("%d ", i);
  printf("\n");
  fflush(stdout), scanf("%d%d", &pla, &tmp2);
  for (int i = 1; i <= k; i++) {
    printf("? ");
    for (int j = 1; j <= k; j++)
      if (j != i) printf("%d ", j);
    printf("%d\n", k + 1);
    fflush(stdout), scanf("%d%d", &pla3, &tmp2);
    if (pla3 == pla)
      ans++;
    else
      tmp3 = tmp2;
  }
  if (tmp3 > tmp)
    printf("! %d\n", k - ans);
  else
    printf("! %d\n", ans + 1);
}
