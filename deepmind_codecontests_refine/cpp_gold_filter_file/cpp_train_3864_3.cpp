#include <bits/stdc++.h>
using namespace std;
int n, k;
long long f[1005][2005][4];
int main() {
  f[1][1][0] = f[1][1][1] = f[1][2][2] = f[1][2][3] = 1;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) f[i][1][0] = f[i][1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j - 1][1] + f[i - 1][j][2] +
                    f[i - 1][j][3]) %
                   998244353;
      f[i][j][1] = (f[i - 1][j - 1][0] + f[i - 1][j][1] + f[i - 1][j][2] +
                    f[i - 1][j][3]) %
                   998244353;
      f[i][j][2] = (f[i - 1][j - 1][0] + f[i - 1][j - 1][1] + f[i - 1][j][2] +
                    f[i - 1][j - 2][3]) %
                   998244353;
      f[i][j][3] = (f[i - 1][j - 1][0] + f[i - 1][j - 1][1] +
                    f[i - 1][j - 2][2] + f[i - 1][j][3]) %
                   998244353;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 3; i++) ans = (ans + f[n][k][i]) % 998244353;
  cout << ans;
}
