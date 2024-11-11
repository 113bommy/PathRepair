#include <bits/stdc++.h>
using namespace std;
int n, m;
int g[23];
int dp[1 << 22], p[1 << 22];
int l[1 << 22];
int pop(int x) { return __builtin_popcount(x); }
int main() {
  cin >> n >> m;
  if (m == n * (n - 1) / 2) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u] += (1 << v);
    g[v] += (1 << u);
  }
  for (int i = 0; i < n; ++i) {
    g[i] += (1 << i);
    l[1 << i] = i;
  }
  for (int x = 1; x < (1 << n); ++x) {
    if (pop(x) == 1) {
      dp[x] = g[l[x]];
      p[x] = 0;
    }
    for (int j = 0; j < n; ++j) {
      if (((1 << j) & dp[x]) == 0) continue;
      int t = (dp[x] | g[j]);
      if (dp[x | (1 << j)] < t) {
        dp[x | (1 << j)] = t;
        p[x | (1 << j)] = x;
      }
    }
  }
  int mini = 50;
  int ind = -1;
  for (int i = 0; i < (1 << n); ++i) {
    if (dp[i] == ((1 << n) - 1)) {
      if (pop(i) < mini) {
        mini = pop(i);
        ind = i;
      }
    }
  }
  vector<int> ans;
  cout << mini << endl;
  while (ind != 0) {
    ans.push_back(l[ind - p[ind]] + 1);
    ind = p[ind];
  }
  for (int i = mini - 1; i >= 0; --i) cout << ans[i] << ' ';
  cout << endl;
}
