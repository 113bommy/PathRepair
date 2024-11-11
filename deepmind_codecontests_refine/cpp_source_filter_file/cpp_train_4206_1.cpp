#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> adj[305];
int order[305];
vector<int> ans;
void dfs1(int src, int par) {
  for (int child : adj[src]) {
    if (child == par) continue;
    dfs1(child, src);
    order[src] = min(order[src], order[child]);
  }
}
void dfs2(int src, int par) {
  ans.push_back(src);
  for (auto child : adj[src]) {
    if (par == child) continue;
    dfs2(child, src);
    ans.push_back(src);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 305; i++) order[i] = 999999;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  vector<int> A;
  int l;
  while (cin >> l) A.emplace_back(l);
  for (int i = 0; i < A.size(); i++) order[A[i]] = i;
  dfs1(1, -1);
  for (int i = 1; i <= N; i++)
    sort(adj[i].begin(), adj[i].end(),
         [](int x, int y) { return order[x] < order[y]; });
  dfs2(1, -1);
  vector<int> B;
  for (int i = 0; i < ans.size(); i++) {
    if (adj[ans[i]].size() == 1 && ans[i] != -1) B.push_back(ans[i]);
  }
  if (B != A)
    cout << -1 << "\n";
  else {
    for (int i : ans) cout << i << " ";
  }
  return 0;
}
