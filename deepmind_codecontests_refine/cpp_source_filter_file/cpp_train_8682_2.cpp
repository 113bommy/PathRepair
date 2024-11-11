#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int n, r1, r2;
vector<int> adj[N];
int par[N];
void dfs(int u, int p) {
  par[u] = p;
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}
int main() {
  cin >> n >> r1 >> r2;
  r1--, r2--;
  for (int i = 0; i < n; i++) {
    if (i == r1) continue;
    int p;
    cin >> p;
    p--;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }
  dfs(r2, -1);
  for (int i = 0; i < n; i++) {
    if (i == r2) continue;
    cout << par[i] << " ";
  }
  cout << endl;
}
