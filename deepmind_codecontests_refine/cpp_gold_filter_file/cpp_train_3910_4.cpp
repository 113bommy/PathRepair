#include <bits/stdc++.h>
using namespace std;
int s[200010], univ[200010];
int n, k, n_univ;
vector<int> edges[200010];
bool visited[200010];
int dist[200010];
int getSum(int node) {
  int sum = univ[node];
  visited[node] = true;
  for (auto e : edges[node]) {
    if (!visited[e]) sum += getSum(e);
  }
  s[node] = sum;
  return sum;
}
int dfs(int node) {
  visited[node] = true;
  for (auto e : edges[node]) {
    if (visited[e]) continue;
    if (s[e] * 2 > n_univ) {
      return dfs(e);
    }
  }
  return node;
}
long long getAns(int centroid) {
  queue<pair<int, int> > q;
  memset(visited, 0, sizeof(visited));
  q.push(make_pair(centroid, 0));
  visited[centroid] = true;
  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    dist[node.first] = node.second;
    for (int e : edges[node.first]) {
      if (!visited[e]) {
        visited[e] = true;
        q.push(make_pair(e, node.second + 1));
      }
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (univ[i]) sum += dist[i];
  }
  return sum;
}
int main() {
  cin >> n >> k;
  n_univ = k + k;
  for (int i = 0; i < n_univ; i++) {
    int x;
    cin >> x;
    x--;
    univ[x] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    edges[v1].push_back(v2);
    edges[v2].push_back(v1);
  }
  getSum(0);
  memset(visited, 0, sizeof(visited));
  cout << getAns(dfs(0)) << endl;
}
