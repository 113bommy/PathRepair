#include <bits/stdc++.h>
using namespace std;
bool dp[105][105][27];
int in[105], vis[105][105][27];
int n, m;
struct node {
  int to, val;
};
vector<node> ac[105];
int cal[105];
void dfs(int v, int u, int temp) {
  if (vis[v][u][temp]) return;
  vis[v][u][temp] = 1;
  int w = 0;
  for (int i = 0; i < ac[v].size(); i++) {
    node temp1 = ac[v][i];
    int x = temp1.to, val = temp1.val;
    if (val >= temp) {
      dfs(u, x, val);
      if (dp[u][x][val] == false) w = 1;
    }
  }
  if (w == 0)
    dp[v][u][temp] = 0;
  else
    dp[v][u][temp] = 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    ac[a].push_back(node{b, c - 'a' + 1});
  }
  memset(dp, false, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dfs(i, j, 0);
      if (dp[i][j][0] == true)
        cout << "A";
      else
        cout << "B";
    }
    cout << endl;
  }
  return 0;
}
