#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int SZ = 55555;
void bfs(queue<int>& q, int st, vector<long long>& lvl,
         vector<vector<int>>& graph) {
  lvl[st] = 1;
  q.push(st);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int to : graph[cur]) {
      if (!lvl[to]) {
        lvl[to] = lvl[cur] + 1;
        q.push(to);
      }
    }
  }
}
void solve() {
  int n, m, x, y, k;
  cin >> n >> m;
  vector<vector<int>> graph(n + 10);
  vector<long long> lvl(n + 1, 0), reversed(n + 1, 0), special(n + 1, 0);
  cin >> k;
  for (int i = 0; i < k; ++i) cin >> x, special[x] = 1;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  queue<int> q;
  vector<pair<int, pair<int, long long>>> distances;
  bfs(q, 1, lvl, graph);
  bfs(q, n, reversed, graph);
  for (int i = 1; i <= n; ++i) {
    if (special[i]) {
      int dist = lvl[i] - reversed[i] - 2;
      distances.push_back({dist, {i, reversed[i] - 1}});
    }
  }
  sort(distances.begin(), distances.end());
  n = distances.size();
  long long maxDistY = -1;
  int l = n - 1;
  long long ans = -1;
  while (l >= 0) {
    if (l != n - 1) ans = max(ans, lvl[distances[l].second.first] + maxDistY);
    maxDistY = max(maxDistY, distances[l].second.second);
    l--;
  }
  cout << min(lvl[n] + 1, ans) << endl;
}
int main() { solve(); }
