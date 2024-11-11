#include <bits/stdc++.h>
using namespace std;
void read(signed& x) { scanf("%d", &x); }
void read(long long& x) { scanf("%lld", &x); }
int n, m;
int f[156][156][2][2];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
    for (int j = i; j <= m; ++j) f[i][j][1][1] = 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cur = 0;
    for (int l = 1; l <= m; ++l)
      for (int r = l; r <= m; ++r)
        for (int k = 0; k <= 1; ++k)
          for (int kk = 0; kk <= 1; ++kk)
            (cur = (cur + f[l][r][k][kk]) % 1000000007);
    (ans = (ans + cur * (n - i + 1) % 1000000007) % 1000000007);
    for (int l = 2; l <= m; ++l)
      for (int r = l; r <= m; ++r)
        for (int k = 0; k <= 1; ++k)
          (f[l][r][0][k] =
               (f[l][r][0][k] +
                (f[l - 1][r][0][k] + f[l - 1][r][1][k]) % 1000000007) %
               1000000007);
    for (int l = 1; l <= m; ++l)
      for (int r = m - 1; r >= l; --r)
        for (int k = 0; k <= 1; ++k)
          (f[l][r][k][0] =
               (f[l][r][k][0] +
                (f[l][r + 1][k][0] + f[l][r + 1][k][1]) % 1000000007) %
               1000000007);
    for (int l = m - 1; l >= 1; --l)
      for (int r = l + 1; r <= m; ++r)
        for (int k = 0; k <= 1; ++k)
          (f[l][r][1][k] = (f[l][r][1][k] + f[l + 1][r][1][k]) % 1000000007);
    for (int l = m; l >= 1; --l)
      for (int r = l + 1; r <= m; ++r)
        for (int k = 0; k <= 1; ++k)
          (f[l][r][k][1] = (f[l][r][k][1] + f[l][r - 1][k][1]) % 1000000007);
  }
  cout << ans << endl;
}
