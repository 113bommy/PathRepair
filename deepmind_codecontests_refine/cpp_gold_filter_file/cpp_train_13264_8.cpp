#include <bits/stdc++.h>
using namespace std;
const int N = 45;
int n, m, q, mat[N][N], dp[N][N][N][N];
char arr[N][N];
bool query(int a, int b, int c, int d) {
  int res = mat[c][d];
  if (a) res -= mat[a - 1][d];
  if (b) res -= mat[c][b - 1];
  if (a && b) res += mat[a - 1][b - 1];
  return !res;
}
int sol(int a, int b, int c, int d) {
  int &ret = dp[a][b][c][d];
  if (~ret) return ret;
  ret = query(a, b, c, d);
  if (c > a) ret += sol(a, b, c - 1, d);
  if (d > b) ret += sol(a, b, c, d - 1);
  if (c > a && d > b) ret -= sol(a, b, c - 1, d - 1);
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> arr[i][j];
  for (int i = 0; i < m; ++i) mat[0][i] = arr[0][i] - '0';
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < m; ++j) mat[i][j] = (arr[i][j] - '0') + mat[i - 1][j];
  for (int i = 0; i < n; ++i)
    for (int j = 1; j < m; ++j) mat[i][j] += mat[i][j - 1];
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    int ans = 0;
    for (int i = a; i <= c; ++i)
      for (int j = b; j <= d; ++j) ans += sol(i, j, c, d);
    cout << ans << '\n';
  }
  return 0;
}
