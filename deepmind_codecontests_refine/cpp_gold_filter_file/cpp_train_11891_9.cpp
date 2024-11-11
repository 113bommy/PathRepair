#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int mod = 1000000000 + 7;
long long c[maxn][maxn];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < maxn; i++) {
    c[0][i] = 1;
    c[i][i] = 1;
  }
  for (int i = 1; i < maxn; i++)
    for (int j = 1; j < maxn; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i][j - 1]) % mod;
  k *= 2;
  if (k > max(m, n))
    cout << 0;
  else {
    long long ans = (c[k][n - 1] * c[k][m - 1]) % mod;
    cout << ans;
  }
  return 0;
}
