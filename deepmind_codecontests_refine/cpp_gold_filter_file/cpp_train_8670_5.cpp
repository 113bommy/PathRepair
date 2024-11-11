#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MAX = 2e5 + 1e4, MOD = 1e9 + 7, MAXL = 25;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o;
  return;
}
long long a[MAX], dp[4][MAX], b[MAX], f[MAX], cnt = 0;
map<long long, long long> mp;
long long p(int x, int y) {
  if (y == 0) return 1;
  long long z = p(x, y / 2);
  z = (z * z) % MOD;
  if (y % 2 == 1) z = (z * x) % MOD;
  return z;
}
long long c(long long n, long long k) {
  return (((f[n] * p(f[k], MOD - 2)) % MOD) * p(f[n - k], MOD - 2)) % MOD;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x = 0, k, ans = 0;
  cin >> n >> k;
  f[0] = 1;
  for (int i = 1; i <= 2e5; i++) f[i] = (f[i - 1] * i) % MOD;
  for (int i = 1; i <= n; i++) {
    long long y, t = 1, z;
    cin >> y;
    z = y;
    while (y && t) {
      if (y % 10 != 4 && y % 10 != 7) t = 0;
      y /= 10;
    }
    if (t) {
      if (mp[z] == 0) {
        cnt++;
        b[cnt] = 1;
        mp[z] = cnt;
      } else
        b[mp[z]]++;
    } else
      x++;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= 1024; i++) {
    dp[i % 2][0] = 1;
    for (int j = 1; j <= k; j++)
      dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] * b[i] + dp[(i - 1) % 2][j]) % MOD;
  }
  for (int i = 0; i <= min(k, x); i++)
    ans = (ans + ((dp[0][k - i] * c(x, i)) % MOD)) % MOD;
  cout << ans;
  return 0;
}
