#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char> > g[105];
char dp[105][105][(int)('z' - 'a') + 4];
char getDp(int m, int l, int k) {
  if (dp[m][l][k] != 0) return dp[m][l][k];
  char ans = 'B';
  for (int i = 0; i < g[m].size(); i++) {
    if (k <= g[m][i].second) {
      char n = getDp(l, g[m][i].first, g[m][i].second);
      if (n == 'B') {
        ans = 'A';
        break;
      }
    }
  }
  dp[m][l][k] = ans;
  return ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int f, t;
    char c;
    cin >> f >> t >> c;
    g[f].push_back({t, c - 'a'});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << getDp(i, j, 0);
    }
    cout << endl;
  }
}
