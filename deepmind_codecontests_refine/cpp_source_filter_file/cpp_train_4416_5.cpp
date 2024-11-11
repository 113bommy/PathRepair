#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, f[2][3030][3030];
char s[3030][3030];
void ical(int o, int u, int v) {
  int i, j;
  if (s[u][v] == '#') f[o][u][v] = 1;
  s[u][v] = '#';
  for (i = u; i <= n; i++)
    for (j = v; j <= m; j++)
      if (s[i][j] == '.') f[o][i][j] = (f[o][i - 1][j] + f[o][i][j - 1]) % mod;
}
void iWork() {
  cin >> n >> m;
  int i, j;
  for (i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  ical(0, 1, 2);
  ical(1, 2, 1);
  long long a = f[0][n - 1][m], b = f[1][n][m - 1], c = f[0][n][m - 1],
            d = f[1][n - 1][m];
  long long ans = ((a * b % mod - c * d % mod) % mod + mod) % mod;
  cout << ans << endl;
}
int main() {
  iWork();
  return 0;
}
