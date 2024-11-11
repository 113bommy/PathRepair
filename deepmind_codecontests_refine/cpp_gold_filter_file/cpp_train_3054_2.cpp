#include <bits/stdc++.h>
using namespace std;
int tx, tt, h, ss, ta, x, y, i, j, k, e, n, m, mo, ru[700], chu[700], s[700],
    q[700], t[700], gy[100100], ne[100100], fir[700];
long long tmp, ans, f[700][700], de[700][700];
void add(int x, int y) {
  gy[++e] = y;
  ne[e] = fir[x];
  fir[x] = e;
}
int main() {
  scanf("%d%d%d", &n, &m, &mo);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    ru[y]++;
    chu[x]++;
  }
  for (i = 1; i <= n; i++) {
    if (!ru[i]) {
      s[++ss] = i;
      q[++ta] = i;
    }
    if (!chu[i]) t[++tx] = i;
  }
  for (i = 1; i <= ss; i++) f[i][s[i]] = 1;
  for (h = 0; h < ta;) {
    x = q[++h];
    for (tt = fir[x]; tt != 0; tt = ne[tt]) {
      for (j = 1; j <= ss; j++) f[j][gy[tt]] = (f[j][x] + f[j][gy[tt]]) % mo;
      ru[gy[tt]]--;
      if (!ru[gy[tt]]) q[++ta] = gy[tt];
    }
  }
  for (i = 1; i <= ss; i++) {
    for (j = 1; j <= tx; j++) {
      de[i][j] = f[i][t[j]];
    }
  }
  for (i = 1, ans = 1; i <= ss; ans = ans * de[i][i] % mo, i++)
    for (j = i + 1; j <= ss; j++)
      for (; de[j][i];) {
        for (k = i + 1; k <= ss; k++)
          de[i][k] = (de[i][k] - de[i][i] / de[j][i] * de[j][k]) % mo;
        de[i][i] = (de[i][i] - de[i][i] / de[j][i] * de[j][i]) % mo;
        for (k = i; k <= ss; k++)
          tmp = de[j][k], de[j][k] = de[i][k], de[i][k] = tmp;
        ans = -ans;
      }
  if (ans < 0) ans += mo;
  cout << ans;
}
