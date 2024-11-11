#include <bits/stdc++.h>
using namespace std;
int n, m, f[105][200005], q[200005], he, ta;
int main() {
  scanf("%d%d", &n, &m);
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for (int i = 1, len, t; i <= m; i++) {
    scanf("%d%d", &len, &t);
    len = t - len + 1;
    for (int j = 0; j <= t; j++) f[i][j] = f[i - 1][j];
    he = 1, ta = 0;
    for (int j = t; ~j; j--) {
      while (he <= ta && q[he] < t - j - len) he++;
      while (he <= ta && f[i - 1][q[ta]] > f[i - 1][t - j]) ta--;
      q[++ta] = t - j;
      f[i][j] = min(f[i][j], f[i - 1][q[he]] + 1);
    }
    if (len > 1) {
      he = 1, ta = 0;
      for (int j = 0; j <= t; j++) {
        while (he <= ta && q[he] < j - len) he++;
        while (he <= ta && f[i - 1][q[ta]] > f[i - 1][j]) ta--;
        q[++ta] = j;
        f[i][j] = min(f[i][j], f[i - 1][q[he]] + 2);
      }
    }
  }
  if (f[m][n] >= f[0][1])
    puts("Hungry");
  else {
    puts("Full");
    printf("%d\n", f[m][n]);
  }
  return 0;
}
