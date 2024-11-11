#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, k;
char a[N][N];
bool vis[N][N];
vector<pair<int, int>> st;
void dfs(int i, int j) {
  if (vis[i][j]) return;
  vis[i][j] = 1;
  if (i - 1 >= 0 && a[i - 1][j] == '.') dfs(i - 1, j);
  if (j - 1 >= 0 && a[i][j - 1] == '.') dfs(i, j - 1);
  if (j + 1 < m && a[i][j + 1] == '.') dfs(i, j + 1);
  if (i + 1 < n && a[i + 1][j] == '.') dfs(i + 1, j);
  st.push_back({i, j});
}
int main() {
  cin >> n >> m >> k;
  pair<int, int> pos = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '.' && pos.first == -1) pos = {i, j};
    }
  }
  dfs(pos.first, pos.second);
  if (k) {
    for (auto x : st) {
      a[x.first][x.second] = 'X';
      k--;
      if (!k) break;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
}
