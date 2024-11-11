#include <bits/stdc++.h>
using namespace std;
long long tree[9 * 100010 + 1], dist[9 * 100010 + 1], visited[9 * 100010],
    ind[2][9 * 100010];
vector<pair<int, long long> > graph[9 * 100010 + 1];
int ct, n;
void build(int low, int high, int node, int type = 0) {
  ind[type][node] = ct++;
  if (low == high) {
    if (!type)
      graph[ind[type][node]].push_back(make_pair(low, 0));
    else
      graph[low].push_back(make_pair(ind[type][node], 0));
    return;
  }
  int mid = (low + high) / 2;
  build(low, mid, 2 * node, type);
  build(mid + 1, high, 2 * node + 1, type);
  if (!type) {
    graph[ind[type][node]].push_back(make_pair(ind[type][2 * node], 0));
    graph[ind[type][node]].push_back(make_pair(ind[type][2 * node + 1], 0));
  } else {
    graph[ind[type][2 * node]].push_back(make_pair(ind[type][node], 0));
    graph[ind[type][2 * node + 1]].push_back(make_pair(ind[type][node], 0));
  }
}
void update(int low, int high, int begin, int end, int v, int w, int type,
            int node) {
  if (low > end || high < begin) return;
  if (low >= begin && high <= end) {
    if (!type) {
      graph[v].push_back(make_pair(ind[type][node], w));
    } else {
      graph[ind[type][node]].push_back(make_pair(v, w));
    }
    return;
  }
  int mid = (low + high) / 2;
  update(low, mid, begin, end, v, w, type, 2 * node);
  update(mid + 1, high, begin, end, v, w, type, 2 * node + 1);
}
int main() {
  ios::sync_with_stdio(false);
  int q, s;
  cin >> n >> q >> s;
  ct = n;
  build(0, n - 1, 1, 0);
  build(0, n - 1, 1, 1);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, u, w;
      cin >> v >> u >> w;
      graph[v - 1].push_back(make_pair(u - 1, w));
    } else {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      if (t == 2) {
        update(0, n - 1, l - 1, r - 1, v - 1, w, 0, 1);
      } else {
        update(0, n - 1, l - 1, r - 1, v - 1, w, 1, 1);
      }
    }
  }
  for (int i = 0; i < 9 * 100010 + 1; i++) dist[i] = 1000000000000000;
  set<pair<int, long long> > pq;
  pq.insert(make_pair(0, s - 1));
  dist[s - 1] = 0;
  while (pq.size()) {
    int x = pq.begin()->second;
    visited[x] = 1;
    pq.erase(pq.begin());
    for (int i = 0; i < graph[x].size(); i++) {
      int node = graph[x][i].first;
      long long wt = graph[x][i].second;
      if (!visited[node]) {
        if (dist[node] > dist[x] + wt) {
          pq.erase(make_pair(dist[node], node));
          dist[node] = dist[x] + wt;
          pq.insert(make_pair(dist[node], node));
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dist[i] == 1000000000000000)
      cout << -1 << " ";
    else
      cout << dist[i] << " ";
  }
}
