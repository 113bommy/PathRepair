#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector<int> edge[maxn];
int dist[maxn];
int n;
void bfs(int u) {
  vector<int> vis(n + 1, false);
  queue<int> q;
  q.push(u);
  dist[u] = 1;
  vis[u] = true;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto child : edge[node]) {
      if (!vis[child]) {
        vis[child] = true;
        dist[child] = dist[node] + 1;
        q.push(child);
      }
    }
  }
}
int count1[maxn];
void numberOfNodes(int s, int e) {
  vector<int>::iterator u;
  count1[s] = 1;
  for (u = edge[s].begin(); u != edge[s].end(); u++) {
    if (*u == e) continue;
    numberOfNodes(*u, s);
    count1[s] += count1[*u];
  }
}
void solve() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  bfs(1);
  long long res = 0;
  numberOfNodes(1, 0);
  vector<int> ans(n);
  for (int i = 1; i <= n; i++) ans[i - 1] = dist[i] - count1[i];
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < k; i++) res += ans[i];
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
