#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m, k, s;
int vis[N];
vector<vector<int>> adj(N), costsOfProducts(N);
vector<vector<int>> nodesWithProduct(100 + 9);
void bfs(int product) {
  queue<pair<int, int>> q;
  for (auto i : nodesWithProduct[product]) {
    q.push({i, 0});
    vis[i] = product;
  }
  while (!q.empty()) {
    int node = q.front().first;
    int level = q.front().second;
    costsOfProducts[node].push_back(level);
    q.pop();
    for (auto i : adj[node]) {
      if (vis[i] < product) {
        vis[i] = product;
        q.push({i, level + 1});
      }
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) {
    int product;
    scanf("%d", &product);
    nodesWithProduct[product].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= k; i++) {
    bfs(i);
  }
  for (int i = 1; i <= n; i++) {
    long long cost = 0;
    sort(costsOfProducts[i].begin(), costsOfProducts[i].end());
    for (int j = 0; j < s; j++) {
      cost += costsOfProducts[i][j];
    }
    printf("%lld ", cost);
  }
  return 0;
}
