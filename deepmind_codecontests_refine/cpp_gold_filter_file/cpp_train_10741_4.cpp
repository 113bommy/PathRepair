#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
vector<int> parent;
long long ans1 = 0;
int find(int x) {
  if (parent[x] != x) parent[x] = find(parent[x]);
  return parent[x];
}
void Union(int u, int v, vector<int>& rank) {
  u = find(u);
  v = find(v);
  if (rank[u] < rank[v]) swap(u, v);
  ans1 -= (long long)rank[u] * (rank[u] - 1) / 2;
  ans1 -= (long long)rank[v] * (rank[v] - 1) / 2;
  rank[u] += rank[v];
  ans1 += (long long)(rank[u]) * (rank[u] - 1) / 2;
  parent[v] = u;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> adj(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> adj[i].second.first >> adj[i].second.second >> adj[i].first;
      adj[i].second.first--;
      adj[i].second.second--;
    }
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; i++) {
      cin >> q[i].first;
      q[i].second = i;
    }
    sort(q.begin(), q.end());
    sort(adj.begin(), adj.end());
    int j = 0;
    parent = vector<int>(n, 0);
    vector<int> rank(n, 1);
    for (int i = 0; i < n; i++) parent[i] = i;
    long long ans[m];
    for (int i = 0; i < m; i++) {
      while (j < n - 1 && adj[j].first <= q[i].first) {
        int u = adj[j].second.first;
        int v = adj[j].second.second;
        Union(u, v, rank);
        j++;
      }
      ans[q[i].second] = ans1;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
