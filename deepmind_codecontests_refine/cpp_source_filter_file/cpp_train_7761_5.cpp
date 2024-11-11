#include <bits/stdc++.h>
using namespace std;
long long int n, m, k;
long long int flag, lake_size;
char a[55][55];
long long int vis[55][55];
long long int dx[] = {1, -1, 0, 0};
long long int dy[] = {0, 0, 1, -1};
bool check(long long int i, long long int j) {
  if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.' && vis[i][j] == 0)
    return true;
  return false;
}
void dfs(long long int i, long long int j) {
  vis[i][j] = 1;
  lake_size++;
  if (i == 0 || i == n - 1 || j == 0 || j == m - 1) flag = 1;
  for (long long int k = 0; k < 4; k++) {
    long long int x = i + dx[k];
    long long int y = j + dy[k];
    if (check(x, y)) dfs(x, y);
  }
}
void dfs0(long long int i, long long int j) {
  vis[i][j] = 1;
  a[i][j] = '*';
  for (long long int k = 0; k < 4; k++) {
    long long int x = i + dx[k];
    long long int y = j + dy[k];
    if (check(x, y)) dfs0(x, y);
  }
}
void solve() {
  cin >> n >> m >> k;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> a[i][j];
  long long int lakes = 0;
  vector<pair<long long int, pair<long long int, long long int>>> result;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < n; j++) {
      if (check(i, j)) {
        lake_size = 0;
        flag = 0;
        dfs(i, j);
        if (flag == 0) {
          lakes++;
          result.push_back(make_pair(lake_size, make_pair(i, j)));
        }
      }
    }
  sort(result.begin(), result.end());
  long long int cells = 0;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) vis[i][j] = 0;
  for (long long int i = 0; i < lakes - k; i++) {
    cells += result[i].first;
    dfs0(result[i].second.first, result[i].second.second);
  }
  cout << cells << '\n';
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) cout << a[i][j];
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int _t = 1;
  while (_t--) {
    solve();
  }
  return 0;
}
