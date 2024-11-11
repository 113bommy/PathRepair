#include <bits/stdc++.h>
using namespace std;
int max_deg = -1e9;
vector<pair<int, int>> ans;
void dfs(int v, vector<vector<int>>& g, int t, int time, vector<bool>& used) {
  ans.push_back({v, t});
  used[v] = 1;
  int counter = 0;
  for (int i : g[v]) {
    if (!used[i]) {
      if (t == max_deg) {
        t = time - g[v].size() + counter;
        ans.push_back({v, t});
      }
      t++;
      dfs(i, g, t, t, used);
      ans.push_back({v, t});
      counter++;
    }
  }
  if (v == 1) {
    return;
  }
  if (t >= time) {
    t = time - 1;
    ans.push_back({v, t});
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int num1, num2;
    cin >> num1 >> num2;
    g[num1].push_back(num2);
    g[num2].push_back(num1);
    max_deg = max(max(int(g[num1].size()), int(g[num2].size())), max_deg);
  }
  vector<bool> used(n + 1, 0);
  dfs(1, g, 0, g[1].size(), used);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
