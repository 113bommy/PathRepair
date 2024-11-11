#include <bits/stdc++.h>
using namespace std;
int n, d, k, gem[30001], f[30001][2 * 200], ans, limit;
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k), gem[k]++;
    limit = max(k, limit);
  }
  memset(f, -1, sizeof(f));
  f[d][200] = gem[d];
  for (int i = d; i <= limit; i++)
    for (int j = -200; j <= 200; j++)
      if (f[i][j + 200] != -1) {
        ans = max(ans, f[i][j + 200]);
        for (int delt = -1; delt <= 1; delt++) {
          int jump = d + j + delt;
          if (jump > 0 && i + jump <= 30000)
            f[i + jump][jump - d + 200] =
                max(f[i + jump][jump - d + 200], f[i][j + 200] + gem[i + jump]);
        }
      }
  printf("%d\n", ans);
  return 0;
}
