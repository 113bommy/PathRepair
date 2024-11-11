#include <bits/stdc++.h>
using namespace std;
stringstream ss;
long long dp[512][512], n, m, mod;
char a[512][512];
long long g(int x) { return x * 1ll * (x - 1) / 2LL; }
long long f(int zero, int one) {
  if (!zero && !one) return 1;
  if (dp[zero][one] != -1) return dp[zero][one];
  long long ret = 0;
  if (zero > 1) ret = (ret + f(zero - 2, one + 2) * g(zero) % mod) % mod;
  if (zero && one)
    ret = (ret + f(zero - 1, one) * (zero * one % mod) % mod) % mod;
  if (one > 1) ret = (ret + f(zero, one - 2) * g(one) % mod) % mod;
  return dp[zero][one] = ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  long long cc[3] = {0};
  cin >> n >> m >> mod;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0, cnt; i < n; i++) {
    for (int j = cnt = 0; j < m; j++) cnt += (a[j][i] == '1');
    cc[cnt]++;
  }
  cout << f(cc[0], cc[1]) << endl;
  return 0;
}
