#include <bits/stdc++.h>
using namespace std;
int t, k;
int main() {
  cin >> t;
  while (t--) {
    vector<vector<pair<int, int>>> graph;
    cin >> k;
    graph.resize(2 * k);
    for (int i = 0; i < 2 * k - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      graph[a].emplace_back(b, c);
      graph[b].emplace_back(a, c);
    }
    vector<int> parent(2 * k, -1);
    vector<long long> cost(2 * k);
    vector<int> que(1, 0);
    parent[0] = 0;
    for (int i = 0; i < que.size(); ++i) {
      int t = que[i];
      for (auto it : graph[t]) {
        if (parent[it.first] == -1) {
          parent[it.first] = t;
          cost[it.first] = it.second;
          que.emplace_back(it.first);
        }
      }
    }
    long long mn = 0, mx = 0;
    vector<int> size(2 * k, 1);
    reverse(que.begin(), que.end());
    for (int i : que) {
      size[parent[i]] += size[i];
      mx += cost[i] * min(2 * k - size[i], size[i]);
      mn += cost[i] * (size[i] & 1);
    }
    cout << mn << " " << mx << endl;
  }
  return 0;
}
