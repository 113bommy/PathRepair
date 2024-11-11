#include <bits/stdc++.h>
using namespace std;
const short sl = 2;
const int mod[] = {1000005277, 1000007277};
int n, m;
vector<vector<char> > a;
vector<vector<bool> > vis;
vector<vector<int> > op[sl], dp[sl];
bool bfs() {
  if (a[1][1] == '#' || a[n][m] == '#') return false;
  queue<int> qx, qy;
  vis[1][1] = true;
  qx.push(1), qy.push(1);
  int u, v, uu, vv;
  while (!qx.empty()) {
    u = qx.front(), qx.pop();
    v = qy.front(), qy.pop();
    uu = u + 1, vv = v;
    if (!vis[uu][vv] && a[uu][vv] == '.') {
      vis[uu][vv] = true;
      qx.push(uu), qy.push(vv);
    }
    uu = u, vv = v + 1;
    if (!vis[uu][vv] && a[uu][vv] == '.') {
      vis[uu][vv] = true;
      qx.push(uu), qy.push(vv);
    }
  }
  return vis[n][m];
}
int main() {
  scanf("%d%d", &n, &m);
  a.resize(n + 2);
  vis.resize(n + 2);
  for (short i = 0; i < sl; ++i) op[i].resize(n + 2), dp[i].resize(n + 2);
  for (int i = 0; i <= n + 1; ++i) {
    a[i].resize(m + 2);
    vis[i].resize(m + 2);
    for (short j = 0; j < sl; ++j)
      op[j][i].resize(m + 2), dp[j][i].resize(m + 2);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf(" %c", &a[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i == 1 && j == 1)
        for (short z = 0; z < sl; ++z) op[z][i][j] = (a[i][j] == '.' ? 1 : 0);
      else
        for (short z = 0; z < sl; ++z)
          op[z][i][j] =
              (a[i][j] == '.' ? (op[z][i - 1][j] + op[z][i][j - 1]) % mod[z]
                              : 0);
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i == 1 && j == 1)
        for (short z = 0; z < sl; ++z) op[z][i][j] = (a[i][j] == '.' ? 1 : 0);
      else
        for (short z = 0; z < sl; ++z)
          op[z][i][j] =
              (a[i][j] == '.' ? (op[z][i - 1][j] + op[z][i][j - 1]) % mod[z]
                              : 0);
    }
  for (int i = n; i; --i)
    for (int j = m; j; --j) {
      if (i == n && j == m)
        for (short z = 0; z < sl; ++z) dp[z][i][j] = (a[i][j] == '.' ? 1 : 0);
      else
        for (short z = 0; z < sl; ++z)
          dp[z][i][j] =
              (a[i][j] == '.' ? (dp[z][i + 1][j] + dp[z][i][j + 1]) % mod[z]
                              : 0);
    }
  if (bfs()) {
    bool k;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (i == 1 && j == 1) continue;
        if (i == n && j == m) continue;
        k = true;
        for (short z = 0; z < sl; ++z)
          k &= (op[z][i][j] * dp[z][i][j]) % mod[z] == op[z][n][m];
        if (k) {
          puts("1");
          return 0;
        }
      }
    puts("2");
  } else
    puts("0");
}
