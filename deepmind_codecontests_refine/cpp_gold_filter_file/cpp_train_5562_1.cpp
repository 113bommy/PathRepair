#include <bits/stdc++.h>
const int mo = (int)1e9 + 7, B = 30;
int n, pw2[B + 1], f[B + 1][B + 1], g[B + 1][B + 1];
void inc(int &a, const int b) {
  if ((a += b) >= mo) a -= mo;
}
int main() {
  scanf("%d", &n);
  n++;
  pw2[0] = 1;
  for (int j = 1; j <= B; j++) pw2[j] = pw2[j - 1] * 2 % mo;
  g[B][0] = 1;
  for (int i = B; i > 0; i--)
    for (int j = 0; j <= B - i; j++) {
      inc(f[i - 1][j + 1], f[i][j]);
      inc(f[i - 1][j], f[i][j] * 1LL * pw2[j] % mo);
      if (n >> (i - 1) & 1) {
        inc(g[i - 1][j + 1], g[i][j]);
        inc(f[i - 1][j], g[i][j] * 1LL * (j ? pw2[j - 1] : 1) % mo);
        inc(g[i - 1][j], g[i][j] * 1LL * (j ? pw2[j - 1] : 0) % mo);
      } else {
        inc(g[i - 1][j], g[i][j] * 1LL * (j ? pw2[j - 1] : 1) % mo);
      }
    }
  int ans = 0;
  for (int j = 0; j <= B; j++) inc(ans, f[0][j]);
  printf("%d\n", ans);
}
