#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int n, m, k;
string str[100];
char res[100][100];
int visited[100][100];
vector<pair<int, int> > v;
set<pair<int, int> > s;
vector<vector<pair<int, int> > > lakes;
set<pair<int, int> > store;
void dfs(int x, int y) {
  visited[x][y] = 1;
  v.push_back(make_pair(x, y));
  if (x != 0) {
    if (str[x - 1][y] == '.' && visited[x - 1][y] == 0) dfs(x - 1, y);
  }
  if (x != n - 1) {
    if (str[x + 1][y] == '.' && visited[x + 1][y] == 0) dfs(x + 1, y);
  }
  if (y != 0) {
    if (str[x][y - 1] == '.' && visited[x][y - 1] == 0) dfs(x, y - 1);
  }
  if (y != n - 1) {
    if (str[x][y + 1] == '.' && visited[x][y + 1] == 0) dfs(x, y + 1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> str[i];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res[i][j] = str[i][j];
      if (str[i][j] == '*') visited[i][j] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (str[0][i] == '.') s.insert(make_pair(0, i));
    if (str[n - 1][i] == '.') s.insert(make_pair(n - 1, i));
  }
  for (int i = 0; i < n; i++) {
    if (str[i][0] == '.') s.insert(make_pair(i, 0));
    if (str[i][m - 1] == '.') s.insert(make_pair(i, m - 1));
  }
  int flag;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] == 0) {
        dfs(i, j);
        flag = 0;
        for (int i = 0; i < (int)(v.size()); i++) {
          if (s.find(v[i]) != s.end()) flag = 1;
        }
        if (flag == 0) {
          lakes.push_back(v);
          store.insert(make_pair((int)(v.size()), (int)(lakes.size()) - 1));
        }
        v.clear();
      }
    }
  }
  int cnt, extra, ans = 0;
  cnt = (int)(lakes.size());
  extra = cnt - k;
  while (extra != 0) {
    set<pair<int, int> >::iterator it;
    it = store.begin();
    store.erase(it);
    int pos = it->second;
    for (int i = 0; i < (int)(lakes[pos].size()); i++) {
      pair<int, int> temp = lakes[pos][i];
      res[temp.first][temp.second] = '*';
    }
    extra--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (res[i][j] != str[i][j]) ans++;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) cout << res[i] << "\n";
  return 0;
}
