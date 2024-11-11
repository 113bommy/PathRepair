#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
struct edge {
  int v, u;
  char c;
  edge() {}
  edge(int vv, int uu, int cc) { v = vv, u = uu, c = cc; }
};
int n, m;
vector<edge> G[MAXN];
int dp[MAXN][MAXN][30];
bool dfs(int x, int y, char c) {
  if (dp[x][y][c - 'a'] != -1) return dp[x][y][c - 'a'];
  for (auto e : G[x]) {
    if (e.c >= c && dfs(y, e.u, e.c) == false) {
      dp[x][y][c - 'a'] = true;
      return true;
    }
  }
  return dp[x][y][c - 'a'] = false;
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(dp, 0xff, sizeof(dp));
  for (int ii = 0; ii < m; ii++) {
    int v, u;
    char c;
    scanf("%d %d %c\n", &v, &u, &c);
    G[v].push_back(edge(v, u, c));
  }
  for (int ii = 1; ii <= n; ii++) {
    for (int jj = 1; jj <= n; jj++) {
      if (dfs(ii, jj, 'a'))
        cout << 'A';
      else
        cout << 'B';
    }
    cout << endl;
  }
}
