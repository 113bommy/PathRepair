#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 9;
vector<int> graph[maxn];
bool vis[maxn];
vector<int> arr(maxn);
vector<int> order;
bool ok;
int level[maxn];
bool comp(int x, int y) { return level[x] < level[y]; }
void bfs() {
  int src = 1;
  queue<int> q;
  q.push(src);
  vis[src] = 1;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    order.push_back(node);
    for (auto x : graph[node]) {
      if (vis[x]) continue;
      q.push(x);
      vis[x] = true;
    }
  }
}
void test_case(int tc) {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  order.push_back(-1);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    level[arr[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    sort(graph[i].begin(), graph[i].end(), comp);
  }
  bfs();
  for (int i = 1; i <= n; ++i)
    if (arr[i] != order[i]) {
      cout << "No";
      return;
    }
  cout << "Yes";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  for (int tc = 1; tc <= t; ++tc) test_case(tc);
}
