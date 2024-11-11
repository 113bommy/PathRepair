#include <bits/stdc++.h>
using namespace std;
const int N = 2020, P = 1e9 + 7, B = 19260817;
int n, m, ans, p[N], g[2][2][N], h[N], f[2][N][N], a[2][N];
char s[2][N], t[N];
int hs(int l, int r) {
  return (h[r] - 1ll * h[l - 1] * p[r - l + 1] % P + P) % P;
}
int gs(int l, int r, int k, int b) {
  if (b == 0)
    return (g[0][k][r] - 1ll * g[0][k][l - 1] * p[r - l + 1] % P + P) % P;
  if (b == 1)
    return (g[1][k][l] - 1ll * g[1][k][r + 1] * p[r - l + 1] % P + P) % P;
}
int cal(int l, int r, int k, int b) {
  return (1ll * gs(l, r, k, !b) * p[r - l + 1] % P + gs(l, r, !k, b)) % P;
}
void work() {
  reverse(t + 1, t + m + 1);
  for (int i = 1; i <= m; i++) h[i] = (1ll * h[i - 1] * B % P + t[i]) % P;
  f[0][0][0] = f[1][0][0] = 1;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= 1; k++)
        a[k][j] = j ? f[k][i - 1][j - 1] * (s[k][i] == t[j]) : 0;
    f[0][i][0] = f[1][i][0] = 1;
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= 1; k++) {
        f[k][i][j] = j ? (a[!k][j - 1] * (s[k][i] == t[j]) + a[k][j]) % P : 0;
        if (j / 2 > 1 && j % 2 == 0 && i >= j / 2)
          f[k][i][j] += (cal(i - j / 2 + 1, i, !k, 0) == h[j]);
        if (j < m && (m - j) % 2 == 0 && n - i >= (m - j) / 2)
          (ans += f[k][i][j] *
                  (cal(i + 1, i + (m - j) / 2, k, 1) == hs(j + 1, m))) %= P;
      }
    for (int k = 0; k <= 1; k++)
      (ans += f[k][i][m - 1] * (s[k][i + 1] == t[m])) %= P;
  }
}
int main() {
  scanf("%s%s%s", s[0] + 1, s[1] + 1, t + 1);
  n = strlen(s[0] + 1);
  m = strlen(t + 1);
  if (m == 1) {
    for (int i = 1; i <= n; i++)
      for (int k = 0; k <= 1; k++) ans += s[k][i] == t[1];
    cout << ans << '\n';
    return 0;
  }
  p[0] = 1;
  for (int i = 1; i <= max(n, m); i++) p[i] = 1ll * p[i - 1] * B % P;
  for (int i = 1; i <= n; i++)
    for (int k = 0; k <= 1; k++)
      g[0][k][i] = (1ll * g[0][k][i - 1] * B % P + s[k][i]) % P;
  for (int i = n; i >= 1; i--)
    for (int k = 0; k <= 1; k++)
      g[1][k][i] = (1ll * g[1][k][i + 1] * B % P + s[k][i]) % P;
  work();
  work();
  if (m % 2 == 0)
    for (int i = 1; i <= n - m / 2 + 1; i++) {
      int j = i + m / 2 - 1;
      for (int k = 0; k <= 1; k++) {
        ans += cal(i, j, k, 0) == h[m];
        if (m > 2) ans += cal(i, j, k, 1) == h[m];
      }
    }
  cout << ans % P << '\n';
}
