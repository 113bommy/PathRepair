#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> edges[N], ans;
int init[N], goal[N], was[N], n;
int dfs(int cv, int cx, int nx) {
  if (was[cv]) return 0;
  was[cv] = 1;
  int res = 0;
  if (goal[cv] != init[cv] ^ cx) {
    ans.push_back(cv);
    res++;
    cx ^= 1;
  }
  for (int i : edges[cv]) res += dfs(i, nx, cx);
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) cin >> init[i];
  for (int i = 1; i <= n; i++) cin >> goal[i];
  cout << dfs(1, 0, 0) << endl;
  for (int i : ans) cout << i << endl;
  return 0;
}
