#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> g[1000010];
bool used[1000010];
long long res, ans;
int dfs(int t) {
  int cnt = 1;
  for (int i = 0; i < g[t].size(); i++) {
    if (!used[g[t][i]]) {
      used[g[t][i]] = 1;
      cnt += dfs(g[t][i]);
    }
  }
  return cnt;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      used[i] = 1;
      ans += min(dfs(i), k);
      res++;
    }
  }
  if (k == 1)
    cout << max(0LL, res - 2) << endl;
  else
    cout << max(0LL, res - 1 - ans / 2) << endl;
  return 0;
}
