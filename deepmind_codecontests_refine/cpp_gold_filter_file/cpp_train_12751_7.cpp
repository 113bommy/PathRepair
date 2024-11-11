#include <bits/stdc++.h>
using namespace std;
long long n, m, b, mod;
long long ans = 0;
vector<int> a;
int main() {
  cin >> n >> m >> b >> mod;
  a.resize(n + 1);
  long long d[2][m + 1][b + 1];
  for (int i = 0; i <= 1; i++)
    for (int y = 0; y <= m; y++)
      for (int k = 0; k <= b; k++) d[i][y][k] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= 1; i++) {
    if (a[i] <= b) d[i][1][a[i]]++;
    d[i][0][0] = 1;
  }
  for (int i = 0; i <= b; i++) d[0][0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int y = 0; y <= m; y++)
      for (int k = 1; k <= b; k++) d[i % 2][y][k] = 0;
    for (int y = 1; y <= m; y++) {
      for (int k = 0; k <= b; k++) {
        if (k - a[i] >= 0)
          d[i % 2][y][k] = d[(i - 1) % 2][y][k] + d[i % 2][y - 1][k - a[i]];
        else
          d[i % 2][y][k] = d[(i - 1) % 2][y][k];
        d[i % 2][y][k] %= mod;
      }
    }
  }
  for (int i = 0; i <= b; i++) {
    ans += d[n % 2][m][i];
    ans %= mod;
  }
  cout << ans;
  return 0;
}
