#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 7;
long long read() {
  long long res = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (isdigit(c)) res = (res << 1) + (res << 3) + c - 48, c = getchar();
  return res * f;
}
long long ans;
int n, m;
long long f[maxn][maxn], g[maxn][maxn];
int main() {
  n = read(), m = read();
  for (int i = 2; i <= m; i++) f[1][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++)
      f[i][j] = (f[i - 1][j] + 2 * f[i][j - 1] - f[i][j - 2] + 1000000009) %
                1000000009;
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++) g[i][j] = (g[i - 1][j] + f[i][j]) % 1000000009;
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++)
      (ans += f[i][j] * g[n - i + 1][j] % 1000000009 * (m - j + 1) %
              1000000009) %= 1000000009;
  printf("%lld\n", ans);
  return 0;
}
