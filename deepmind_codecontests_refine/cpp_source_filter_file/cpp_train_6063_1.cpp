#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 500;
vector<int> edge[maxn];
vector<int> ans;
int ansv[maxn];
void dfs(int u, int depth, int father) {
  for (auto v : edge[u]) {
    if (v == father) {
      continue;
    }
    dfs(v, depth + 1, u);
    ansv[u] += ansv[v];
  }
  ans.push_back(depth - ansv[u]);
  ++ansv[u];
}
int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0, 0);
  sort(ans.begin(), ans.end(), greater<int>());
  int sum = 0;
  for (int i = 0; i < K; ++i) {
    sum += ans[i];
  }
  cout << sum << endl;
  return 0;
}
