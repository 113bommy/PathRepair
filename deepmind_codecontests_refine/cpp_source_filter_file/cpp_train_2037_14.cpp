#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 7;
const int K = 20 + 7;
const int M = (int)1e9 + 7;
int n;
int k;
int dp[N][K][2];
int sol[K][2];
vector<int> g[N];
void addup(int i, int j, int x, int y) {
  x = (long long)x * y % M;
  sol[i][j] = (sol[i][j] + x) % M;
}
void add(int a, int b) {
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= k; j++) {
      addup(min(i, j + 1), 0, dp[a][i][0], dp[b][j][0]);
      if (i + j + 1 <= k) {
        addup(i, 0, dp[a][i][0], dp[b][j][1]);
      } else {
        addup(j + 1, 1, dp[a][i][0], dp[b][j][1]);
      }
      if (i + j + 1 <= k) {
        addup(j + 1, 0, dp[a][i][1], dp[b][j][0]);
      } else {
        addup(i, 1, dp[a][i][1], dp[b][j][1]);
      }
      addup(max(i, j + 1), 1, dp[a][i][1], dp[b][j][1]);
    }
  }
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < 2; j++) {
      dp[a][i][j] = sol[i][j];
      sol[i][j] = 0;
    }
  }
}
void dfs(int a, int par) {
  dp[a][0][0]++;
  dp[a][0][1]++;
  for (auto &b : g[a]) {
    if (b != par) {
      dfs(b, a);
      add(a, b);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, -1);
  int sol = 0;
  for (int i = 0; i <= k; i++) {
    sol = (sol + dp[1][i][0]) % M;
  }
  cout << sol << "\n";
  return 0;
}
