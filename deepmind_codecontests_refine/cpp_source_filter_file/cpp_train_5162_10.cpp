#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, k;
long long L;
vector<vector<int>> g;
vector<long long> total;
vector<int> visited;
vector<vector<long long>> cnt;
int dfs(int cur) {
  visited[cur] = 1;
  int r = 1;
  for (int n : g[cur]) {
    if (visited[n] == 0) {
      r += dfs(n);
      ++cnt[n][0];
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
          total[(i + j + 1) % k] += cnt[cur][i] * cnt[n][j];
        }
      }
      --cnt[n][0];
      for (int i = 0; i < k; ++i) {
        cnt[cur][(i + 1) % k] += cnt[n][i];
      }
      ++cnt[cur][1 % k];
    }
  }
  for (int i = 0; i < k; ++i) total[i] += cnt[cur][i];
  L += r * (n - r);
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  g.resize(n + 1);
  total.resize(k, 0);
  visited.resize(n + 1, 0);
  cnt = vector<vector<long long>>(n + 1, vector<long long>(k, 0));
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  L = 0;
  dfs(1);
  for (int i = 1; i < k; ++i) L += total[i] * (k - i);
  cout << L / k << endl;
  return 0;
}
