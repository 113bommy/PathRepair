#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 10;
vector<pair<long long int, char> > v[200];
long long int dp[200][200][150];
long long int fun(long long int x, long long int y, long long int val) {
  if (dp[x][y][val] != -1) return dp[x][y][val];
  long long int i, flag = 0, tmp;
  for (i = 0; i < v[x].size(); i++) {
    long long int child = v[x][i].first;
    long long int lol = (long long int)v[x][i].second;
    if (lol >= val) {
      tmp = fun(y, child, lol);
      if (!tmp) {
        flag = 1;
        break;
      }
    }
  }
  return dp[x][y][val] = flag;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  long long int i, j, n, m;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    long long int x, y;
    char c;
    cin >> x >> y >> c;
    v[x].push_back(make_pair(y, c));
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      long long int ans = fun(i, j, 0);
      if (ans)
        cout << "A";
      else
        cout << "B";
    }
    cout << "\n";
  }
  return 0;
}
