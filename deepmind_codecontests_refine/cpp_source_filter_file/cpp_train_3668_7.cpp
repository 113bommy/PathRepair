#include <bits/stdc++.h>
using namespace std;
const int oo = (1 << 30);
const int MAX = (2e5) + 10;
vector<int> g[MAX];
int n, dp[MAX];
void dfs1(int x, int p) {
  for (auto i : g[x]) {
    if (i != p) {
      dfs1(i, x);
      if (dp[i] > 0) {
        dp[x] += dp[i];
      }
    }
  }
}
void dfs2(int x, int p) {
  for (auto i : g[x]) {
    if (i != p) {
      if (dp[x] > 0) {
        if (dp[i] >= 0) {
          dp[i] = dp[x];
        } else {
          dp[i] += dp[x];
        }
      }
      dfs2(i, x);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a == 0) {
      dp[i] = -1;
    } else
      dp[i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs1(1, -1);
  dfs2(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  return 0;
}
