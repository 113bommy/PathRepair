#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n, m, sz[N], deep[N];
long long sum[N], ans[N];
char A[30];
string second[N];
vector<int> adj[N], root;
vector<pair<int, int> > query[N];
set<string> s[N];
void calcSz(int u, int v) {
  sz[u] = 1;
  deep[u] = deep[v] + 1;
  for (auto &x : adj[u]) {
    if (x != v) {
      calcSz(x, u);
      sz[u] += sz[x];
    }
  }
}
void add(int u, int p) {
  if (p == 1)
    s[deep[u]].insert(second[u]);
  else
    s[deep[u]].erase(second[u]);
}
void dfs2(int u, int v, int p) {
  add(u, p);
  for (auto &x : adj[u])
    if (x != v) dfs2(x, u, p);
}
void dfs(int u, int v, bool keep) {
  int mxSz = 0, bigChild = 0;
  for (auto &x : adj[u])
    if (x != v && mxSz < sz[x]) {
      mxSz = sz[x];
      bigChild = x;
    }
  for (auto &x : adj[u])
    if (x != v && x != bigChild) dfs(x, u, 0);
  if (bigChild != 0) dfs(bigChild, u, 1);
  for (auto &x : adj[u])
    if (x != v && x != bigChild) dfs2(x, u, 1);
  add(u, 1);
  for (auto &X : query[u]) {
    int x = X.first;
    int id = X.second;
    ans[id] = (int)(s[deep[u] + x].size());
  }
  if (!keep) dfs2(u, v, -1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", &A);
    second[i] = A;
    int x;
    scanf("%d", &x);
    if (x) {
      adj[i].push_back(x);
      adj[x].push_back(i);
    } else
      root.push_back(i);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int u, h;
    scanf("%d%d", &u, &h);
    query[u].push_back({h, i});
  }
  for (auto &x : root) {
    deep[x] = -1;
    calcSz(x, x);
    dfs(x, x, 0);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
