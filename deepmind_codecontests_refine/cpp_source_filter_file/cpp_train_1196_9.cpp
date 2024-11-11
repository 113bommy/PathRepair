#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, m;
bool del[N];
int children[N];
vector<int> adj[N];
void dfs(int u, int p) {
  if (adj[u].size() <= 2) {
    del[u] = true;
    for (auto v : adj[u])
      if (v != p) dfs(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i < n + 1; i++)
    if (adj[i].size() == 1) dfs(i, i);
  for (int i = 1; i < n + 1; i++)
    for (auto v : adj[i])
      if (del[i]) children[i] = min(children[i] + 1, 2);
  for (int i = 1; i <= n; i++)
    if (!del[i]) {
      int cnt = 0;
      for (auto v : adj[i])
        if (!del[v] && adj[v].size() - children[v] > 1) ++cnt;
      if (cnt > 2) return puts("No");
    }
  puts("Yes");
  return 0;
}
