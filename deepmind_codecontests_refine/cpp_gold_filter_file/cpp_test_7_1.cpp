#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 503;
int dp[2][N][N];
vector<int> pf(string s) {
  int n = int(s.size());
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dp[0][i][j] = dp[1][i][j] = INF;
  dp[0][0][0] = 0;
  auto pi = pf(t);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= n - m + 1; k++) dp[1][j][k] = INF;
    for (int j = 0; j <= m; j++) {
      for (char c : {'0', '1'}) {
        int nj = j;
        if (nj == m) nj = pi[m - 1];
        while (nj > 0 && t[nj] != c) nj = pi[nj - 1];
        if (t[nj] == c) nj++;
        int cost = (c != s[i]);
        int add = (nj == m);
        for (int k = 0; k <= n - m + 1; k++) {
          dp[1][nj][k + add] = min(dp[1][nj][k + add], dp[0][j][k] + cost);
        }
      }
    }
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= n - m + 1; k++) {
        dp[0][j][k] = dp[1][j][k];
      }
  }
  for (int k = 0; k <= n - m + 1; k++) {
    int ans = INF;
    for (int j = 0; j <= m; j++) ans = min(ans, dp[1][j][k]);
    if (ans >= INF)
      cout << -1 << ' ';
    else
      cout << ans << ' ';
  }
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
