#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
const int N = 300 + 10;
bool vis[N];
vector<int> adj[N];
int par[N], dep[N];
int n, m, order[N];
void dfs(int v) {
  vis[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (!vis[u]) {
      par[u] = v;
      dep[u] = dep[v] + 1;
      dfs(u);
    }
  }
}
void find_path(int v, int u) {
  u = par[u];
  vector<int> tmp1, tmp2;
  while (dep[v] > dep[u]) {
    tmp1.push_back(v);
    v = par[v];
  }
  while (dep[u] > dep[v]) {
    tmp2.push_back(u);
    u = par[u];
  }
  if (v == u) {
    for (int i = 0; i < tmp1.size(); i++) vec.push_back(tmp1[i]);
    vec.push_back(u);
    return;
  }
  while (v != u) {
    tmp1.push_back(v);
    tmp2.push_back(u);
    v = par[v], u = par[u];
  }
  for (int i = 0; i < tmp1.size(); i++) vec.push_back(tmp1[i]);
  vec.push_back(v);
  while (tmp2.size()) {
    vec.push_back(tmp2.back());
    tmp2.pop_back();
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  int l = 0;
  for (int i = 1; i < n; i++)
    if (adj[i].size() == 1) l++;
  for (int i = 0; i < l; i++) {
    cin >> order[i];
    order[i]--;
  }
  vector<int> tmp;
  int v = par[order[0]];
  while (v != 0) {
    tmp.push_back(v);
    v = par[v];
  }
  tmp.push_back(0);
  while (tmp.size()) {
    vec.push_back(tmp.back());
    tmp.pop_back();
  }
  for (int i = 0; i < l - 1; i++) {
    find_path(order[i], order[i + 1]);
  }
  v = order[l - 1];
  while (v != 0) {
    tmp.push_back(v);
    v = par[v];
  }
  tmp.push_back(0);
  for (int i = 0; i < tmp.size(); i++) vec.push_back(tmp[i]);
  if (vec.size() == 2 * n - 1) {
    for (int i = 0; i < vec.size(); i++) cout << vec[i] + 1 << " ";
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
