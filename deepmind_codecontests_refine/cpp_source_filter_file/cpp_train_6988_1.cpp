#include <bits/stdc++.h>
using namespace std;
const int N = (5e5) + 322;
const long long INF = 2e18 + 17;
const int inf = 2e9 + 17;
const int MOD = 998244353;
const double eps = 1e-9;
int cnt;
string s;
int n, m, mn[100][100], l[100][100], dp[16][16][(1 << 16) + 23], a[100][11000],
    full;
int calc(int i, int j, int flag) {
  int curmn = inf;
  for (int x = 1; x <= m - flag; ++x) {
    curmn = min(curmn, abs(a[i][x] - a[j][x + flag]));
  }
  return curmn;
}
int f(int first, int last, int mask) {
  if (mask == full) return l[last][first];
  int &res = dp[first][last][mask];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i <= n - 1; ++i) {
    if (!(mask & (1 << i))) {
      res = max(min(f(first, i, (mask | (1 << i))), mn[last][i]), res);
    }
  }
  return res;
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  int mn2 = inf;
  if (n == 1) {
    for (int i = 1; i <= n - 1; ++i) {
      mn2 = min(mn2, a[1][i] - a[1][i + 1]);
    }
    cout << mn2;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      mn[i - 1][j - 1] = calc(i, j, 0);
      l[i - 1][j - 1] = calc(i, j, 1);
    }
  }
  memset(dp, -1, sizeof dp);
  full = (1 << n) - 1;
  int mx = 0;
  for (int i = 0; i <= n - 1; ++i) {
    mx = max(mx, f(i, i, (1 << i)));
  }
  cout << mx;
  return 0;
}
