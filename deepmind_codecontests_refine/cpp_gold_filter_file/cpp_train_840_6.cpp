#include <bits/stdc++.h>
using namespace std;
int isg[709][709] = {0}, ca[709];
bool ggcd(int a, int b) { return b ? ggcd(b, a % b) : a != 1; }
bool gcd(int a, int b) {
  return isg[a][b] ? (isg[a][b] - 1)
                   : isg[a][b] = (ggcd(ca[a], ca[b]) ? 1 : 0) + 1,
                     isg[a][b] - 1;
}
int main() {
  int n;
  bool f[709][709][2] = {0};
  scanf("%d", &n);
  for (int i = 1; i <= n; i = -(~i)) {
    scanf("%d", &ca[i]);
    if (i != 1) f[i][i][0] = f[i - 1][i - 1][1] = gcd(i, i - 1);
  }
  for (int i = 1; i <= n; i = -(~i)) {
    for (int j = i - 1; j; j = ~(-j)) {
      for (int k = j + 1; k < i; k = -(~k)) {
        if (f[j][k - 1][1] && f[k + 1][i][0]) {
          f[j][i][0] |= gcd(j - 1, k);
          f[j][i][1] |= gcd(i + 1, k);
        }
      }
      if (f[j + 1][i][0]) {
        f[j][i][0] |= gcd(j - 1, j);
        f[j][i][1] |= gcd(i + 1, j);
      }
      if (f[j][i - 1][1]) {
        f[j][i][0] |= gcd(j - 1, i);
        f[j][i][1] |= gcd(i + 1, i);
      }
    }
  }
  printf("%s", (f[1][n][0] || f[1][n][1]) ? "Yes" : "No");
  return 0;
}
