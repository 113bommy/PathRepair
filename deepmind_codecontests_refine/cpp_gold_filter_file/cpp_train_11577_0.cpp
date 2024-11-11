#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[500001];
int parent[500001];
int parent_weight[500001];
vector<pair<long long, long long>> child_result[500001];
int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      adj[a].push_back(make_pair(b, w));
      adj[b].push_back(make_pair(a, w));
    }
    for (int i = 0; i <= n; ++i) {
      parent[i] = -1;
      parent_weight[i] = 0;
    }
    vector<int> order = {1};
    parent[1] = 0;
    for (int i = 0; i < (int)order.size(); ++i) {
      const int u = order[i];
      for (int j = 0; j < (int)adj[u].size(); ++j) {
        const int v = adj[u][j].first;
        if (parent[v] == -1) {
          parent[v] = u;
          parent_weight[v] = adj[u][j].second;
          order.push_back(v);
        }
      }
    }
    for (int i = order.size() - 1; i >= 0; --i) {
      const int u = order[i];
      sort(child_result[u].begin(), child_result[u].end(),
           [](const pair<long long, long long>& a,
              const pair<long long, long long>& b) {
             return a.first - a.second > b.first - b.second;
           });
      long long base_sum = 0;
      long long top_k_minus_1 = 0;
      long long kth = 0;
      int cnt = 0;
      for (const pair<long long, long long> p : child_result[u]) {
        base_sum += p.second;
        ++cnt;
        if (cnt <= k - 1) {
          top_k_minus_1 += p.first - p.second;
        } else if (cnt == k) {
          kth = p.first - p.second;
        }
      }
      pair<long long, long long> result(
          base_sum + top_k_minus_1 + max(kth, (long long)parent_weight[u]),
          base_sum + top_k_minus_1 + kth);
      child_result[parent[u]].push_back(result);
    }
    printf("%lld\n", child_result[0].begin()->second);
    for (int i = 0; i <= n; ++i) adj[i].clear();
    for (int i = 0; i <= n; ++i) child_result[i].clear();
  }
  return 0;
}
