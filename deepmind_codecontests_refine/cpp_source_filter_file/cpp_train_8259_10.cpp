#include <bits/stdc++.h>
using namespace std;
int f[200001], l[200001], n, i, u, v, kq;
vector<int> a[200001], c[200001];
void dfs(int u, int p) {
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v != p) {
      dfs(v, u);
      l[u] += l[v] + c[u][i];
    }
  }
}
void DFS(int u, int p) {
  kq = min(kq, f[u]);
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v != p) {
      if (c[u][i] == 1)
        f[v] = f[u] + 1;
      else
        f[v] = f[u] - 1;
      DFS(v, u);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
    c[u].push_back(1);
    c[v].push_back(0);
  }
  dfs(1, 0);
  f[1] = l[1];
  kq = n + 1;
  DFS(1, 0);
  cout << kq << '\n';
  for (i = 1; i <= n; i++)
    if (f[i] == kq) cout << i << " ";
}
