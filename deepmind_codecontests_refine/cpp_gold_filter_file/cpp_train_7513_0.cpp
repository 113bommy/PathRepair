#include <bits/stdc++.h>
using namespace std;
const int LEN = (int)1e6;
int n, m;
string a[LEN];
vector<char> dp[LEN];
vector<int> s;
void dfs(int i, int j) {
  if (dp[i][j] != -1) {
    return;
  }
  if (a[i][j] == '#') {
    dp[i][j] = 0;
    return;
  }
  if (i + 1 < n) {
    dfs(i + 1, j);
    dp[i][j] = dp[i + 1][j];
  }
  if (j + 1 < m) {
    dfs(i, j + 1);
    dp[i][j] = max(dp[i][j], dp[i][j + 1]);
  }
  if (dp[i][j] != 0 && (i != 0 || j != 0) && (i + 1 != n || j + 1 != m)) {
    s[i + j]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) dp[i].assign(m, -1);
  s.assign(n + m, 0);
  dp[n - 1][m - 1] = 1;
  dfs(0, 0);
  if (dp[0][0] == 0) {
    cout << "0\n";
    return 0;
  }
  for (auto i : s) {
    if (i == 1) {
      cout << "1\n";
      return 0;
    }
  }
  cout << "2\n";
  return 0;
}
