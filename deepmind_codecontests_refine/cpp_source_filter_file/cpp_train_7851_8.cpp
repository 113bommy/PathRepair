#include <bits/stdc++.h>
const int N = 100050;
int mod = 1000000007;
int a[N];
int x[105][N];
int C[N][105];
int n, m;
void up(int &v, int x) {
  v = (v + x) % mod;
  if (v < 0) v += mod;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= n + 102; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i && j <= 102; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 1; i <= m; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    x[k + 1][l]++;
    for (int j = 1; j <= k + 1; j++)
      up(x[j][r + 1], -C[k + 1 - j + r - l][k + 1 - j]);
  }
  for (int k = 100; k >= 0; k--) {
    for (int i = 1; i <= n; i++) up(x[k + 1][i], x[k + 1][i - 1]);
    for (int i = 1; i <= n; i++) up(x[k][i], x[k + 1][i]);
  }
  for (int i = 1; i <= n; i++) up(a[i], x[0][i]);
  for (int i = 1; i <= n; i++) printf("%d\n", a[i]);
}
