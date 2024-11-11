#include <bits/stdc++.h>
using namespace std;
const int N = 150010, Mod = 1e9 + 7;
int t, n, i, r;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = r = 0; i < 9; i++) {
      int cnt = 0, x;
      for (int j = 1; j <= n; j++)
        if ((j >> i) & 1) cnt++;
      if (cnt == 0 || cnt == n) continue;
      printf("%d %d", cnt, n - cnt);
      for (int j = 1; j <= n; j++)
        if ((j >> i) & 1) printf(" %d", j);
      for (int j = 1; j <= n; j++)
        if (!((j >> i) & 1)) printf(" %d", j);
      printf("\n");
      fflush(stdout);
      scanf("%d", &x);
      r = max(r, x);
    }
    printf("-1 %d\n", r);
    fflush(stdout);
  }
  return 0;
}
