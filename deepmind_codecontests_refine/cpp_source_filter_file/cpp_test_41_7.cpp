#include <bits/stdc++.h>
using namespace std;
int n, k, m, cnt, now, A[1000 + 5][1000 + 5], La;
int main() {
  register int i, j;
  scanf("%d%d", &n, &k);
  now = 1;
  while (now <= n) {
    La = now;
    now *= k;
    cnt++;
    for (i = 1; i <= n; i++) {
      for (j = (i - 1) / La * La + La + 1;
           j <= (((i - 1) / now * now + now) < (n) ? ((i - 1) / now * now + now)
                                                   : (n));
           j++)
        A[i][j] = cnt;
    }
  }
  printf("%d\n", cnt);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) printf("%d ", A[i][j]);
}
