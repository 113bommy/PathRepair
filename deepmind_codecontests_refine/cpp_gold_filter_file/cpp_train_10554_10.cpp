#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
bool mark[MAXN];
int n;
int sz[MAXN];
long long past, ans;
long long lca[MAXN];
vector<int> adj[MAXN];
void dfs(int v) {
  mark[v] = true;
  sz[v] = 1;
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int tmp = adj[v][i];
    if (!mark[tmp]) {
      dfs(tmp);
      lca[v] += (long long)sz[tmp] * sz[v];
      sz[v] += sz[tmp];
    }
  }
}
void go(int v) {
  ans += lca[v] * (past - (n - sz[v]) * (long long)sz[v]);
  past += lca[v];
  mark[v] = true;
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int tmp = adj[v][i];
    if (!mark[tmp]) go(tmp);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int e1, e2;
    cin >> e1 >> e2;
    e1--;
    e2--;
    adj[e1].push_back(e2);
    adj[e2].push_back(e1);
  }
  dfs(0);
  memset(mark, 0, sizeof mark);
  go(0);
  cout << 2LL * ans << endl;
  return 0;
}
