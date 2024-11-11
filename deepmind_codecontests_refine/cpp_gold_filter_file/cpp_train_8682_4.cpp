#include <bits/stdc++.h>
using namespace std;
int gcd(int u, int v) { return (v != 0) ? gcd(v, u % v) : u; }
int V;
vector<vector<int> > adj;
vector<int> res;
int r1, r2;
void dfs(int cur, int prev) {
  res[cur] = prev;
  for (int i = 0; i < adj[cur].size(); i++) {
    int nxt = adj[cur][i];
    if (nxt == prev) continue;
    dfs(nxt, cur);
  }
}
int main() {
  cin >> V >> r1 >> r2;
  int a, b = 1;
  adj.resize(V + 10);
  res.resize(V + 10);
  for (int i = 1; i < V; i++) {
    if (b == r1) b++;
    cin >> a;
    adj[a].push_back(b);
    adj[b].push_back(a);
    b++;
  }
  dfs(r2, r2);
  for (int i = 1; i <= V; i++) {
    if (i == r2) continue;
    cout << res[i] << " ";
  }
  cout << endl;
}
