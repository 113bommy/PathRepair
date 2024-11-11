#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const int N = 3000 + 10;
const long long MOD = 998244353;
const long long INF = 1000000010;
const long long LOG = 25;
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
int mul(int a, int b) { return (a * 1ll * b) % MOD; }
int POW(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
int dp[N][N], n, m, a[200010], sm, sm2;
bool mark[200010];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mark[i] = x;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mark[i])
      sm += a[i];
    else
      sm2 += a[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= i; j++) {
      int x = i - j;
      if (x <= sm2)
        dp[i + 1][j] =
            add(dp[i + 1][j],
                mul(dp[i][j], mul(sm2 - x, POW(sm + sm2 + j - x, MOD - 2))));
      dp[i + 1][j + 1] =
          add(dp[i + 1][j + 1],
              mul(dp[i][j], mul(sm + j, POW(sm + sm2 + j - x, MOD - 2))));
    }
  int E = 0;
  for (int i = 0; i <= m; i++) {
    E = add(E, mul(dp[m][i], sm + i));
  }
  E = mul(E, POW(sm, MOD - 2));
  int Em = 0;
  for (int i = 0; i <= m; i++) {
    int x = m - i;
    if (x >= sm2) continue;
    Em = add(Em, mul(dp[m][i], sm2 - x));
  }
  Em = mul(Em, POW(sm2, MOD - 2));
  for (int i = 1; i <= n; i++) {
    if (mark[i])
      cout << mul(a[i], E) << '\n';
    else
      cout << mul(a[i], Em) << '\n';
  }
  return 0;
}
