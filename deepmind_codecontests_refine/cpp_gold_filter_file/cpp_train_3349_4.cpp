#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, m;
bool used[MAXN];
set<int> graph[MAXN];
stack<int> path;
vector<int> cycle;
int fake;
vector<pair<int, int> > edges;
vector<pair<int, int> > answer;
void EulerCycle(int x) {
  cycle.clear();
  edges.clear();
  path.push(x);
  while (path.empty() == false) {
    used[x] = true;
    if (graph[x].empty() == false) {
      path.push(*graph[x].begin());
      int y = *graph[x].begin();
      graph[x].erase(y);
      graph[y].erase(x);
      x = y;
    } else {
      cycle.push_back(x);
      path.pop();
      if (path.empty() == false) x = path.top();
    }
  }
  for (int i = 0; i < cycle.size() - 1; i++) {
    edges.push_back({cycle[i], cycle[i + 1]});
  }
}
bool isFake(pair<int, int> x) {
  if (x.first == fake || x.second == fake) return true;
  return false;
}
void solve(int x) {
  EulerCycle(x);
  for (int i = 0; i < edges.size(); i++) {
    bool toDelete;
    if (isFake(edges[i]) == true) {
      continue;
    }
    if (i % 2 != 0)
      toDelete = true;
    else
      toDelete = false;
    if (i != 0 && isFake(edges[i - 1]) == true) toDelete = false;
    if (i == 0 && isFake(edges[edges.size() - 1]) == true) toDelete = false;
    if (i != edges.size() - 1 && isFake(edges[i + 1]) == true) toDelete = false;
    if (i == edges.size() - 1 && isFake(edges[0]) == true) toDelete = false;
    if (toDelete == false) {
      answer.push_back(edges[i]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].insert(v);
    graph[v].insert(u);
  }
  fake = -1;
  for (int i = 1; i <= n; i++) {
    if (graph[i].size() % 2 != 0) {
      fake = n + 1;
      graph[i].insert(fake);
      graph[fake].insert(i);
    }
  }
  for (int x = 1; x <= n + 1; x++) {
    if (used[x] == false) {
      solve(x);
    }
  }
  cout << answer.size() << '\n';
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i].first << " " << answer[i].second << '\n';
  }
}
