#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
vector<vector<int>> gr(N);
bool used[N];
int s = -1;
int dfs(int v, int prv = 0) {
  used[v] = true;
  for (auto u : gr[v]) {
    if (u == prv) continue;
    if (used[u]) {
      s = 0;
      return 0;
    }
    dfs(u, v);
  }
  return s == 0 ? 0 : 1;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) ans += dfs(i);
    s = -1;
  }
  cout << ans;
  return 0;
}
