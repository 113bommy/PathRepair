#include <bits/stdc++.h>
using namespace std;
int G[110][110];
string t[110];
string dist[110];
bool used[110];
int n, m;
int memo[100][100][26][2];
int dfs(int a, int b, int c, bool f) {
  if (memo[a][b][c][f] != -100) return memo[a][b][c][f];
  if (!f) {
    int ret = 0;
    int now;
    for (int i = 0; i < n; i++) {
      if (c <= G[a][i]) {
        now = dfs(i, b, G[a][i], 1);
        if (now == 1) ret = 1;
      }
    }
    return memo[a][b][c][f] = ret;
  } else {
    int ret = 1;
    int now;
    for (int i = 0; i < n; i++) {
      if (c <= G[b][i]) {
        now = dfs(a, i, G[b][i], 0);
        if (now == 0) ret = 0;
      }
    }
    return memo[a][b][c][f] = ret;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int a, b;
  char x;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) G[i][j] = -10;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> x;
    a--;
    b--;
    G[a][b] = (x - 'a') + 1;
  }
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      for (int k = 0; k < 26; k++)
        for (int l = 0; l < 2; l++) memo[i][j][k][l] = -100;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int now = dfs(i, j, 0, 0);
      if (now == 1)
        cout << "A";
      else
        cout << "B";
    }
    cout << endl;
  }
  return 0;
}
