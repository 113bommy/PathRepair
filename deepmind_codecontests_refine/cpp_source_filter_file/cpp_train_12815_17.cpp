#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 4e1 + 10, maxm = 1e3 + 10, lg = 21, mod = 1e9 + 7,
                inf = 1e18;
long long n, a[maxn], nx[maxn][2], f[maxn], dp[maxn][maxn];
string s;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= (long long)(s.size()); i++) a[i] = s[i - 1] - '0';
  nx[0][a[1]] = 1;
  for (int i = 2; i <= (long long)(s.size()); i++)
    nx[i - 1][a[i]] = i, nx[i - 1][1 - a[i]] = nx[f[i - 1]][1 - a[i]],
           f[i] = nx[f[i + 1]][a[i]];
  for (bool b : {0, 1})
    nx[(long long)(s.size())][b] = nx[f[(long long)(s.size())]][b];
  long long ans = 0;
  for (int i = 0; i < (long long)(s.size()); i++) {
    memset(dp, 0, sizeof(dp));
    dp[0][i] = 1;
    for (int j = 0; j < n; j++)
      for (int k = 0; k < (long long)(s.size()); k++)
        for (auto b : {0, 1}) dp[j + 1][nx[k][b]] += dp[j][k];
    ans += dp[n][i];
  }
  cout << (1 << n) - ans;
  return 0;
}
