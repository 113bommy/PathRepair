#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000007LL;
const int maxn = 1005;
int n, m, k;
long long f[maxn][maxn];
int main() {
  cin >> n >> m >> k;
  f[0][0] = 1LL;
  for (int i = 1; i < maxn; i++) {
    long long s = 0;
    for (int j = 0; j < maxn; j++) {
      f[i][j] = s;
      s = (s + f[i - 1][j]) % P;
    }
  }
  long long res1 = 0LL;
  for (int l = 0; l <= n; l++)
    for (int r = l + 1; r <= n; r++) res1 = (res1 + f[k][l] * f[k][n - r]) % P;
  long long res2 = 0LL;
  for (int l = 0; l <= m; l++)
    for (int r = l + 1; r <= n; r++) res2 = (res2 + f[k][l] * f[k][m - r]) % P;
  long long res = (res1 * res2) % P;
  cout << res << "\n";
}
