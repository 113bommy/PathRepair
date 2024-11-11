#include <bits/stdc++.h>
using namespace std;
char v[64][64];
char s[64][64];
vector<pair<int, int> > ans;
void dfs(int xx, int yy) {
  if (s[xx + 1][yy] == 'U') {
    if (s[xx + 1][yy + 1] == 'L') dfs(xx + 1, yy + 1);
    ans.push_back(make_pair(xx + 1, yy));
    s[xx + 1][yy] = 'L';
    s[xx + 1][yy + 1] = 'R';
    s[xx + 2][yy] = 'L';
    s[xx + 2][yy + 1] = 'R';
  }
  ans.push_back(make_pair(xx, yy));
  s[xx][yy] = 'U';
  s[xx][yy + 1] = 'U';
  s[xx + 1][yy] = 'D';
  s[xx + 1][yy + 1] = 'D';
}
void dfs1(int xx, int yy) {
  if (s[xx][yy + 1] == 'L') {
    if (s[xx + 1][yy + 1] == 'U') dfs1(xx + 1, yy + 1);
    ans.push_back(make_pair(xx + 1, yy));
    s[xx][yy + 1] = 'U';
    s[xx][yy + 2] = 'U';
    s[xx + 1][yy + 1] = 'D';
    s[xx + 1][yy + 2] = 'D';
  }
  ans.push_back(make_pair(xx, yy));
  s[xx][yy] = 'L';
  s[xx][yy + 1] = 'R';
  s[xx + 1][yy] = 'L';
  s[xx + 1][yy + 1] = 'R';
}
int main(void) {
  int n, m;
  cin >> n >> m;
  int was = 0;
  for (int cs = 0; cs < 2; ++cs) {
    was = ans.size();
    for (int i = 1; i <= n; ++i) cin >> (s[i] + 1);
    if (n % 2 == 0) {
      for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
          if (s[i][j] == 'L') dfs(i, j);
    } else {
      for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
          if (s[i][j] == 'U') dfs1(i, j);
    }
  }
  cout << (ans.size()) << '\n';
  for (int i = 0; i < was; ++i)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  for (int i = ans.size() - 1; i >= was; --i)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  return 0;
}
