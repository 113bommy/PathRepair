#include <bits/stdc++.h>
using namespace std;
const long long mm = 1e5 + 20;
long long n, dp[mm][2], inp[mm];
vector<long long> g[mm];
void input() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) cin >> inp[i];
}
void dfs(int u, int par) {
  if (g[u].size() == 1 && u != 0) {
    if (inp[u] > 0)
      dp[u][1] = inp[u];
    else
      dp[u][0] = -1 * (inp[u]);
    return;
  }
  long long m1 = 0, m2 = 0;
  for (auto v : g[u]) {
    if (v != par) {
      dfs(v, u);
      m1 = max(m1, dp[v][0]);
      m2 = max(m2, dp[v][1]);
    }
  }
  dp[u][0] = m1;
  dp[u][1] = m2;
  long long di = m1 - m2 + inp[u];
  if (di < 0) {
    dp[u][0] += abs(di);
  } else {
    dp[u][1] += abs(di);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  input();
  if (n == 1) {
    cout << inp[0] << endl;
    return 0;
  }
  dfs(0, -1);
  cout << dp[0][0] + dp[0][1] << endl;
}
