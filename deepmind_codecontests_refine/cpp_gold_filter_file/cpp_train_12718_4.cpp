#include <bits/stdc++.h>
using namespace std;
const int M = 1e6, N = 2 * 1e5 + 20, MOD = 1e9 + 7, OO = 1e16;
long long m, n, k, x, y, vis[N], bla, c = 1, cnt, ans[N], sum, child[N];
pair<int, int> p[N];
vector<int> v;
set<long long> ss;
string s, t;
map<int, int> mp;
vector<vector<int> > G;
int DFS(int root, int par) {
  vis[root] = 1;
  for (int i = 0; i < G[root].size(); i++) {
    int c = G[root][i];
    if (!vis[c] && c != par) child[root] += DFS(c, root);
  }
  return child[root];
}
void DFS2(int root, int par) {
  if (par == -1)
    ans[root] = bla, x = max(x, bla);
  else {
    ans[root] = ans[par] - child[root] + (n - child[root]);
    x = max(x, ans[root]);
  }
  for (int i = 0; i < G[root].size(); i++) {
    int c = G[root][i];
    if (!vis[c] && c != par) DFS2(c, root);
  }
}
int main() {
  int mx = 0;
  cin >> n;
  G.resize(n + 1);
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    child[i] = 1;
  }
  DFS(1, -1);
  for (int i = 1; i <= n; i++) bla += child[i], vis[i] = 0;
  DFS2(1, -1);
  cout << x;
  return 0;
}
