#include <bits/stdc++.h>
using namespace std;
const int Maxn = 507;
int n, m;
int E[Maxn][Maxn];
vector<int> V[Maxn];
int ans[Maxn];
bool mark[Maxn];
void dfs(int v) {
  mark[v] = true;
  for (int i = 0; i < V[v].size(); i++) {
    int u = V[v][i];
    if (!mark[u])
      ans[u] = 2 - ans[v], dfs(u);
    else if (ans[u] == ans[v]) {
      cout << "No" << endl;
      exit(0);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    E[u][v] = E[v][u] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!E[i][j] and i != j) V[i].push_back(j);
  for (int i = 1; i <= n; i++) {
    if (!V[i].size())
      ans[i] = 1, mark[i] = true;
    else if (!mark[i])
      ans[i] = 2, dfs(i);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) {
      if (E[i][j] and abs(ans[i] - ans[j]) == 2) return cout << "No" << endl, 0;
    }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) cout << (char)(ans[i] + 'a');
  cout << endl;
}
