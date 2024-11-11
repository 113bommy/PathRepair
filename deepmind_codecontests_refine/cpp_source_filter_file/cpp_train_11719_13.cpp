#include <bits/stdc++.h>
using namespace std;
string s;
int arr[30][30];
long long dp[105][105][30];
bool vis[105][105][30];
long long solve(int i, int k, int pre) {
  if (i == s.size()) return 0;
  long long &ret = dp[i][k][pre];
  if (vis[i][k][pre]) return ret;
  vis[i][k][pre] = 1;
  ret = 0;
  for (int j = 0; j < 26; j++) {
    if (j != s[i] - 'a' && k > 0)
      ret = max(ret, solve(i + 1, k - 1, j) + arr[pre][j]);
    else if (j == s[i] - 'a')
      ret = max(ret, solve(i + 1, k, j) + arr[pre][j]);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k, n, c;
  char x, y;
  cin >> s >> k >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> c;
    arr[x - 'a'][y - 'a'] = c;
  }
  cout << solve(0, k, 27) << endl;
  return 0;
}
