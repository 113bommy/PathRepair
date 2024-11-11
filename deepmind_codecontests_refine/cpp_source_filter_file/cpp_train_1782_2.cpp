#include <bits/stdc++.h>
using namespace std;
vector<int> folha;
vector<bool> visit;
void dfs_visit(vector<vector<int>>& adj, int i) {
  visit[i] = 1;
  bool vf = true;
  for (int j : adj[i]) {
    if (!visit[j]) {
      dfs_visit(adj, j);
      vf = false;
      folha[i] += folha[j];
    }
  }
  if (vf) folha[i] = 1;
}
void dfs(vector<vector<int>>& adj, int n) {
  visit.assign(n + 1, 0);
  dfs_visit(adj, 1);
}
int main() {
  int n, k, a, b;
  cin >> n;
  vector<int> vetor;
  vetor.assign(n + 1, 0);
  vector<vector<int>> adj;
  vector<int> lista;
  lista.clear();
  adj.assign(n + 1, lista);
  for (int i = 2; i <= n; i++) {
    cin >> a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  folha.assign(n + 1, 0);
  dfs(adj, 1);
  vector<int> v(n);
  for (int i = 1; i <= n; i++) {
    v[i - 1] = folha[i];
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    cout << v[i - 1] << " ";
  }
  cout << endl;
  return 0;
}
