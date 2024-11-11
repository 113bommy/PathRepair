#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int sz[maxn], h[maxn], cnt[maxn];
set<pair<int, int>> S;
vector<int> adj[maxn];
int ans[maxn];
bitset<maxn> big;
void getsz(int v, int p = -1) {
  sz[v] = 1;
  for (auto u : adj[v]) {
    if (u != p) {
      h[u] = h[v] + 1;
      getsz(u, v);
      sz[v] += sz[u];
    }
  }
}
void add(int v, int p, int val) {
  S.erase({cnt[h[v]], h[v]});
  cnt[h[v]] += val;
  S.insert({cnt[h[v]], h[v]});
  for (auto u : adj[v]) {
    if (u != p && !big[u]) {
      add(u, v, val);
    }
  }
}
void dfs(int v, int p, bool keep) {
  int mx = -1, bigchild = -1;
  for (auto u : adj[v]) {
    if (u != p && sz[u] > mx) {
      mx = sz[u];
      bigchild = u;
    }
  }
  for (auto u : adj[v]) {
    if (u != p && u != bigchild) {
      dfs(u, v, 0);
    }
  }
  if (bigchild != -1) {
    big[bigchild] = 1;
    dfs(bigchild, v, 1);
  }
  add(v, p, 1);
  int x = (*S.rbegin()).first;
  ans[v] = (*(S.lower_bound({x, 0}))).second - h[v];
  ans[v] = max(0, ans[v]);
  if (bigchild != -1) {
    big[bigchild] = 0;
  }
  if (!keep) {
    add(v, p, -1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  getsz(0);
  dfs(0, -1, 1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
}
