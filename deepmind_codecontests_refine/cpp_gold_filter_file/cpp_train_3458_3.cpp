#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int inverse(long long int i) {
  if (i == 1) return 1;
  return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}
int main() {
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  }
  int ans = 0;
  int d[n + 1];
  for (int i = 1; i <= m; ++i) {
    int flag = 0;
    if (i == m) flag = 1;
    for (int j = 1; j <= n; ++j) d[j] = 0;
    for (int j = 1; j <= n; ++j) {
      if (a[j][i] % m == i % m && (a[j][i] - (i % m)) / m >= 0 + flag &&
          (a[j][i] - (i % m)) / m <= n - 1 + flag) {
        int des1 = (a[j][i] - (i % m)) / m;
        if (j - (des1 - flag) > 0) {
          d[j - (des1 - flag)]++;
        } else {
          d[n + (j - (des1 - flag))]++;
        }
      }
    }
    int min1 = MOD;
    for (int j = 1; j <= n; ++j) {
      if (n - d[j] + j - 1 < min1) min1 = (n - d[j] + j - 1);
    }
    ans += min1;
  }
  cout << ans << "\n";
}
