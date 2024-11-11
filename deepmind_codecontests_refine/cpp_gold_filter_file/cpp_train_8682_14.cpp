#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
const int MAXN = 100005;
int par[MAXN];
void dfs(int node, int p) {
  par[node] = p;
  for (int i = 0; i < (int)adj[node].size(); i++) {
    int v = adj[node][i];
    if (v != p) {
      dfs(v, node);
    }
  }
}
int main() {
  int n, r1, r2;
  scanf("%d%d%d", &n, &r1, &r2);
  adj.resize(n + 2);
  int child = 1;
  for (int i = 1; i < n; i++) {
    if (child == r1) child++;
    int v;
    scanf("%d", &v);
    adj[v].push_back(child);
    adj[child].push_back(v);
    child++;
  }
  dfs(r2, -1);
  for (int i = 1; i <= n; i++) {
    if (par[i] != -1) printf("%d ", par[i]);
  }
}
