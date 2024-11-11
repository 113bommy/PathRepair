#include <bits/stdc++.h>
using namespace std;
const int N = 2048, INF = 2e9;
int n;
string s, t;
int dp[N][N];
int sufs[N][30], suft[N][30];
int go(int i, int j) {
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  if (j == 0) return ans = 0;
  ans = INF;
  if (i) {
    ans = 1 + go(i - 1, j);
    if (s[i - 1] == t[j - 1]) ans = min(ans, go(i - 1, j - 1));
  }
  int x = t[j - 1] - 'a';
  if (sufs[i][x] > suft[j][x]) ans = min(ans, go(i, j - 1));
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> s >> t;
    for (int i = int(0); i < int(30); ++i) sufs[n][i] = suft[n][i] = 0;
    for (int i = n - 1; i >= 0; --i) {
      for (int c = 0; c < 26; ++c) {
        sufs[i][c] = sufs[i + 1][c];
        suft[i][c] = suft[i + 1][c];
      }
      sufs[i][s[i] - 'a']++;
      suft[i][t[i] - 'a']++;
    }
    for (int i = int(0); i < int(n + 1); ++i)
      for (int j = int(0); j < int(n + 1); ++j) dp[i][j] = -1;
    int ans = go(n, n);
    if (ans >= INF) ans = -1;
    cout << ans << endl;
  }
  return 0;
}
