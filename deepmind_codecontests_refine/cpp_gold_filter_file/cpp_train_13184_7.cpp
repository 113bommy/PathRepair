#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 3e5 + 5;
const long long mod = 1e9 + 7;
priority_queue<pair<long long, int> > Q;
vector<pair<int, long long> > G[N];
long long dis[N];
bool vis[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    G[u].push_back(make_pair(v, w));
    G[v].push_back(make_pair(u, w));
  }
  for (int i = 1; i <= n; i++) {
    cin >> dis[i];
    Q.push(make_pair(-dis[i], i));
  }
  while (!Q.empty()) {
    pair<int, int> np = Q.top();
    Q.pop();
    int u = np.second;
    if (vis[u]) continue;
    vis[u] = 1;
    for (pair<int, long long> to : G[u]) {
      int v = to.first;
      long long w = to.second * 2;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        Q.push(make_pair(-dis[v], v));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << " ";
  }
  cout << endl;
}
