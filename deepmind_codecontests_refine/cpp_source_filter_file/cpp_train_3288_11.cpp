#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, r, flag;
long long ans;
bitset<510> ss[61][2][510], con, now;
int main() {
  scanf("%d%d", &n, &m);
  int i = 1;
  for (i; i <= m; i++) {
    scanf("%d%d%d", &p, &q, &r);
    ss[0][r][p][q] = 1;
  }
  for (i = 1; i <= 60; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (ss[i - 1][0][j][k]) ss[i][0][j] |= ss[i - 1][1][k];
        if (ss[i - 1][1][j][k]) ss[i][1][j] |= ss[i - 1][0][k];
      }
    }
  }
  for (i = 1; i <= n; i++)
    if (ss[60][0][1][i]) {
      printf("-1");
      return 0;
    }
  con[1] = 1;
  for (i = 59; i >= 0; i--) {
    now = 0;
    for (int j = 1; j <= n; j++)
      if (con[j]) now |= ss[i][flag][j];
    if (now.count()) {
      con = now;
      flag ^= 1;
      ans += (1 << i);
    }
  }
  if (ans > (long long)1e18) {
    printf("-1");
    return 0;
  }
  printf("%I64d", ans);
  return 0;
}
