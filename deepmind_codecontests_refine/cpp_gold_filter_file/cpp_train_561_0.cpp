#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<string> g;
vector<vector<bool> > visited;
void dfs(int y, int x) {
  if (visited[y][x]) return;
  visited[y][x] = true;
  if (x > 0 && g[y][x - 1] == '.') dfs(y, x - 1);
  if (x < m - 1 && g[y][x + 1] == '.') dfs(y, x + 1);
  if (y > 0 && g[y - 1][x] == '.') dfs(y - 1, x);
  if (y < n - 1 && g[y + 1][x] == '.') dfs(y + 1, x);
  if (k > 0) {
    g[y][x] = 'X';
    k--;
  }
}
int main() {
  cin >> n >> m >> k;
  copy_n(istream_iterator<string>(cin), n, back_inserter(g));
  fill_n(back_inserter(visited), n, vector<bool>(m, false));
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y) {
      if (g[y][x] == '.') {
        dfs(y, x);
        for (int i = 0; i < n; ++i) cout << g[i] << endl;
        return 0;
      }
    }
  }
  return 0;
}
