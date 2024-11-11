#include <bits/stdc++.h>
using namespace std;
const int size = 5005;
const int mo = 1000000007;
int n, a, b, k, ans;
int f[size][size], s[size][size];
int main() {
  cin >> n >> a >> b >> k;
  f[0][a] = 1;
  for (int r__ = (n), i = (a); i <= r__; i++) s[0][i] = 1;
  for (int r__ = (k), i = (1); i <= r__; i++) {
    for (int r__ = (n), j = (1); j <= r__; j++) {
      if (j == b)
        f[i][j] = 0;
      else if (j < b)
        f[i][j] = (s[i - 1][(b + j - 1) / 2] - f[i - 1][j] + mo) % mo;
      else
        f[i][j] = ((s[i - 1][n] - s[i - 1][(b + j + 1) / 2] + mo) % mo -
                   f[i - 1][j] + mo) %
                  mo;
      s[i][j] = (s[i][j - 1] + f[i][j]) % mo;
    }
  }
  int ans = 0;
  for (int r__ = (n), j = (1); j <= r__; j++) ans = (ans + f[k][j]) % mo;
  cout << ans << endl;
  return 0;
}
