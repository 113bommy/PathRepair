#include <bits/stdc++.h>
using namespace std;
int t, n;
long long S;
long long sum;
long long steps;
vector<pair<int, int> > tree[200000];
vector<pair<int, int> > edges;
int leaf[200000];
priority_queue<pair<long long, pair<int, int> > > pq;
void dfs(int u, int p) {
  leaf[u] = 0;
  int flag = 0;
  for (pair<int, int> child : tree[u]) {
    if (child.first == p) continue;
    dfs(child.first, u);
    edges.push_back({child.second, leaf[child.first]});
    leaf[u] += leaf[child.first];
  }
  if (!leaf[u]) {
    leaf[u] = 1;
  }
}
int main() {
  cin >> t;
  while (t--) {
    steps = 0;
    while (!pq.empty()) {
      pq.pop();
    }
    for (int i = 1; i <= n; i++) {
      leaf[i] = 0;
      tree[i].clear();
    }
    edges.clear();
    cin >> n >> S;
    sum = 0;
    for (int i = 0; i < n - 1; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      tree[u].push_back({v, w});
      tree[v].push_back({u, w});
    }
    dfs(1, -1);
    for (int i = 1; i < n; i++) {
      pq.push({edges[i - 1].first * 1LL * edges[i - 1].second -
                   (edges[i - 1].first / 2) * 1LL * edges[i - 1].second,
               {edges[i - 1].first, edges[i - 1].second}});
      sum += edges[i - 1].first * 1LL * edges[i - 1].second;
    }
    while (sum > S) {
      pair<long long, pair<int, int> > t = pq.top();
      pq.pop();
      sum -= t.second.first * 1LL * t.second.second;
      int k = t.second.first;
      k = k / 2;
      sum += k * t.second.second;
      pq.push({k * 1LL * t.second.second - (k / 2) * 1LL * t.second.second,
               {k, t.second.second}});
      steps++;
    }
    cout << steps << endl;
  }
}
