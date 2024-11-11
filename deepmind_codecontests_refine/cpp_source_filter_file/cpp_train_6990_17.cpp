#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 510, LOG = 20;
int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];
bool dp[MAXN][1024];
int par[MAXN][1024];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> A[i][j];
      for (int x = 0; x < 1024; x++)
        if (dp[i - 1][x]) {
          dp[i][x ^ A[i][j]] = 1;
          par[i][x ^ A[i][j]] = j;
        }
    }
  }
  for (int i = 1; i < 1024; i++)
    if (dp[n][i]) {
      puts("TAK");
      vector<int> out;
      for (int x = i, j = n; j; x ^= A[j][par[j][x]], j--)
        out.push_back(par[j][x]);
      reverse(out.begin(), out.end());
      for (int x : out) cout << x << ' ';
      return 0;
    }
  return cout << "NIE" << '\n', 0;
  return 0;
}
