#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1005, M = 1000000009;
long long n, m, f[2][2][31][31][31], ans;
int main() {
  cin >> n >> m;
  f[0][1][0][0][0] = 1;
  for (long long i = 0, cur = 0; i < n; cur = (++i) & 1) {
    for (long long k = 0; k <= 1; k++)
      for (long long a = 0; a <= m; a++)
        for (long long b = 0; b <= m; b++)
          for (long long c = 0; c <= m; c++) {
            long long x = f[cur][k][a][b][c], d;
            x %= M;
            if (x == 0) continue;
            if (k)
              d = 1;
            else
              d = m;
            f[cur ^ 1][a < m][min(b + 1, m)][min(c + 1, m)][d] += x;
            f[cur ^ 1][b < m][min(a + 1, m)][min(c + 1, m)][d] += x;
            f[cur ^ 1][c < m][min(a + 1, m)][min(b + 1, m)][d] += x;
            f[cur ^ 1][k][min(a + 1, m)][min(b + 1, m)][min(c + 1, m)] += x;
          }
    memset(f[cur], 0, sizeof(f[cur]));
  }
  for (long long a = 0; a <= 1; a++)
    for (long long b = 0; b <= m; b++)
      for (long long c = 0; c <= m; c++)
        for (long long d = 0; d <= m; d++)
          if (a || b < m || c < m || d < m)
            ans = (ans + f[n & 1][a][b][c][d]) % M;
  cout << ans;
  return 0;
}
