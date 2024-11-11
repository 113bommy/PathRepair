#include <bits/stdc++.h>
using namespace std;
int n, m, sa = 0, g[1010][1010];
int cost[1010][1010];
string s[1010];
map<int, int> mp;
bool vis[1010][1010];
vector<pair<int, int>> v;
void dfs(int i, int j) {
  if (i == -1 || i == n || j == -1 || j == n || s[i][j] == '*' || vis[i][j])
    return;
  vis[i][j] = 1;
  sa++;
  v.push_back({i, j});
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  int as = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.' && !vis[i][j]) {
        v.clear();
        sa = 0;
        dfs(i, j);
        for (int i = 0; i < v.size(); ++i) {
          cost[v[i].first][v[i].second] = sa;
          g[v[i].first][v[i].second] = as;
        }
        as++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') {
        mp.clear();
        int op = 1;
        if (i + 1 != n && s[i + 1][j] != '*') {
          op += cost[i + 1][j];
          mp[g[i + 1][j]] = 1;
        }
        if (i - 1 != -1 && !mp[g[i - 1][j]] && s[i - 1][j] != '*') {
          op += cost[i + 1][j];
          mp[g[i - 1][j]] = 1;
        }
        if (j - 1 != -1 && !mp[g[i][j - 1]] && s[i][j - 1] != '*') {
          op += cost[i][j - 1];
          mp[g[i][j - 1]] = 1;
        }
        if (j + 1 != -1 && !mp[g[i][j + 1]] && s[i][j + 1] != '*') {
          op += cost[i][j + 1];
          mp[g[i][j + 1]] = 1;
        }
        cout << op % 10;
      } else {
        cout << '.';
      }
    }
    cout << endl;
  }
}
