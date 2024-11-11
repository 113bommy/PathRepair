#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n, m, sz[N], deep[N], ans[N], mod1 = 1e9 + 7, mod2 = 9576890767;
char A[30];
string second;
vector<int> adj[N], root;
vector<pair<int, int> > query[N];
set<pair<int, int> > s[N];
pair<int, int> hsh[N];
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
    s[deep[u]].insert(hsh[u]);
  else
    s[deep[u]].erase(hsh[u]);
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
int getHash(string &s, int mod) {
  int ret = 0;
  for (auto &x : s) ret = (1LL * ret * 26 + (x - 'a')) % mod;
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", &A);
    second = A;
    hsh[i] = {getHash(second, mod1), getHash(second, mod2)};
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
