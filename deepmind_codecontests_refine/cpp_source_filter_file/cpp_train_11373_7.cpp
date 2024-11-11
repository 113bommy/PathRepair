#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
bool vis[MAXN], mark[MAXN], mark1[MAXN], mark2[MAXN], en[MAXN];
vector<int> adj[MAXN];
vector<int> rev_adj[MAXN];
vector<int> vec;
int a[MAXN];
bool cycle;
int n, m;
void input();
void dfs(int);
void rev_dfs(int);
void solve();
int main() {
  input();
  solve();
  return 0;
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    rev_adj[v].push_back(u);
  }
}
void dfs(int u) {
  mark[u] = true;
  vec.push_back(u);
  for (auto v : adj[u])
    if (!mark[v])
      dfs(v);
    else if (!vis[v] && en[v])
      cycle = true;
  en[u] = true;
}
void dfs1(int u) {
  mark1[u] = true;
  for (auto v : adj[u])
    if (!mark1[v]) dfs1(v);
}
void rev_dfs(int u) {
  mark2[u] = true;
  for (auto v : rev_adj[u])
    if (!mark2[v]) rev_dfs(v);
}
void solve() {
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!mark[i]) {
      dfs(i);
      for (auto v : vec) vis[v] = true;
      vec.clear();
    }
  if (cycle) {
    cout << -1;
    return;
  }
  for (int i = 0; i < n; i++)
    if ((!mark1[i]) && (!mark2[i])) {
      a[i] = true;
      ans++;
      dfs1(i);
      rev_dfs(i);
    } else if (!mark1[i])
      dfs1(i);
    else if (!mark2[i])
      rev_dfs(i);
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) (a[i]) ? printf("%c", 'A') : printf("%c", 'E');
}
