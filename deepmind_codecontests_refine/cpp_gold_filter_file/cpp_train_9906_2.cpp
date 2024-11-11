#include <bits/stdc++.h>
using namespace std;
int cnt(vector<vector<pair<int, int>>>& graph, int cur, int parent, int val) {
  int ans = 1;
  for (auto p : graph[cur]) {
    if (p.first == parent) continue;
    if (p.second == val) ans += cnt(graph, p.first, cur, val);
  }
  return ans;
}
void fill(vector<vector<pair<int, int>>>& graph,
          vector<pair<bool, bool>>& visited, vector<pair<int, int>>& cnt_vec,
          int cur, int parent, int val, int num) {
  if (val == 0) {
    visited[cur].first = true;
    cnt_vec[cur].first = num;
  } else {
    visited[cur].second = true;
    cnt_vec[cur].second = num;
  }
  for (auto p : graph[cur]) {
    if (p.first == parent) continue;
    if (p.second == val) fill(graph, visited, cnt_vec, p.first, cur, val, num);
  }
}
int process(vector<vector<pair<int, int>>>& graph,
            vector<pair<bool, bool>>& visited, vector<pair<int, int>>& cnt_vec,
            int start, int val) {
  int n = graph.size(), ans;
  ans = cnt(graph, start, -1, val);
  fill(graph, visited, cnt_vec, start, -1, val, ans);
  return ans;
}
int main() {
  int n, i, a, b, val, tmp;
  long long ans = 0;
  cin >> n;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (i = 0; i < n - 1; ++i) {
    cin >> a >> b >> val;
    graph[a].push_back({b, val});
    graph[b].push_back({a, val});
  }
  vector<pair<int, int>> cnt_vec(n + 1, {0, 0});
  vector<pair<bool, bool>> visited(n + 1, {false, false});
  vector<int> components;
  for (i = 1; i <= n; ++i) {
    if (!visited[i].first) {
      tmp = process(graph, visited, cnt_vec, i, 0);
      if (tmp > 1) components.push_back(tmp);
    }
    if (!visited[i].second) {
      tmp = process(graph, visited, cnt_vec, i, 1);
      if (tmp > 1) components.push_back(tmp);
    }
  }
  for (auto num : components) ans += 1LL * num * (num - 1);
  for (i = 1; i <= n; ++i)
    ans += 1LL * (cnt_vec[i].first - 1) * (cnt_vec[i].second - 1);
  cout << ans << endl;
  return 0;
}
