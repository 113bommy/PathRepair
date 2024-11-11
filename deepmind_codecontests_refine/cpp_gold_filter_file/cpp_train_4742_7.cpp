#include <bits/stdc++.h>
using namespace std;
int r;
int c;
bool valid(vector<vector<char>> adj, vector<vector<int>>& vis, int x, int y) {
  if (x < 0 or x >= r or y < 0 or y >= c or adj[x][y] == '.' or
      vis[x][y] == true)
    return false;
  return true;
}
void dfs(vector<vector<char>> adj, vector<vector<int>>& vis, int start,
         int end) {
  vis[start][end] = true;
  if (valid(adj, vis, start - 1, end)) dfs(adj, vis, start - 1, end);
  if (valid(adj, vis, start + 1, end)) dfs(adj, vis, start + 1, end);
  if (valid(adj, vis, start, end + 1)) dfs(adj, vis, start, end + 1);
  if (valid(adj, vis, start, end - 1)) dfs(adj, vis, start, end - 1);
}
int main() {
  int i, j;
  cin >> r >> c;
  vector<vector<char>> adj(r, vector<char>(c));
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++) cin >> adj[i][j];
  vector<vector<int>> vis(r, vector<int>(c, 0));
  int cnt = 0;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (vis[i][j] == 0 && adj[i][j] == 'B') {
        dfs(adj, vis, i, j);
        cnt += 1;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
