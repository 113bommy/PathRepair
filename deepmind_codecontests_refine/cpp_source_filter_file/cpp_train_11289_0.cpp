#include <bits/stdc++.h>
using namespace std;
void count(const vector<vector<int> > &G, vector<int> &state,
           const vector<int> &goal, int v, int f1, int f2, vector<int> &ans,
           int pre) {
  if (f1) state[v] = !state[v];
  if (state[v] != goal[v]) {
    f1 += 1;
    ans.push_back(v);
    state[v] = goal[v];
  }
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == pre) continue;
    count(G, state, goal, G[v][i], f2, f1, ans, v);
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> init(n), goal(n);
  for (int i = 0; i < n; i++) cin >> init[i];
  for (int i = 0; i < n; i++) cin >> goal[i];
  vector<int> ans;
  count(G, init, goal, 0, 0, 0, ans, -1);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << endl;
  }
  return 0;
}
