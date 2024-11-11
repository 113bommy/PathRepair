#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e3 + 10;
long long int dp[N][N];
long long int suffs[N][26], sufft[N][26];
const long long int inf = 1e10;
long long int n;
string s, t;
long long int dfs(long long int x, long long int y) {
  if (y == 0) {
    return 0;
  }
  long long int &an = dp[x][y];
  if (an != -1) {
    return an;
  }
  an = inf;
  long long int ch = t[x] - 'a';
  if (suffs[x + 1][ch] - sufft[y + 1][ch] > 0) {
    an = min(an, dfs(x, y - 1));
  }
  if (x > 0) {
    an = min(an, dfs(x - 1, y) + 1);
    if (s[x - 1] == t[y - 1]) {
      an = min(an, dfs(x - 1, y - 1));
    }
  }
  return an;
}
void solve() {
  cin >> n;
  cin >> s >> t;
  for (long long int i = 0; i <= n; i++) {
    for (long long int j = 0; j < 26; j++) {
      suffs[i][j] = sufft[i][j] = 0;
    }
  }
  for (long long int i = 0; i <= n; i++) {
    for (long long int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  for (long long int i = n; i >= 1; i--) {
    for (long long int j = 0; j < 26; j++) {
      sufft[i][j] = sufft[i + 1][j];
      suffs[i][j] = suffs[i + 1][j];
    }
    suffs[i][s[i - 1] - 'a']++;
    sufft[i][t[i - 1] - 'a']++;
  }
  long long int ans = dfs(n, n);
  if (ans >= inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
