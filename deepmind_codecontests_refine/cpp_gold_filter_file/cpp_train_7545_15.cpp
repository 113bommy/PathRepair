#include <bits/stdc++.h>
using namespace std;
vector<int> fort;
vector<vector<int> > graph;
vector<int> strength;
void calcStrength(double r) {
  for (int i = 0; i < (strength.size()); ++i) {
    strength[i] = graph[i].size() - graph[i].size() * r;
  }
}
bool start(vector<bool>& ans) {
  queue<int> q;
  for (auto& f : fort) q.push(f);
  ans = vector<bool>(graph.size(), true);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    if (ans[node]) {
      ans[node] = false;
      for (auto& neigh : graph[node]) {
        if (strength[neigh]-- <= 0) q.push(neigh);
      }
    }
  }
  bool ret = any_of(ans.begin(), ans.end(), [](bool b) { return b; });
  return ret;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  fort.resize(k);
  graph.resize(n);
  strength.resize(n);
  for (auto& a : fort) cin >> a;
  for (auto& a : fort) a--;
  for (int i = 0; i < (m); ++i) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  double l = 0, r = 1;
  vector<bool> ans;
  while (l + 0.00000001 < r) {
    double mid = (l + r) / 2;
    calcStrength(mid);
    bool possible = start(ans);
    if (possible) {
      l = mid;
    } else {
      r = mid;
    }
  }
  calcStrength(l);
  start(ans);
  set<int> s;
  for (int i = 0; i < (ans.size()); ++i) {
    if (ans[i]) s.insert(i + 1);
  }
  cout << s.size() << endl;
  for (auto& a : s) cout << a << " ";
  cout << endl;
  return 0;
}
