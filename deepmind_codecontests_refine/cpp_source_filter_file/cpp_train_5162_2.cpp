#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 2e5 + 5;
ll sol;
int n, k;
ll dp1[MXN][5];
ll dp2[MXN][5];
vector<int> adj[MXN];
void dfs(int x, int p) {
  dp1[x][0] = 1;
  for (int y : adj[x]) {
    if (y == p) continue;
    dfs(y, x);
    sol += dp1[x][0] * dp1[y][0];
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        sol += dp1[x][i] * dp2[y][j];
        sol += dp2[x][i] * dp1[y][j];
        if (i && j && i + 1 + j <= k) {
          sol -= dp1[x][i] * dp1[y][j];
        }
      }
    }
    for (int i = 0; i < k; ++i) {
      dp1[x][(i + 1) % k] += dp1[y][i];
      dp2[x][(i + 1) % k] += dp2[y][i];
    }
    dp2[x][1] += dp1[y][0];
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  cout << sol << '\n';
}
