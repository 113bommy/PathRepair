#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const int MAXSIZE = 1e6;
using ll = long long;
using ld = long double;
using vint = vector<int>;
void precalc() {}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m + 4, 0);
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    v[val]++;
  }
  int res = 0;
  for (int i = 1; i <= m; ++i) {
    while (v[i] >= 7) {
      v[i] -= 3;
      res++;
    }
  }
  vector<vector<int> > dp(7, vector<int>(7, -INF));
  dp[v[0]][v[1]] = 0;
  for (int i = 0; i <= m; ++i) {
    vector<vector<int> > nx(7, vector<int>(7, -INF));
    for (int j = 0; j < 7; ++j) {
      for (int z = 0; z < 7; ++z) {
        for (int d = 0; d * 3 <= j; ++d) {
          for (int k = 0; k <= min(j - d * 3, min(z, v[i + 2])); ++k) {
            nx[z - k][v[i + 2] - k] =
                max(nx[z - k][v[i + 2] - k], dp[j][z] + d + k);
          }
        }
      }
    }
    dp = nx;
  }
  int val = 0;
  for (int i = 0; i < 7; ++i)
    for (int j = 0; j < 7; ++j) val = max(val, dp[i][j]);
  cout << res + val << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(9);
  precalc();
  solve();
  return 0;
}
