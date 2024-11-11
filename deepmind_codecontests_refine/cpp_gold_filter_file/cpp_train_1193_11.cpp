#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 25 + 10, maxm = 1e3 + 10, lg = 21, mod = 1e9 + 7,
                inf = 1e18;
long long n, m;
struct MAT {
  long long a[maxn][maxn];
  MAT() { memset(a, 0, sizeof(a)); }
};
MAT I() {
  MAT r;
  for (int i = 0; i <= m; i++) r.a[i][i] = 1;
  return r;
}
MAT operator*(const MAT& a, const MAT& b) {
  MAT r;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= m; k++)
        r.a[i][j] = (r.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
  return r;
}
MAT dp[maxn << 1][maxn], g1[maxn], g2[maxn];
long long a[maxn << 1];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  long long nn = 0;
  while (n) a[nn++] = n % m, n /= m;
  nn--;
  for (int i = 0; i < m; i++) {
    dp[0][i] = I();
    for (int j = 0; j <= m; j++) dp[0][i].a[j][i] = 1;
  }
  for (int i = 1; i <= nn; i++) {
    g1[0] = g2[m] = I();
    for (int j = 1; j < m; j++) g1[j] = g1[j - 1] * dp[i - 1][j - 1];
    for (int j = m - 1; j >= 0; j--) g2[j] = dp[i - 1][j] * g2[j + 1];
    for (int j = 0; j < m; j++) dp[i][j] = g2[j] * g1[j];
  }
  MAT res;
  res.a[0][m] = 1;
  for (int i = nn, nw = 0; i >= 0; i--)
    for (int j = 0; j < a[i]; j++) res = res * dp[i][nw], nw = (nw + 1) % m;
  long long ans = 0;
  for (int i = 0; i <= m; i++) ans = (ans + res.a[0][i]) % mod;
  cout << ans;
  return 0;
}
