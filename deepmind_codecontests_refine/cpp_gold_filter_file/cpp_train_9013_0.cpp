#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int maxi_s = 0;
int maxi_node = 0;
set<int> ice_cream[300005];
vector<int> adj[300005];
int ans[300005];
void dfs(int node, int prev) {
  if (prev != -1) {
    if (ice_cream[node].size() <= ice_cream[prev].size()) {
      deque<int> need_assign;
      deque<int> unassigned;
      for (int i : ice_cream[node]) {
        if (ice_cream[prev].count(i) == 0) {
          need_assign.push_back(i);
        }
      }
      while (unassigned.size() < need_assign.size()) {
        for (int i : ice_cream[prev]) {
          if (ice_cream[node].count(i) == 0) {
            unassigned.push_back(i);
          }
        }
      }
      while (need_assign.size()) {
        int x = need_assign.front();
        int y = unassigned.front();
        need_assign.pop_front();
        unassigned.pop_front();
        ans[x] = ans[y];
      }
    } else {
      deque<int> need_assign;
      set<int> used_colors;
      for (int i : ice_cream[node]) {
        if (ice_cream[prev].count(i) == 0) {
          need_assign.push_back(i);
        } else {
          used_colors.insert(ans[i]);
        }
      }
      for (int i = 1; i <= maxi_s && need_assign.size(); i++) {
        if (used_colors.count(i) == 0) {
          int x = need_assign.front();
          need_assign.pop_front();
          ans[x] = i;
        }
      }
    }
  }
  for (int i : adj[node]) {
    if (i == prev) continue;
    dfs(i, node);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    if (maxi_s < w) {
      maxi_s = w;
      maxi_node = i;
    }
    for (int j = 0; j < w; j++) {
      int a;
      cin >> a;
      a--;
      ice_cream[i].insert(a);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ind = 1;
  for (int i : ice_cream[maxi_node]) {
    ans[i] = ind;
    ind++;
  }
  dfs(maxi_node, -1);
  if (maxi_s <= 1) {
    cout << "1\n";
    for (int i = 0; i < m; i++) cout << "1 ";
    return 0;
  }
  cout << maxi_s << "\n";
  for (int i = 0; i < m; i++) {
    cout << max(ans[i], 1) << " ";
  }
  return 0;
}
